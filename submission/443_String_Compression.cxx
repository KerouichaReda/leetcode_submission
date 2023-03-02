#include <vector>
#include <string>

int compress(std::vector<char>& chars) {
    char pre = chars[0];
    int counter = 1;
    chars.push_back('\n');
    int index = 0;
    for (int i = 1, size = chars.size(); i < size; ++i) {
        if (chars[i] != pre) {
            chars[index++] = pre;
            if (counter > 1) {
                std::string temp = std::to_string(counter);
                for (char& c : temp) {
                    chars[index++] = c;
                }
            }
            pre = chars[i];
            counter = 1;
        } else {
            counter++;
        }
    }
    chars.pop_back();
    return index;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
