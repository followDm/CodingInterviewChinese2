/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题53（二）：0到n-1中缺失的数字
// 题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
// 都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
// 中，请找出这个数字。

#include <cstdio>

int GetMissingNumber(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        return -1;

    int left = 0;
    int right = length - 1;
    while(left <= right)
    {
        int middle = (right + left) >> 1;
        if(numbers[middle] != middle) {
            /// 改一下试试if(middle == 0)，照样通过了。但是不太对。
            // 如果中间元素的值和下标相等，那么下一轮查找只需要查找右半边;
            // 如果中间元素的值和下标不相等，并且它前面一个元素和它的下标相等，这意味着这个中间的数字正好是第一个值和下标不相等的元素，它的下标就是在数组中不存在的数字;
            // 如果中间元素的值和下标不相等，并且它前面一个元素和它的下标不相等，这意味着下一轮查找我们只需要在左半边查找即可
            if(middle == 0 || numbers[middle - 1] == middle - 1) {
                return middle;
            }
//            if(middle == 0) {
//                return middle;
//            }
            right = middle - 1;
        } else {
            /// 说明右边少了
            left = middle + 1;
        }

    }

    if(left == length)
        return length;

    // 无效的输入，比如数组不是按要求排序的，
    // 或者有数字不在0到n-1范围之内
    return -1;
}

// ====================测试代码====================
void Test(const char* testName, int numbers[], int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int result = GetMissingNumber(numbers, length);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 缺失的是第一个数字0
void Test1()
{
    int numbers[] = { 1, 2, 3, 4, 5 };
    int expected = 0;
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是最后一个数字
void Test2()
{
    int numbers[] = { 0, 1, 2, 3, 4 };
    int expected = 5;
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是中间某个数字0
void Test3()
{
    int numbers[] = { 0, 1, 2, 4, 5 };
    int expected = 3;
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是第一个数字0
void Test4()
{
    int numbers[] = { 1 };
    int expected = 0;
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是最后一个数字1
void Test5()
{
    int numbers[] = { 0 };
    int expected = 1;
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 空数组
void Test6()
{
    int expected = -1;
    Test("Test6", nullptr, 0, expected);
}
/// 自己加的
void Test0()
{
    int numbers[] = { 0,1,2,4,5,6,7,8 };
    int expected = 3;
    Test("Test0", numbers, sizeof(numbers) / sizeof(int), expected);
}
int main(int argc, char* argv[])
{
//    Test1();
//    Test2();
//    Test3();
//    Test4();
//    Test5();
//    Test6();

    Test0();
    return 0;
}
