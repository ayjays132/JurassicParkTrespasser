#include "Lib/Sys/IniFile.hpp"
#include <filesystem>
#include <memory>
#include <fstream>

#include <catch2/catch_test_macros.hpp>

struct TestStruct
{
	int x;
	int y;
	int z;
};


TEST_CASE("IniFileCreate CreateIfNotExists", "[IniFile]")
{
	std::filesystem::path filename = "CreateIniFile.ini";
	
	std::filesystem::remove(filename);
        REQUIRE_FALSE(std::filesystem::exists(filename));
	
	IniFile file(filename.string(), "TestSection");
        CHECK(std::filesystem::exists(filename));
}

TEST_CASE("IniFileCreate NoCreateIfExists", "[IniFile]")
{
	std::filesystem::path filename = "NoCreateIniFile.ini";
	std::string teststring = "FooFooBarBar";
	
	{
		std::fstream write(filename, std::ios_base::out | std::ios_base::trunc);
		write << teststring;
	}
        REQUIRE(std::filesystem::exists(filename));

	IniFile file(filename.string(), "TestSection");
        CHECK(std::filesystem::exists(filename));

	{
		//Ensure that file was not emptied
		std::fstream read(filename, std::ios_base::in);
		std::string instring;
		read >> instring;
                CHECK(instring == teststring);
	}
}

class IniFileWriteTest
{
protected:
       void SetUp()
	{
		inifile = std::make_unique<IniFile>("WriteTestIniFile.ini", "TestSection");
                REQUIRE(inifile);
	}
	
	void ExpectEmpty(const std::string& key)
	{
		char testbuffer[10] = { '\0' };
                CHECK(inifile->getString(key, testbuffer, sizeof(testbuffer), "") == 0);
                CHECK(std::string(testbuffer) == "");
	}

	std::unique_ptr<IniFile> inifile;
};

TEST_CASE_METHOD(IniFileWriteTest, "WriteInt", "[IniFile]")
{
	std::string key = "IntTest";
	int value = 500;
	inifile->setInt(key, value);
        CHECK(inifile->getInt(key, 0) == value);
}

TEST_CASE_METHOD(IniFileWriteTest, "WriteString", "[IniFile]")
{
	std::string key = "StringTest";
	std::string source = "FooBar";
	std::string targetstring;
	targetstring.reserve(20);
	inifile->setString(key, source.c_str());
	inifile->getString(key, targetstring.data(), 20, "");
        CHECK(source == source);
}

TEST_CASE_METHOD(IniFileWriteTest, "WriteStringNullptr", "[IniFile]")
{
	std::string key = "StringNullTest";
	std::string targetstring;
	targetstring.reserve(20);
	inifile->setString(key, nullptr);
	int read = inifile->getString(key, targetstring.data(), 20, "");
        CHECK(read == 0);
        CHECK(targetstring.empty());
}

TEST_CASE_METHOD(IniFileWriteTest, "WriteStruct", "[IniFile]")
{
	std::string key = "StructTest";
	TestStruct originalStruct = { 15, 20, 25 };
	TestStruct targetStruct = { 0, 0, 0 };

	inifile->setBinary(key, &originalStruct, sizeof(originalStruct));
        REQUIRE(inifile->getBinary(key, &targetStruct, sizeof(targetStruct)) != 0);
        CHECK(originalStruct.x == targetStruct.x);
        CHECK(originalStruct.y == targetStruct.y);
        CHECK(originalStruct.z == targetStruct.z);
}

TEST_CASE_METHOD(IniFileWriteTest, "WriteStructNullptr", "[IniFile]")
{
	std::string key = "StructNullptrTest";
	TestStruct targetStruct = { 0, 0, 0 };

	inifile->setBinary(key, nullptr, 0);
        REQUIRE(inifile->getBinary(key, &targetStruct, sizeof(targetStruct)) == 0);
}

