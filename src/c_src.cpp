/*
 * c_src.cpp
 * 
 * Copyright 2025 mike <mike@xps14>
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
#include <cstdint>
#include "../inc/Amatrix.hpp"
using namespace std;

int main(int argc, char **argv)
{
	const vector<int64_t> fib = {0,1,1,2,3,5,8,13,21,34,55,89,144};	// fib[12] = 144;
	const int64_t modulus = 97;
	const int64_t k = 6;
	Amatrix amatrix(k, modulus);	
	
	for(int64_t c = 0; c != fib[k]; ++c) {	// limit is fib[k]
		amatrix.scan_col(c);
	}
	
	amatrix.print_matrix();
	
	// calc a basic result S(5)
	int64_t S = 0;
	for(int64_t i = 1; i < k+1; ++i) {
		if(i==4) continue;
		for(int64_t j = 1; j < k+1; ++j)	{
			if(j==4) continue;
			S += amatrix.matrix[i][j];
			S %= modulus;
		}
	}
	if(S < 0) S += modulus;
	cout << "S(5) mod 97 = " << S << endl;

	
	return 0;
}

