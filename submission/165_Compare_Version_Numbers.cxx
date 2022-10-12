#include <iostream>
#include <sstream>
#include <queue>
#include <string>

int compareVersion(std::string version1, std::string version2){
    std::queue<int> v1,v2; 
    std::stringstream s1(version1), s2(version2);
    std::string inter;
    while(getline(s1,inter,'.')){
        v1.push(stoi(inter));
    }
    while(getline(s2,inter,'.')){
        v2.push(stoi(inter));
    }
    while (!v1.empty() || !v2.empty()){
        int temp1 = v1.empty() ? 0 : v1.front();
        if(!v1.empty()) v1.pop();
        int temp2 = v2.empty() ? 0 : v2.front();
        if(!v2.empty()) v2.pop();
        if (temp1 > temp2){
            return  1;
        }else if (temp1 < temp2){
            return -1;
        }        
    }
    return 0;
}

int main(int argc, char const *argv[]){
    std::string version1 = "1.0.0.1";
    std::string version2 = "1.0.1";

    std::cout<<compareVersion(version1,version2) <<std::endl;
    /* code */
    return 0;
}
