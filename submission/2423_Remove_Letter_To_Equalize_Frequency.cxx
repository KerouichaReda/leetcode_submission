    #include <string>
    #include <unordered_map>
    #include <vector>
    #include <iostream>
    #include <functional>
    bool equalFrequency(std::string word) {
        std::unordered_map<char,int> m,f; 
        for(char& c : word) m[c]++;
        for(auto p : m) f[p.second]++ ;
        return true;
        
    }