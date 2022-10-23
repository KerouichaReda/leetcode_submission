#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string makeLargestSpecial(string s) 
    {

        string result="";        
        vector<string> sub;
        
        int index=0;
        int variation=0;        
        for(int i=0; i<(int) s.size();i++)
        {
            variation+=(s[i]=='1')?1:-1;
            if (variation==0)
            {
                sub.push_back("1"+makeLargestSpecial(s.substr(index+1,i-index-1)) +"0");
                index=i+1;
            }
        }
        sort(sub.rbegin(),sub.rend());
        for(int i=0;i<(int)sub.size();i++)
        {
            result+=sub[i];
        }
    return result;
        
    }
   }
};
int main()
{
   Solution ob;
   cout << (ob.makeLargestSpecial("10101001"))<<endl;
   return 0;
}
