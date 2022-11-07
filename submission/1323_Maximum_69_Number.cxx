#include <iostream>
int maximum69Number(int num) {
    int div = 10000;
    int mod = num;
    while (div) {
        if ((mod / div) == 6) {
            num += (div * 3);
            break;
        }
        mod = num % div;
        div /= 10;
    }
    return num;
}

int main(int argc, char const* argv[]) {
    int num = 9999;
    std::cout << maximum69Number(num) << std::endl;
    return 0;
}
