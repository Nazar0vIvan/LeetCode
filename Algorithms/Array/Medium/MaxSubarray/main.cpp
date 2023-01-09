#include <vector>
#include <algorithm>

#include "test_runner.h"

int maxSubArraySum(std::vector<int>& nums)
{
  int max = nums[0];
  for (size_t i = 1; i < nums.size(); ++i){
    nums[i] = std::max(nums[i], nums[i]+nums[i-1]);
    max = std::max(max,nums[i]);
  }
  return max;
}

void TestCase1()
{
  vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  int result = maxSubArraySum(nums);
  int expected = 6;

  ASSERT_EQUAL(result, expected);
}

void TestCase2()
{
  vector<int> nums = {1};
  int result = maxSubArraySum(nums);
  int expected = 1;

  ASSERT_EQUAL(result, expected);
}

void TestCase3()
{
  vector<int> nums = {5,4,-1,7,8};
  int result = maxSubArraySum(nums);
  int expected = 23;

  ASSERT_EQUAL(result, expected);
}

int main()
{
  TestRunner tr;
  RUN_TEST(tr, TestCase1);
  RUN_TEST(tr, TestCase2);
  RUN_TEST(tr, TestCase3);
  return 0;
}

