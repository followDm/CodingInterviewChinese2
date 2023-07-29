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

// ������19��������ʽƥ��
// ��Ŀ����ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'
// ��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ����ڱ���
// �У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"
// ��"ab*ac*a"ƥ�䣬����"aa.a"��"ab*a"����ƥ�䡣

#include <cstdio>
#include<cstring>
#include<stack>

bool matchCore(const char* str, const char* pattern);
bool matchSelfCode(const char* str, const char* pattern) {
    if(str == nullptr || pattern == nullptr) {
        return false;
    }
    int strLength = strlen(str);
    int patternLength = strlen(pattern);
    std::stack<char> patternBasePart;
    std::stack<char> patternExtendPart;
    for (int i = 0; i < patternLength-1; i++){
        if (pattern[i+1] == '*') {
            patternExtendPart.push('*');
        } else {
            patternExtendPart.push('+');
        }
        patternBasePart.push(pattern[i]);
    }
    char charOfStr = 'a', charOfPatternBase = 'b', charPatternExtendPart = '+';
    int i =0,j=0;
    for (i = strLength-1, j= patternBasePart.size(); i >=0 && !patternBasePart.empty();) {
        charOfStr = str[i];
        // �Ȳ�pop����
        charOfPatternBase = patternBasePart.top();
        charPatternExtendPart = patternExtendPart.top();
        // ��������������������Ƿ���Ⱥ��Ƿ�*��������˹�4�֡����Ȼ���һ��������.��������
        if (charPatternExtendPart == '+' && charOfPatternBase == charOfStr){
            i--;
            patternBasePart.pop();
            patternExtendPart.pop();
        } else if (charPatternExtendPart == '*' && charOfPatternBase == charOfStr){
            i--;
        } else if (charPatternExtendPart == '+' && charOfPatternBase != charOfStr) {
            if (charOfPatternBase == '.') {
                i--;
                patternBasePart.pop();
                patternExtendPart.pop();
            } else {
                return false;
            }
        } else if (charPatternExtendPart == '*' && charOfPatternBase != charOfStr) {
            if (charOfPatternBase == '.') {
                i--;
            } else {
                patternBasePart.pop();
                patternExtendPart.pop();
            }
        }
    }
    // �ж��ǲ�������������
    if (i <0 && patternBasePart.empty()){
         return true;
    } else {
        return false;
    }
}

bool match(const char* str, const char* pattern)
{
    if(str == nullptr || pattern == nullptr)
        return false;

    return matchCore(str, pattern);
}

bool matchCore(const char* str, const char* pattern)
{
    if(*str == '\0' && *pattern == '\0')
        return true;

    if(*str != '\0' && *pattern == '\0')
        return false;

    if(*(pattern + 1) == '*')
    {
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            // ��������״̬������һ��״̬
            return matchCore(str + 1, pattern + 2)
            // ������������״̬���ĵ�ǰ״̬ 
            || matchCore(str + 1, pattern)
            // �Թ�һ��'*' 
            || matchCore(str, pattern + 2);
        else
            // �Թ�һ��'*'
            return matchCore(str, pattern + 2);
    }

    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str + 1, pattern + 1);

    return false;
}

// ====================���Դ���====================
void Test(const char* testName, const char* string, const char* pattern, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(matchSelfCode(string, pattern) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    Test("Test01", "", "", true);
    Test("Test02", "", ".*", true);
    Test("Test03", "", ".", false);
    Test("Test04", "", "c*", true);
    Test("Test05", "a", ".*", true);
    Test("Test06", "a", "a.", false);
    // Test("Test07", "a", "", false);
    // Test("Test08", "a", ".", true);
    // Test("Test09", "a", "ab*", true);
    // Test("Test10", "a", "ab*a", false);
    // Test("Test11", "aa", "aa", true);
    // Test("Test12", "aa", "a*", true);
    // Test("Test13", "aa", ".*", true);
    // Test("Test14", "aa", ".", false);
    // Test("Test15", "ab", ".*", true);
    // Test("Test16", "ab", ".*", true);
    // Test("Test17", "aaa", "aa*", true);
    // Test("Test18", "aaa", "aa.a", false);
    // Test("Test19", "aaa", "a.a", true);
    // Test("Test20", "aaa", ".a", false);
    // Test("Test21", "aaa", "a*a", true);
    // Test("Test22", "aaa", "ab*a", false);
    // Test("Test23", "aaa", "ab*ac*a", true);
    // Test("Test24", "aaa", "ab*a*c*a", true);
    // Test("Test25", "aaa", ".*", true);
    // Test("Test26", "aab", "c*a*b", true);
    // Test("Test27", "aaca", "ab*a*c*a", true);
    // Test("Test28", "aaba", "ab*a*c*a", false);
    // Test("Test29", "bbbba", ".*a*a", true);
    // Test("Test30", "bcbbabab", ".*a*a", false);
    // Test("Test69", "aabb", "a.b*", true);
    return 0;
}

