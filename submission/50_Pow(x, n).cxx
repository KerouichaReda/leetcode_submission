/*
 * 50_Pow(x, n).cxx
 * 
 * Copyright 2021 RedaKerouicha <redakerouicha@localhost>
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

    double myPow(double x, int n) {
    if (n==0) return 1;
    if (n==1) return x;
    if (n==-1) return 1/x;
    return myPow(x*x, n/2) * (n % 2 == 0 ? 1: n>0?x : 1/x);
    }

int main(int argc, char **argv)
{
	std::cout << myPow(2,35) << std::endl;
	return 0;
}

