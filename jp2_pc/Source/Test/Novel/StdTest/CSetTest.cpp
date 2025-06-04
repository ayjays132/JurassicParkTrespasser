#include "Lib/Std/UTypes.hpp"
#include "Lib/Std/UDefs.hpp"
#include "Lib/Std/Set.hpp"

#include <catch2/catch_test_macros.hpp>

#include <type_traits>

enum TestEnum
{
	Start,
	Foo,
	Bar,
	End
};

//Check general prerequisites to make copy-assignment operator implementation work as expected
TEST_CASE("CSetHelper SafetyChecks", "[CSet]")
{
	using CSet_t = CSet<TestEnum>;
	using CSetHC_t = CSet_t::CSetHelperConst;

	//Same size, CSetHelperConst has no new members
	static_assert(sizeof(CSet_t::CSetHelper) == sizeof(CSetHC_t));

	//We can unofficially skip destruction in the copy-assignment operator (and in general)
	static_assert(std::is_trivially_destructible_v<CSetHC_t>);

	//No virtual methods
	static_assert(!std::is_polymorphic_v<CSetHC_t>);
}

TEST_CASE("CSetHelper Copy_Assignment_Same_Bitfield", "[CSet]")
{
	CSet<TestEnum> bitfield = Set(TestEnum::Bar);

	bitfield[TestEnum::Foo] = bitfield[TestEnum::Bar];
	
        CHECK(bitfield[TestEnum::Foo]);
}

TEST_CASE("CSetHelper Copy_Assignment_Different_Bitfield", "[CSet]")
{
	CSet<TestEnum> first = Set(TestEnum::Start);
	CSet<TestEnum> second = Set(TestEnum::Bar) + TestEnum::End;

	first[TestEnum::Foo] = second[TestEnum::Bar];
	
        CHECK(first[TestEnum::Start]);
        CHECK(first[TestEnum::Foo]);
        CHECK_FALSE(first[TestEnum::Bar]);
        CHECK_FALSE(first[TestEnum::End]);
}
