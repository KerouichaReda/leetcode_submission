/*
 * 8_String_to_Integer_(atoi).cxx
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
 * https://leetcode.com/problems/string-to-integer-atoi/submissions/
 */
/*
 * int myAtoi(string str) {
    int ret = 0, sign = 1, i = str.find_first_not_of(' '), base = INT_MAX / 10;
    if (str[i] == '+' || str[i] == '-') sign = str[i++] == '+' ?: -1;
    while (isdigit(str[i])) {
        if (ret > base || (ret == base && str[i] - '0' > 7)) 
            return sign > 0 ? INT_MAX : INT_MIN;
        ret = 10 * ret + (str[i++] - '0');
    }
    return sign * ret;
}
* int myAtoi(const char* str) 
{ 
    int sign = 1, base = 0, i = 0; 
    // if whitespaces then ignore. 
    while (str[i] == ' ') { 
        i++; 
    } 
    // sign of number 
    if (str[i] == '-' || str[i] == '+') { 
        sign = 1 - 2 * (str[i++] == '-'); 
    } 
    // checking for valid input 
    while (str[i] >= '0' && str[i] <= '9') { 
        // handling overflow test case 
        if (base > INT_MAX / 10 
            || (base == INT_MAX / 10 
                && str[i] - '0' > 7)) { 
            if (sign == 1) 
                return INT_MAX; 
            else
                return INT_MIN; 
        } 
        base = 10 * base + (str[i++] - '0'); 
    } 
    return base * sign; 
} 
* */
class Solution {
public:
    int myAtoi(string str) 
    {        
        string buffer="";
        unsigned int solution=0;
        int start=0;
        int length=0;
        bool found=true;
        int zeros=0;
        for(int i=0;i<str.size();i++)
        {
        
            if((str[i]== ' ' || str[i]== '0') && found==true )
            {    
                if((str[i]==' ') && i>0 && str[i-1] =='0')
                    break;
                continue;
            }
            if(str[i]=='-' || str[i]=='+' || (str[i]<= '9' && str[i]>='0'))
            {
                if((str[i]=='-' || str[i]=='+') && i>0 && (str[i-1] =='0' || str[i-1] =='+' || str[i-1] =='-'))
                    break;
                if(found)
                {
                    start=i;
                    found=false;
                }
                length++;
            }
            else
            {
                break;
            }
            
        }
        
        buffer=str.substr(start,length);
        for(int i=0;i<length;i++)
        {
            if(buffer[i]== '-' || buffer[i]== '0'|| buffer[i]== '+')
            {
                zeros++;
            }
            else
            {
                break;
            }
        }
        
        //std::cout<<buffer<<std::endl;
        if((length-zeros)>=11)
            return (buffer[0]=='-')?INT_MIN:INT_MAX;
        
        if((length-zeros)>=10)
        {
            if(buffer[0]=='-' && buffer[1]>'2')
                return INT_MIN;
            if(buffer[0]>'2')
                return INT_MAX;
        }
        
        //solution=atol(buffer.c_str());   
        for(int i=0;i<length;i++)
        {
           if(buffer[i]!= '-' &&  buffer[i]!= '+')
            {
                solution= solution*10+ (buffer[i]-'0');
            }
            else
            {
                if(found)
                break;
                found=true;
            }
        }
        //std::cout<<solution<<std::endl;  
        if(buffer[0]=='-' && solution>=(unsigned int)INT_MAX+1)
            return INT_MIN;
        if(solution>=(unsigned int)INT_MAX+1)
            return INT_MAX;   
        return (buffer[0]=='-')? -1* solution:solution;
    }
};


#include <iostream>

int main(int argc, char **argv)
{
	
	return 0;
}

