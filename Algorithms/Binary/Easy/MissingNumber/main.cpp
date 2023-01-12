#include <iostream>

#include "test_runner.h"

int missingNumber(std::vector<int>& nums)
{
  int actual_sum = 0;
  for (const int& elem : nums) actual_sum += elem;

  size_t n = nums.size();
  int expected_sum = n*(n+1)/2; // sum of arithmetic progression

  return expected_sum - actual_sum;
}

void TestCase1()
{
  std::vector<int> nums = {0};
  int result = missingNumber(nums);
  int expected = 1;

  ASSERT_EQUAL(result, expected);
}

void TestCase2()
{
  std::vector<int> nums = {};
  int result = missingNumber(nums);
  int expected = 0;

  ASSERT_EQUAL(result, expected);
}

void TestCase3()
{
  std::vector<int> nums = {3,0,1};
  int result = missingNumber(nums);
  int expected = 2;

  ASSERT_EQUAL(result, expected);
}

void TestCase4()
{
  std::vector<int> nums = {0,1};
  int result = missingNumber(nums);
  int expected = 2;

  ASSERT_EQUAL(result, expected);
}

void TestCase5()
{
  std::vector<int> nums = {9,6,4,2,3,5,7,0,1};
  int result = missingNumber(nums);
  int expected = 8;

  ASSERT_EQUAL(result, expected);
}

int main()
{
  TestRunner tr;
  RUN_TEST(tr, TestCase1);
  RUN_TEST(tr, TestCase2);
  RUN_TEST(tr, TestCase3);
  RUN_TEST(tr, TestCase4);
  RUN_TEST(tr, TestCase5);
  return 0;
}
