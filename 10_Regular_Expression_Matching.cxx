/*
 * 10_Regular_Expression_Matching.cxx
 * 
 * Copyright 2020 RedaKerouicha <redakerouicha@localhost>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
using namespace std;
bool match(string s, string p,int i,int j);
    bool isMatch(string s, string p) 
    {
        int ls=s.length();
        int lp=p.length();
        
        
        return match(s,p,ls-1,lp-1);
        
    }
    bool match(string s, string p,int i,int j)
    {
        
        int myi=(i-1)*(i>0);
        int myj=(j-1)*(j>0);
        std::cout<<s[i]<<" "<<p[j]<<" "<<i<<" "<<j<<std::endl;
        
        
        if(i<=0 && j<=0 && p[1]=='*' && s[0]==s[1])
            return true;
        
        if(i==0 && j==0)
            return s[i]==p[j] || p[j]=='.';
        
        
        
        
        if (s[i]==p[j] || p[j]=='.')
        {
            if((j==0 ) && (p[j]=='.' || p[j]==s[i]) && p[(j==(int)p.length()-1)?j:j+1]!='*')
                return false;
            return match(s,p,myi,myj);
        }
        else if (s[i]!=p[j] && p[j]!='.' && p[j]!='*')
        {
            return false;
        
        }
        else if(p[j]=='*')
        {
            
            if(s[i]!=p[myj] && myj>0)
                return match(s,p,i,myj-1);
            else if (s[i]!=p[myj] && myj==0)
                return match(s,p,i,myj);
            else if (s[i]==s[myi] && j>1 && i>1)
                return match(s,p,myi,j);
            else
            return match(s,p,i,myj);
        }
        
       return false ;
    }


int main(int argc, char **argv)
{
	std::string s[]={"aa","ab","aab","mississippi"};
	std::string p[]={"a*",".*","c*a*b","c*mis*is*ip*.c*"};
	int l=3;
	
		std::cout<<"s = "<<s[l]<<std::endl;
		std::cout<<"p = "<<p[l]<<std::endl;
		std::cout<<isMatch(s[l],p[l])<<std::endl;
	
	return 0;
}

