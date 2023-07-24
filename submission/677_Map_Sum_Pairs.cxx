#include <vector>
#include <string>

class MapSum {
   public:
    MapSum() {}
    struct TrieNode {        
        int value = 0;
        TrieNode* child[26] = {nullptr};
    };

    void insert(std::string key, int val) {
        TrieNode* curr = root_;
        for (char& c : key) {
            if (curr->child[c - 'a'] == nullptr) {
                curr->child[c - 'a'] = new TrieNode();
            }
            curr = curr->child[c - 'a'];
        }        
        curr->value = val;
    }

    int sum(std::string prefix) {
        TrieNode* curr = root_;
        for (char& c : prefix) {
            curr = curr->child[c - 'a'];
            if (curr == nullptr) break;
        }
        return sum(curr);
    }

    int sum(TrieNode* node) {
        if (node == nullptr) return 0;
        int total = node->value;
        for (TrieNode* n : node->child) {
            total += sum(n);
        }
        return total;
    }

   private:
    TrieNode* root_ = new TrieNode();
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */