
#include <iostream>
#include <string>
bool isLongPressedName(std::string name, std::string typed) {
    int j = 0;
    int i = 0;
    for (int size = name.size(); i < size && j < typed.size(); i++) {
        char c = name[i];
        int count = 0;
        int t = 0;
        for (; c == name[i]; count++, i++);
        i--;
        for (; j < typed.size() && c == typed[j]; j++, t++);
        if (t < count) return false;
    }
    return i == name.size() && j == typed.size();
}

int main(int argc, char const* argv[]) {
    std::string name = "reda";
    std::string typed = "reeeeeeeeeedaaaaaaa";
    std::cout << isLongPressedName(name, typed) << std::endl;
    return 0;
}
