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

// ������66�������˻�����
// ��Ŀ������һ������A[0, 1, ��, n-1]���빹��һ������B[0, 1, ��, n-1]����
// ��B�е�Ԫ��B[i] =A[0]��A[1]���� ��A[i-1]��A[i+1]������A[n-1]������ʹ�ó�����

#include <cstdio>
#include <vector>
#include<algorithm>

using namespace std;

void BuildProductionArray()
{
    double input[] = { 1, 2, 3, 4, 5 };
    double output[] = { 1, 0, 0, 0, 0 };
    double expected[] = { 120, 60, 40, 30, 24 };
    int length1 = 5;
    int length2 = 5;

    if(length1 == length2 && length2 > 1)
    {
        output[0] = 1;
        for(int i = 1; i < length1; ++i)
        {
            output[i] = output[i - 1] * input[i - 1];
        }
        /// �Լ������output[i] *= temp��������
        double temp = 1;
        for(int i = length1 - 2; i >= 0; --i)
        {
            temp *= input[i + 1];
            output[i] *= temp;
        }
    }
}

//================= Test Code =================
static bool EqualArrays(const vector<double>& input, const vector<double>& output)
{
    int length1 = input.size();
    int length2 = output.size();

    if(length1 != length2)
        return false;

    for(int i = 0; i < length1; ++i)
    {
        if(abs(input[i] - output[i]) > 0.0000001)
            return false;
    }

    return true;
}

static void test(char* testName)
{
    printf("%s Begins: ", testName);

}

static void test1()
{
    // ����������û��0
    double input[] = { 1, 2, 3, 4, 5 };
    double output[] = { 0, 0, 0, 0, 0 };
    double expected[] = { 120, 60, 40, 30, 24 };
}

static void test2()
{
    // ������������һ��0
    double input[] = { 1, 2, 0, 4, 5 };
    double output[] = { 0, 0, 0, 0, 0 };
    double expected[] = { 0, 0, 40, 0, 0 };

}

static void test3()
{
    // ����������������0
    double input[] = { 1, 2, 0, 4, 0 };
    double output[] = { 0, 0, 0, 0, 0 };
    double expected[] = { 0, 0, 0, 0, 0 };

}

static void test4()
{
    // ��������������������
    double input[] = { 1, -2, 3, -4, 5 };
    double output[] = { 0, 0, 0, 0, 0 };
    double expected[] = { 120, -60, 40, -30, 24 };

}

static void test5()
{
    // ����������ֻ����������
    double input[] = { 1, -2 };
    double output[] = { 0, 0 };
    double expected[] = { -2, 1 };

}

int main(int argc, char* argv[])
{
    BuildProductionArray();
    return 0;
}
