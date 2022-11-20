#include <iostream>

int primes[3] = {2, 3, 5};
bool isUgly(int n) {    
    if (n == 1 || n == 0) return n == 1;
    for (int& e : primes) {
        if (n % e == 0) {
            return isUgly(n / e);
        }
    }
    return false;
}
int main(int argc, char const* argv[]) {
    int n = 234234;
    std::cout << isUgly(n) << std::endl;
    return 0;
}
