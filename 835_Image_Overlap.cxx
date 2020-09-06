/*
 * 835_Image_Overlap.cxx
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
#include <vector>


int largestOverlap(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B) 
    {
        int len=A.size();
        int max=0,sum=0;
        int p1,p2,p3,p4;
        for (int i = -len+1; i < len; i++)
        {            
            for (int j = -len+1; j < len; j++)
            {
                    sum=0;                    
                    for (int k = 0; k < len-abs(i); k++)
                    {                        
                        p1=(i<0)? abs(i)+k : k;
                        p3=(i<0)? k:i+k ;
                        for (int l = 0; l < len-abs(j); l++)
                        {
                            p2=(j<0)? abs(j)+l: l;                            
                            p4=(j<0)? l:j+l ;                            
                            sum+=A[p1][p2]*B[p3][p4]; 
                        }

                    }
                if(sum>=max)
                    max=sum;
			}  
        }
        return max;
    }




int main(int argc, char **argv)
{
	std::vector<std::vector<int>> A{{1,1,1},{0,1,0},{0,0,0}};
	std::vector<std::vector<int>> B{{0,1,0},{1,1,1},{1,1,1}};
	int test=largestOverlap(A,B);
	std::cout<<test<<std::endl;
	return 0;
}