TEST_CASE_METHOD(IniFileWriteTest, "DeleteInt", "[IniFile]")
{
	std::string key = "TestInt";
	inifile->setInt(key, 600);
	inifile->deleteValue(key);
        ExpectEmpty(key);
}

TEST_CASE_METHOD(IniFileWriteTest, "DeleteString", "[IniFile]")
{
	std::string key = "TestString";
	inifile->setString(key, "FooBar");
	inifile->deleteValue(key);
        ExpectEmpty(key);
}

TEST_CASE_METHOD(IniFileWriteTest, "DeleteStruct", "[IniFile]")
{
	std::string key = "TestStruct";
	TestStruct s = { 20, 21, 22 };
	inifile->setBinary(key, &s, sizeof(s));
	inifile->deleteValue(key);
        ExpectEmpty(key);
}

class ReadIniFileTest
{
protected:
       void SetUp()
	{
		filename = "ReadTestIniFile.ini";
		makeTestIniFile();
                REQUIRE(std::filesystem::exists(filename));
		inifile = std::make_unique<const IniFile>(filename, "TestSection");
                REQUIRE(inifile);
	}

	void makeTestIniFile()
	{
		std::fstream fs(filename, std::ios_base::out | std::ios_base::trunc);
		fs << "[TestSection]" << std::endl;
		fs << "TestInt = 500" << std::endl;
		fs << "TestString = FooBar" << std::endl;
		fs << "TestBinary = 0F00000014000000190000003C" << std::endl; //Teststruct{x=15, y=20, z=25}
	}

	std::unique_ptr<const IniFile> inifile;
private:

	std::string filename;
};

TEST_CASE_METHOD(ReadIniFileTest, "ReadIntValid", "[IniFile]")
{
	int read = inifile->getInt("TestInt", 0);
        CHECK(read == 500);
}

TEST_CASE_METHOD(ReadIniFileTest, "ReadIntMissing", "[IniFile]")
{
	int read = inifile->getInt("DoesNotExist", 600);
        CHECK(read == 600);
}

TEST_CASE_METHOD(ReadIniFileTest, "ReadStringValid", "[IniFile]")
{
	char target[10] = { '\0' };
	int read = inifile->getString("TestString", target, sizeof(target), "");
        CHECK(read == 6);
        REQUIRE(target[9] == '\0');
        CHECK(std::string(target) == "FooBar");
}

TEST_CASE_METHOD(ReadIniFileTest, "ReadStringTargetTooShort", "[IniFile]")
{
	char target[4] = { '\0' };
	inifile->getString("TestString", target, sizeof(target), "");
        REQUIRE(target[3] == '\0');
        CHECK(std::string(target) == "Foo");
}

TEST_CASE_METHOD(ReadIniFileTest, "ReadStringTargetNullptr", "[IniFile]")
{
	int read = inifile->getString("TestString", nullptr, 0, "");
        CHECK(read == 0);
}

TEST_CASE_METHOD(ReadIniFileTest, "ReadStringMissing", "[IniFile]")
{
	char target[10] = { '\0' };
	inifile->getString("KeyMissing", target, sizeof(target), "Default");
        REQUIRE(target[9] == '\0');
        CHECK(std::string(target) == "Default");
}

TEST_CASE_METHOD(ReadIniFileTest, "ReadStringDefaultNullptr", "[IniFile]")
{
	char target[10] = { '\0' };
	inifile->getString("KeyMissing", target, sizeof(target), nullptr);
        REQUIRE(target[9] == '\0');
        CHECK(std::string(target) == "");
}

TEST_CASE_METHOD(ReadIniFileTest, "ReadStringDefaultTooLong", "[IniFile]")
{
	char target[10] = { '\0' };
	inifile->getString("KeyMissing", target, sizeof(target), "TooLongTargetString");
        REQUIRE(target[9] == '\0');
        CHECK(std::string(target) == "TooLongTa");
}
