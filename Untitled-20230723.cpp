#include <iostream>  
#include <string>  
using namespace std;  

/**
 * 大佬何海涛恢复我的邮件，建议我看的一个网页。
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
    // 第一种传递值
    func1(a);
    printf("a = %d \n" ,a);
    // 除非接住返回值，不然没改动
    a = func1(a);
    printf("怎么回事？ a = %d \n" ,a);

    func2(&a);
    // 这里x和&a，*x和a完全一样

    printf("a = %d \n" ,a);

    a = 3;
    // 引用。意思是不是，反正都是&a的，func2(&a);这里传实参这样。func3(int &x)这里形参这样。
    func3(a);
    printf("a = %d \n" ,a);
}  
