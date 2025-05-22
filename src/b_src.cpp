/*
 * a_src.cpp
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
	const int64_t k = 6;
	Amatrix amatrix(k);	
	amatrix.print_matrix();
	
	for(int64_t c = 0; c != 8; ++c) {
		amatrix.scan_col(c);
		amatrix.print_matrix();
	}
	
	// calc a basic result S(5)
	int64_t S = 0;
	for(int64_t i = 1; i < 6; ++i) {
		if(i==4) continue;
		for(int64_t j = 1; j < 6; ++j)	{
			if(j==4) continue;
			S += amatrix.matrix[i][j];
		}
	}
	cout << "S(5) = " << S << endl;

	
	return 0;
}

