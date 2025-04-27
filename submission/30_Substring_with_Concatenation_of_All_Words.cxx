#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
struct TrieNode {
    bool eos;  // end of string
    std::vector<TrieNode*> childs;
    TrieNode() : eos(false), childs(std::vector<TrieNode*>(26, nullptr)) {}
};

void insert(TrieNode* root, std::string word) {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'a';
        if (curr->childs[index] == nullptr) {
            curr->childs[index] = new TrieNode();
        }
        curr = curr->childs[index];
    }
    curr->eos = true;
}

void fill(TrieNode* root, std::vector<std::string>& words) {
    for (std::string str : words) {
        insert(root, str);
    }
}

std::vector<int> findSubstring(std::string str, std::vector<std::string>& words) {
    std::vector<int> solution;
    TrieNode* root = new TrieNode();
    fill(root, words);
    int words_size = words.size() * words[0].size();
    int nb = words.size();
    int str_size = str.size();
    std::unordered_multiset<std::string> s(words.begin(), words.end());
    std::vector<std::string> store;
    std::string temp;
    uint64_t op{0};
    for (int i = 0; i < str_size - words_size + 1; i++) {
        int total = 0;
        TrieNode* curr = root;
        temp.clear();
        for (int j = i, start = i; j < i + words_size; j++) {
            op++;
            int index = str[j] - 'a';
            temp.push_back(str[j]);
            if (curr->childs[index] == nullptr) break;
            curr = curr->childs[index];
            if (curr->eos) {
                if (s.count(temp)) {
                    total++;
                    curr = root;
                    s.erase(s.find(temp));
                    store.push_back(temp);
                    temp.clear();
                }
            }
        }
        s.insert(store.begin(), store.end());
        store.clear();
        if (total == nb) {
            solution.push_back(i);
        }
    }
    std::cout << op << std::endl;
    return solution;
}

void disp(std::vector<int>& vec) {
    std::cout << "[";
    for (int e : vec) {
        std::cout << e << ",";
    }
    std::cout << "]" << std::endl;
}

int main(int argc, char const* argv[]) {
    std::vector<std::string> words = {
        "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba",
        "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba",
        "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba",
        "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba",
        "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba",
        "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba",
        "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba",
        "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba",
        "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab"};
    std::string str =
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababababababab"
        "abababababababababababababababababababababababababababababababab";
    std::vector<int> result = findSubstring(str, words);
    disp(result);

    return 0;
}
