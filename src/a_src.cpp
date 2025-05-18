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

void set_right_cell(Matrix& A, size_t n, size_t m) {	// n -> row, m-> col
	//~ if((A[m][n] == 0) or (A[m][n+1] == 0)) {
		//~ cout << "set_right_cell Error\n";
		//~ //exit(1);
	//~ }
	A[n][m+1] = A[n][m] + A[n+1][m];
}

void set_diag_cell(Matrix& A, size_t n, size_t m) {
	//~ if((A[m][n] == 0) or (A[m+1][n] == 0)) {
		//~ cout << "set_diag_cell Error\n";
		//~ //exit(1);
	//~ }
	A[n+1][m+1] = A[n][m] + 2*(A[n][m+1]);
}

void set_up_cell(Matrix& A, size_t n, size_t m) {
	//~ if((A[m+1][n] == 0) or (A[m][n] == 0)) {
		//~ cout << "set_up_cell Error\n";
		//~ //exit(1);
	//~ }
	A[n+1][m] = A[n][m+1] - A[n][m];	
}

void prt_matrix(Matrix& A, const long int limit) {
	for(auto n = A.rbegin(); n != A.rend(); ++n) {
		for(auto m = n->begin(); m != n->end(); ++m) cout << *m << " ";
		cout << endl;
	}
}

int main(int argc, char **argv)
{
	const long int k = 6;
	const long int limit = fib[k];
	
	Matrix matrix(limit, vector<long int>(limit,0));
	matrix[0][0] = 0;
	matrix[1][0] = 1;
	
	prt_matrix(matrix,limit);
	cout << endl;
	
	// set value in A[1][1]
	set_right_cell(matrix,0,0);
	prt_matrix(matrix,limit);
	cout << endl;	
	set_diag_cell(matrix,0,0);
	prt_matrix(matrix,limit);
	cout << endl;
	// set value in A[1][2]
	set_right_cell(matrix,0,1);
	prt_matrix(matrix,limit);
	cout << endl;	
	set_diag_cell(matrix,0,1);
	prt_matrix(matrix,limit);
	cout << endl;
	cout << endl;
	
	// starting at base of column[1]
	set_diag_cell(matrix,1,1);
	prt_matrix(matrix,limit);
	cout << endl;	
	set_up_cell(matrix,1,1);
	prt_matrix(matrix,limit);
	cout << endl;	
	
	set_diag_cell(matrix,2,1);
	prt_matrix(matrix,limit);
	cout << endl;	
	set_up_cell(matrix,2,1);
	prt_matrix(matrix,limit);
	cout << endl;	
	
	set_diag_cell(matrix,3,1);
	prt_matrix(matrix,limit);
	cout << endl;	
	set_up_cell(matrix,3,1);
	prt_matrix(matrix,limit);
	cout << endl;	
	cout << endl;	
	
	// starting at base of column[2]
	cout << "==========" << endl;	
	set_right_cell(matrix,0,2);
	prt_matrix(matrix,limit);
	cout << endl;	

	set_right_cell(matrix,1,2);
	prt_matrix(matrix,limit);
	cout << endl;	

	set_right_cell(matrix,2,2);
	prt_matrix(matrix,limit);
	cout << endl;	
	
	set_right_cell(matrix,3,2);
	prt_matrix(matrix,limit);
	cout << endl;	
	
	set_right_cell(matrix,4,2);
	prt_matrix(matrix,limit);
	cout << endl;
	
	set_right_cell(matrix,4,2);
	prt_matrix(matrix,limit);
	cout << endl;	
	
	

	
	
	return 0;
}

