
#include <iostream>
#include <string>
const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dayOfYear(std::string& date) {
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
    for (int i = 0; i < month - 1; ++i) {
        day += months[i];
    }
    day += year != 1900 &&  (month > 2 && (year - 1900) % 4 == 0 );
    return day;
}

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
