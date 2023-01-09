#include <set>
#include <vector>

#include "test_runner.h"

using namespace std;

bool containsDuplicate(vector<int>& nums)
{
  set<int> s(nums.begin(), nums.end());
  return s.size() != nums.size();
}

void TestCase1()
{
  vector<int> nums = {1,2,3,1};
  bool result = containsDuplicate(nums);
  bool expected = true;

  ASSERT_EQUAL(result, expected);
}

void TestCase2()
{
  vector<int> nums = {1,2,3,4};
  bool result = containsDuplicate(nums);
  bool expected = false;

  ASSERT_EQUAL(result, expected);
}

void TestCase3()
{
  vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
  bool result = containsDuplicate(nums);
  bool expected = true;

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

