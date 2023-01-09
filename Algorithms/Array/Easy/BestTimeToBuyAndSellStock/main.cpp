#include <vector>

#include "test_runner.h"

using namespace std;

int maxProfit(vector<int>& prices)
{
  int minprice = prices[0];
  int maxprofit = 0;
  for (size_t i = 0; i < prices.size(); i++)
  {
    if (prices[i] < minprice)
      minprice = prices[i];
    else if (prices[i] - minprice > maxprofit)
      maxprofit = prices[i] - minprice;
  }
  return maxprofit;
}


void TestCase1()
{
  vector<int> prices = {7,1,5,3,6,4};
  int result = maxProfit(prices);
  int expected = 5;

  ASSERT_EQUAL(result, expected);
}

void TestCase2()
{
  vector<int> prices = {7,6,4,3,1};
  int result = maxProfit(prices);
  int expected = 0;

  ASSERT_EQUAL(result, expected);
}

int main()
{
  TestRunner tr;
  RUN_TEST(tr, TestCase1);
  RUN_TEST(tr, TestCase2);
  return 0;
}

