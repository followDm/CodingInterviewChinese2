#include <iostream>  
#include <string>  
using namespace std;  

/**
 * ���кκ��λָ��ҵ��ʼ��������ҿ���һ����ҳ��
 * https://blog.csdn.net/jinking01/article/details/107725080
 *
 * */
int func1(int x) {
    printf("x = %d \n" ,x);
    x = 10;
    printf("x = %d \n" ,x);
//    return x;
}

void func2(int* x) {
    printf("x = %d \n" ,*x);
    *x = 10;
    printf("x = %d \n" ,*x);
//    return x;
}

int func3(int &x) {
    printf("x = %d \n" ,x);
    x = 10;
    printf("x = %d \n" ,x);
//    return x;
}

int main() {  
    int a = 3;
    // ��һ�ִ���ֵ
    func1(a);
    printf("a = %d \n" ,a);
    // ���ǽ�ס����ֵ����Ȼû�Ķ�
    a = func1(a);
    printf("��ô���£� a = %d \n" ,a);

    func2(&a);
    // ����x��&a��*x��a��ȫһ��

    printf("a = %d \n" ,a);

    a = 3;
    // ���á���˼�ǲ��ǣ���������&a�ģ�func2(&a);���ﴫʵ��������func3(int &x)�����β�������
    func3(a);
    printf("a = %d \n" ,a);
}  
