
#include <string>
#include <iostream>
int countSegments(std::string& s) {
    s.push_back(' ');
    char pre = ' ';
    int solution{0};
    for (char& c : s) {
        if (c == ' ' && pre != ' ') solution++;
        pre = c;
    }
    return solution;
}