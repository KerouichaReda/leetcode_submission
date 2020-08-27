/*
 * 6_ ZigZag_Conversion.cxx
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
 * https://leetcode.com/problems/zigzag-conversion/
 */
/*
 * string convert(string s, int nRows) {
    
    if (nRows <= 1)
        return s;

    const int len = (int)s.length();
    string *str = new string[nRows];

    int row = 0, step = 1;
    for (int i = 0; i < len; ++i)
    {
        str[row].push_back(s[i]);

        if (row == 0)
            step = 1;
        else if (row == nRows - 1)
            step = -1;

        row += step;
    }

    s.clear();
    for (int j = 0; j < nRows; ++j)
    {
        s.append(str[j]);
    }

    delete[] str;
    return s;
}
*/
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        std::vector<std::string> lines(numRows,"");
        std::string solution="";
        int zig=0;
        int zag=1;
        
        for(int i=0;i<(int) s.size();i++)
        {
            //std::cout<<s[i]<<" "<<zig<<" " <<zig<<std::endl;
            lines[zig]+=s[i];
            
            zig+=zag;
            if (zig==numRows-1)
                zag=-1;
            if (zig==0)
                zag=1;
        }
        for(int i=0;i<numRows;i++)
            solution=solution+lines[i];
        return solution;
        
    }
};
#include <iostream>

int main(int argc, char **argv)
{
	
	return 0;
}

