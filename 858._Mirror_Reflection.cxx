/*
 * 858._Mirror_Reflection.cxx
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
int gcd(int m, int n)
{
	if(n == 0)
		return m;
	else
		return gcd(n, m % n);
}
int mirrorReflection(int p, int q) {
	int g = gcd(p,q);
	p = (p/g) % 2;
	q = (q/g) % 2;
	
	if(q && p){
		return 1;
	}else if (p){
		return 0;
	}else {
		return 2;
	}
}

int main(int argc, char **argv)
{
	int p=1000;
	int q=999;
	std::cout<<mirrorReflection(p,q)<<std::endl;
	return 0;
}

