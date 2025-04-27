#include <iostream>
#include <string>
#include <unordered_set>
bool checkIfPangram(std::string sentence) {
    return (std::unordered_set<char>(sentence.begin(), sentence.end())).size() == 26;
}
int main(int argc, char const* argv[]) {
    std::string sentence = {"thequickbrownfoxjumpsoverthelazydog"};
    std::cout << checkIfPangram(sentence) << std::endl;
    return 0;
}
