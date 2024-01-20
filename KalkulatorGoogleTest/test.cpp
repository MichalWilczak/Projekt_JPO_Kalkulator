#include "pch.h"

#include "C:\Users\michl\Documents\JPO\KalkulatorUnitTest\KalkulatorUnitTest.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}


TEST(Kalkulator_Unit_Test, KalkulatorTest)
{
	bool result = Kalkulator_Unit_Test();

	EXPECT_EQ(result, true) << "All numbers from 0 to 1023 should pass the conversion successfully";

	ASSERT_EQ(result, true) << "All numbers from 0 to 1023 should pass the conversion successfully";
}