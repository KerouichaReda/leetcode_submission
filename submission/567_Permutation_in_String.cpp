/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
    bool checkInclusion(std::string s1, std::string s2) {
        auto count = [](std::string& str){
            std::vector<int> vec(26,0);        
            for(char c: str){
                vec[c - 'a']++;
            }
            return vec;
        };
        std::vector<int> vec = count(s1);
        std::vector<int> temp;
        
        for(int i = 0 ; i < (int)s2.size() - (int)s1.size() + 1 ; i++){
            if(temp.empty()){
                temp = count(s2.substr(i,s1.size()));
            }else{
                temp[s2[i-1]-'a']--;
                temp[s2[i+s1.size()-1]-'a']++;
            }
            if(std::equal(vec.begin(),vec.end(),temp.begin())){
                return true;
            }
        }        
        return false;
    }    

		
	int main(){

		return EXIT_SUCCESS; 
	}