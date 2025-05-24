/*
 * a_solution.cpp
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

struct Status {
	int64_t S = 30;
	int64_t k = 3;
	int64_t fib_k = 2;
	int64_t idx   = 2; // current index
	int64_t w_r0  = 3;
	int64_t w_c0  = 1;
	int64_t w_r1  = 7;
	int64_t w_c1  = 2;
	int64_t temp  = 0;
	const int64_t modulus = 97;
};

struct Fibonacci {
	
	int64_t d = 1;	// n-2
	int64_t e = 1;	// n-1
	int64_t f = 2;	// fibonacci[k]
	size_t k = 3;
	
	int64_t next_fib() {
		d = e;
		e = f;
		f = d + e;
		k += 1;
		return f;
	}
	
	int64_t get_fib(size_t i) {
		if(i < k) {
			cout << "get_fib() error: requested index < current index" << endl;
			exit(1);
		}
		while(k < i) (void) next_fib();
		return f;		
	}
	
};

struct Column {
	int64_t a_n2;
	int64_t a_n1;
	int64_t a_n;	// 3*a_n1 + n2
	size_t  idx;
	
	Column() {};	// default constructor
	Column(int64_t n2, int64_t n1, int64_t n, int64_t i) : a_n2(n2), a_n1(n1), a_n(n), idx(i) {};
	
	int64_t up() {
		a_n2 = a_n1;
		a_n1 = a_n;
		a_n  = 3*a_n1 + a_n2;
		idx += 1;
		return a_n;
	}
	
	void prt_col() { cout << a_n2 << " " << a_n1 << " " << a_n << endl; }
};

struct Row {
	int64_t a_n2;
	int64_t a_n1;
	int64_t a_n;	// 3*a_n2 + n1
	size_t idx;
	
	Row() {};	// default constructor
	Row(int64_t n2, int64_t n1, int64_t n, int64_t i) : a_n2(n2), a_n1(n1), a_n(n), idx(i) {};
	
	int64_t rt() {
		a_n2 = a_n1;
		a_n1 = a_n;
		a_n  = 3*a_n2 + a_n1;
		idx += 1;
		return a_n;
	}
	
	void prt_row() { cout << a_n2 << " " << a_n1 << " " << a_n << endl; }
	
};

		// Outline
		/*
		 * increment k
		 * calc fib[k] -> next required row/col index
		 * 
		 * while status.idx != fib[k]
		 * 		move col0 up 1 row
		 * 		move col1 up 1 row
		 * 		move row0 rt 1 col
		 * 		move row1 rt 1 col
		 * calc rowsum at this k
		 * calc modified colsum (exclude final vakue)
		 * S += (rowsum + colsum
		 */
		 
int main(int argc, char **argv)
{
	const int64_t target = 5;
	
	int64_t S = 30;		// current sum
	int64_t k = 3;		// current k
	int64_t idx = 2;	// current idx
	
	Fibonacci fib;	// k = 3, fib[k] = 2
	// Setup for current state
	Column col0(0,1,3,2);
	Column col1(0,2,7,2);
	
	Row row1(1,2,5,2);
	Row row0(0,1,1,2);

	
	while(k != target) {
		++k;
		int64_t next_idx = fib.get_fib(k);
		while(idx != next_idx) {
			col0.up();
			col1.up();
			row0.rt();
			row1.rt();
			idx++;
		}
		// using col0 and col1 calc the row_sum
		
		// using row0 and row1 calc the reduced col_sum
		
		// S += row_sum + reduced_col_sum
	}
	
	col0.prt_col();	
	col1.prt_col();	
	row0.prt_row();	
	row1.prt_row();	
	
	return 0;
}

