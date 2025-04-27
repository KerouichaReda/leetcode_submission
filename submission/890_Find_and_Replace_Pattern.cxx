#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

bool is_same_pattern(std::string& word, std::string& pattern) {
    if (word.size() != pattern.size()) return false;
    std::unordered_map<char, char> word_to_pattern;
    std::unordered_map<char, char> pattern_to_word;
    int index{0}, size = word.size();
    for (; index < size; ++index) {
        if (!word_to_pattern.count(word[index]) && !pattern_to_word.count(pattern[index])) {
            word_to_pattern[word[index]] = pattern[index];
            pattern_to_word[pattern[index]] = word[index];
        } else if (word_to_pattern[word[index]] != pattern[index] || pattern_to_word[pattern[index]] != word[index]) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern) {
    std::vector<std::string> solution;
    for (std::string& word : words) {
        if (is_same_pattern(word, pattern)) {
            solution.push_back(word);
        }
    }
    return solution;
}

int main(int argc, char const* argv[]) { return 0; }
