/*********************************** 
 * @author: YuZhangWang
 * @date: 2021/9/4 19:42
 * @link: https://www.yuzhang.wang/
***********************************/
#include <iostream>

using namespace std;

void f1(unsigned num) {
    int a[100], i = 0;
    char ch;
    while (num) {
        a[i++] = num % 16;
        num /= 16;
    }
    for (i--; i >= 0; i--) {
        if (a[i] > 9)
            ch = 'A' + a[i] - 10;
        else
            ch = a[i] + '0';
        cout << ch;
    }
}

int main() {
    f1(15);
    return 0;
}