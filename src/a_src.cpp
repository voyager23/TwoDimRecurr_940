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
using namespace std;

typedef vector<vector<long int>> Matrix; 
const vector<long int> fib = {0,1,1,2,3,5,8,13,21,34,55};	// fib[10] = 55;

void set_right_cell(Matrix& A, size_t m, size_t n) {
	if((A[m][n] == 0) or (A[m][n+1] == 0)) {
		cout << "set_right_cell Error\n";
		exit(1);
	}
	A[m+1][n] = A[m][n] + A[m][n+1];
}

void set_diag_cell(Matrix& A, size_t m, size_t n) {
	if((A[m][n] == 0) or (A[m+1][n] == 0)) {
		cout << "set_diag_cell Error\n";
		exit(1);
	}
	A[m+1][n+1] = A[m][n] + 2*A[m][n+1];
}

void set_up_cell(Matrix& A, size_t m, size_t n) {
	if((A[m+1][n] == 0) or (A[m][n] == 0)) {
		cout << "set_up_cell Error\n";
		exit(1);
	}
	A[m][n+1] = A[m+1][n] + A[m][n];	
}

void prt_matrix(Matrix& A, const long int limit) {
	for(auto n = A.rbegin(); n != A.rend(); ++n) {
		for(auto m = n->begin(); m != n->end(); ++m) cout << *m << " ";
		cout << endl;
	}
}

int main(int argc, char **argv)
{
	const long int k = 5;
	const long int limit = fib[k];
	
	Matrix matrix(limit, vector<long int>(limit,0));
	matrix[0][0] = 0;
	matrix[1][0] = 1;
	prt_matrix(matrix,limit);
	
	return 0;
}

