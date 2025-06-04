#include "common.hpp"
#include "Lib/Sys/FastHeap.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("CFastHeap AllocateSingle", "[CFastHeap]")
{
	constexpr size_t elements = 1000;
	CFastHeap fh(sizeof(int) * elements);

	for (size_t i = 0; i < elements; i++) {
                auto* newint = new(fh) int;
                REQUIRE(newint != nullptr);
		
		*newint = 500; //Ensure we can write data to allocated memory
	}	
}

TEST_CASE("CFastHeap AllocateArray", "[CFastHeap]")
{
	constexpr size_t arraySize = 10;
	constexpr size_t arrayCount = 100;
	CFastHeap fh(sizeof(int) * arraySize * arrayCount);
	
	for (size_t i = 0; i < arrayCount; i++)
	{
                auto* newintarray = new(fh) int[arraySize];
                REQUIRE(newintarray != nullptr);
		
		for (size_t j = 0; j < arraySize; j++)
			newintarray[j] = 500; //Ensure we can write data to allocated memory
	}
}
