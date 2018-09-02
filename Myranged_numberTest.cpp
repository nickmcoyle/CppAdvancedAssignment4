#include "TestHarness.h"
#include "ranged_number.h"
#include <cstdint> 

TEST(edgeCaseOverWrap, ranged_number)
{
	uint8_t anInt{ 249 };
	uint8_t anInt2{ 10 };

	uint8_t aResult = std::clamp<uint8_t>(anInt + anInt2, 0, 250);
	
	/*ranged_number<uint8_t, 0, 255> grade{};	
	grade = anInt1 + anInt2;*/

	CHECK_EQUAL(3, aResult);
}

TEST(edgeCaseNegative, ranged_number)
{
	const int anInt1{ 9 };
	const int anInt2{ -10 };

	ranged_number<int, 0, 255> grade{};

	grade = anInt1 + anInt2;

	CHECK_EQUAL(0, grade);
}


//TEST(edgeCaseDecimal, ranged_number)
//{
//	const float anInt1 = 9.9f;
//	const float anInt2 = 10.1f;
//
//	ranged_number<float, 0, 255> grade{}; //should throw static assert compile error
//
//	grade = anInt1 + anInt2;
//	
//	CHECK_EQUAL(20, grade);
//}