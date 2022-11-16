#include <vector>

void duplicateZeros(std::vector<int>& arr) {
    std::vector<int> temp(arr.begin(), arr.end());
    int size = arr.size();
    int index{0};
    for (int& e : temp) {
        if (e == 0) {
            arr[index++] = 0;
            if (index >= size) break;
            arr[index++] = 0;
        } else {
            arr[index++] = e;
        }
        if (index >= size) break;
    }
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
