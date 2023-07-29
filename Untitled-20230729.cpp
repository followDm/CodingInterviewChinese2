#include <iostream>
using namespace std;

template <class T, int N>;
void TestSelfCode(const char* testName, T(&data)[N], int length, int k, int expected) {
    printf("Hello.\n");
}

// 查找的数字出现在数组的中间
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
//    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
    TestSelfCode("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}
