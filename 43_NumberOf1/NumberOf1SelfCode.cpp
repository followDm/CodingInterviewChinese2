/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������43����1��n������1���ֵĴ���
// ��Ŀ������һ������n�����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ���������
// ����12����1��12��Щ�����а���1 ��������1��10��11��12��1һ��������5�Ρ�

#include <cstdio>
#include <cstring>
#include <cstdlib>

int NumberOf1Between1AndN_Solution3(unsigned int n) {
    int number = 0;

    return number;
}
/*
21345	��	ǧ	��	ʮ	��
�ֽ�	2	1	3	4	5
        0	0	0	0	0
        1	1	1	1	1
        2		2	2	2
                3	3	3
                    4	4
                        5
	1*10000+2*4000	1*1000+300*2	1*300+1*100+20*3	1*40+1*10+1*4	1*6+1*1
18821	18000	300	460	54	7

 */

// ====================���Դ���====================
void Test(const char* testName, int n, int expected)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);
    
    if(NumberOf1Between1AndN_Solution3(n) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n"); 

    printf("\n");
}

void Test()
{
    Test("Test1", 1, 1);
    Test("Test2", 5, 1);
    Test("Test3", 10, 2);
    Test("Test4", 55, 16);
    Test("Test5", 99, 20);
    Test("Test6", 10000, 4001);
    Test("Test7", 21345, 18821);
    Test("Test8", 0, 0);
}

int main(int argc, char* argv[])
{
    Test();

    return 0;
}

