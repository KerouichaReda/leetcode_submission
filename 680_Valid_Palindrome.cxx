#include <iostream>
#include <string>
bool validPalindrome(std::string s, bool left2right = true){
    for(int i = 0, j = s.size() - 1 , diff = 0 ; i < j ; i++, j--){
        if(s[i] != s[j]){
            left2right ? i-- : j++;
            diff++;
        }
        if(diff > 1 ){
            return left2right ? validPalindrome(s ,false) : false;
        }
    }
    return true;
}

int main(){
    std::string s = "deeeeeeeeeeee";
    std::cout << validPalindrome(s) << std::endl;
    return EXIT_SUCCESS;
}
