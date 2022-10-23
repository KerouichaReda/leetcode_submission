#include <iostream>
#include <vector>

bool validUtf8(std::vector<int>& data) {
    const int MASK_10 = 0x80;     // 128
    const int MASK_110 = 0xC0;    // 192
    const int MASK_1110 = 0xE0;   // 224
    const int MASK_11110 = 0xF0;  // 240
    const int MASK_11111 = 0xF8;  // 248
    for (int i = 0, size = data.size(); i < size; ++i) {
        if ((data[i] & MASK_10) == 0) continue;
        if ((data[i] >= MASK_10 && data[i] < MASK_110) || data[i] >= MASK_11111)
            return false;
        else if ((data[i] & MASK_11110) == MASK_11110) {
            for (int j = 0; i < size && j < 3; ++j) {
                if (++i == size || (data[i] < MASK_10 || data[i] > MASK_110))
                    return false;
            }
        } else if ((data[i] & MASK_1110) == MASK_1110) {
            for (int j = 0; i < size && j < 2; ++j) {
                if (++i == size || (data[i] < MASK_10 || data[i] > MASK_110))
                    return false;
            }
        } else if ((data[i] & MASK_110) == MASK_110) {
            for (int j = 0; i < size && j < 1; ++j) {
                if (++i == size || (data[i] < MASK_10 || data[i] > MASK_110))
                    return false;
            }
        }
    }
    return true;
}

int main(int argc, char const* argv[]) {
    std::vector<int> data = {228, 133, 160, 226, 137, 188, 240, 136,
                             178, 191, 216, 169, 231, 172, 169, 6};
    std::cout << validUtf8(data) << std::endl;
    return 0;
}
