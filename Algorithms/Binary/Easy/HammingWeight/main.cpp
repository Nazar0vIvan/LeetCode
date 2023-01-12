#include <iostream>

#include "test_runner.h"

int hammingWeight(uint32_t n)
{
  int count = n & 1;
  while (n >>= 1) count += (n & 1);
  return count;
}

void TestCase1()
{
  uint32_t n = 11; // 0000'0000'0000'0000'0000'0000'0000'1011
  int result = hammingWeight(n);
  int expected = 3;

  ASSERT_EQUAL(result, expected);
}

void TestCase2()
{
  uint32_t n = 128; // 0000'0000'0000'0000'0000'0000'1000'0000
  int result = hammingWeight(n);
  int expected = 1;

  ASSERT_EQUAL(result, expected);
}

void TestCase3()
{
  uint32_t n = 4294967293; // 1111'1111'1111'1111'1111'1111'1111'1101
  int result = hammingWeight(n);
  int expected = 31;

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
