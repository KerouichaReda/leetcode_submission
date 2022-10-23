/*
 * 5_Longest_Palindromic_Substring.cxx
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
 * https://leetcode.com/problems/longest-palindromic-substring/submissions/
 */


#include <iostream>
#include <string>
using namespace std;
bool ispalin(std::string sub)
    {
        for(int i=0,j=sub.size()-1; i<=j;i++,j--)
        {
            if(sub[i]!=sub[j])
            {
                return false;
            }
        }
        return true;
    }
std::string longestPalindrome(std::string s) {
        string solution,sub;
        int left=0;
        int right=0;
        int left1max=0;
        int left2max=0;
        int right1max=0;
        int right2max=1;
        if(ispalin(s))
            return s;
        for(int i=0;i<(int)s.size();i++)
        {
            
               
                left=left1max;
                right=right1max;
                while(ispalin(s.substr(i-left,right+left+1)))
                {
                    //std::cout<<i<<" "<<i-left<<" "<<i+right<<std::endl;
                    sub=s.substr(i-left,right+left+1);
                    std::cout<<i<<" "<<i-left<<" "<<i+right<<" " <<sub<<std::endl;
                    left++;
                    right++;  
                    if(i-left<0 || i+right>=(int)s.size())
                    break;                  
                }
                if(sub.size()>=solution.size())
                {
                solution=sub;
                right1max=right;
                left1max=left;  
				}
                left=left2max;
                right=right2max;
                while(ispalin(s.substr(i-left,right+left+1)))
                {
                    //std::cout<<i<<" "<<i-left<<" "<<i+right<<std::endl;
                    sub=s.substr(i-left,right+left+1);
                    std::cout<<i<<" "<<i-left<<" "<<i+right<<" " <<sub<<std::endl;
                    left++;
                    right++;  
                    if(i-left<0 || i+right>=(int)s.size())
                    break;                  
                }
                if((int)sub.size()>=(int)solution.size())
                {
                solution=sub;
                right2max=right;
                left2max=left;  
				}
                
            
            
        }
        return solution;
        
    }
    /* NOT MY SOLUTION
    string longestPalindrome(string s) {
        if (s.size()<=1) 
            return s;
        int min_left=0;
        int max_len=1;
        int max_right=s.size()-1;
        for (int mid=0;mid<s.size();){
            int left=mid;
            int right=mid;
            while (right<max_right && s[right+1]==s[right])
                right++; // Skip duplicate characters in the middle
            mid=right+1; //for next iter
            while (right<max_right && left>0 && s[right+1]==s[left-1]){
                right++; 
                left--;
            } // Expand the selection as long it is a palindrom
            int new_len=right-left+1; //record best palindro
            if (new_len>max_len){ 
                min_left=left; 
                max_len=new_len; 
            }
        }
        return s.substr(min_left, max_len);
    }*/
    
int main(int argc, char **argv)
{
	std::string test="abbac";
	std::cout<<  longestPalindrome(test)<<std::endl;
	//std::cout<<  test.substr(0,1)<<std::endl;
	std::cout<< ispalin(test)<<std::endl;
	
	
	return 0;
}

