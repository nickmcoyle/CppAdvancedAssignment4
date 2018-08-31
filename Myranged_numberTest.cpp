#include "TestHarness.h"

#include "ranged_number.h"

TEST(edgeCaseOverWrap, ranged_number)
{
	const uint8_t anInt1{ 249 };

	const uint8_t anInt2{ 10 };
	
	ranged_number<uint8_t, 0, 255> grade = anInt1 + anInt2;

	CHECK_EQUAL(255, grade);
}

TEST(edgeCaseNegative, ranged_number)
{
	const int anInt1{ 9 };

	const int anInt2{ -10 };

	ranged_number<int, 0, 255> grade = anInt1 + anInt2;

	CHECK_EQUAL(0, grade);
}

TEST(edgeCaseDecimal, ranged_number)
{
	const long anInt1{ 9.9 };

	const long anInt2{ 10.1 };

	ranged_number<int, 0, 255> grade = anInt1 + anInt2;

	CHECK_EQUAL(20, grade);
}


/*
TEST(cTor, ranged_number)
{
    ranged_number<short, 1, 12> grade{};	

    grade = 5;
    CHECK_EQUAL(5, grade);
}

TEST(preIncrement, ranged_number)
{
    ranged_number<short, 1, 12> grade{};

    grade = 5;
    CHECK_EQUAL(5, grade);
    
    ++grade;
    CHECK_EQUAL(6, grade);
}

TEST(preIncrementConstraint, ranged_number)
{
    ranged_number<short, 1, 12> grade{};

    grade = 12;
    CHECK_EQUAL(12, grade);
    
    ++grade;
    CHECK_EQUAL(12, grade);
}

TEST(postIncrementConstraint, ranged_number)
{
    ranged_number<short, 1, 12> grade{};

    grade = 12;
    CHECK_EQUAL(12, grade);
    
    grade++;
    CHECK_EQUAL(12, grade);
}

TEST(preDecrementConstraint, ranged_number)
{
    ranged_number<short, 1, 12> grade{};

    grade = 1;
    CHECK_EQUAL(1, grade);
    
    --grade;
    CHECK_EQUAL(1, grade);
}

TEST(postDecrementConstraint, ranged_number)
{
    ranged_number<short, 1, 12> grade{};

    grade = 1;
    CHECK_EQUAL(1, grade);
    
    grade--;
    CHECK_EQUAL(1, grade);
}

using Grade = ranged_number<int, 1, 12>;
TEST(operatorPlus, ranged_number)
{
    Grade grade{5};

    grade = grade + Grade{5};
    CHECK_EQUAL(10, grade);

    grade = grade + Grade{5};
    CHECK_EQUAL(12, grade);
}

TEST(operatorPlusEquals, ranged_number)
{
    Grade grade {5};

    grade += 5;
    CHECK_EQUAL(10, grade);

    grade += 5;
    CHECK_EQUAL(12, grade);
}
*/