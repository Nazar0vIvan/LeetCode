#include <vector>
#include <map>

#include "test_runner.h"

using namespace std;

vector<int> twoSums(vector<int>& nums, int target)
{
  vector<int> result(2);
  map<int,int> diffToIndex;
  for(size_t i=0;i<nums.size();++i){
    int diff = target - nums[i];
    if(diffToIndex.count(nums[i])){
      result[0] = diffToIndex[nums[i]];
      result[1] = i;
    }
    else{
      diffToIndex[diff] = i;
    }
  }
  return result;
}

void TestCase1()
{
  vector<int> nums = {2,7,11,15}; int target = 9;
  vector<int> result = twoSums(nums,target);
  vector<int> expected = {0,1};

  ASSERT_EQUAL(result, expected);
}

void TestCase2()
{
  vector<int> nums = {3,2,4}; int target = 6;
  vector<int> result = twoSums(nums,target);
  vector<int> expected = {1,2};

  ASSERT_EQUAL(result, expected);
}

void TestCase3()
{
  vector<int> nums = {3,3}; int target = 6;
  vector<int> result = twoSums(nums,target);
  vector<int> expected = {0,1};

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

