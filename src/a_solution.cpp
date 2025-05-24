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

struct Fibonacci {
	int64_t d = 1;	// n-2
	int64_t e = 1;	// n-1
	int64_t f = 2;	// fibonacci[k]
	size_t k = 3;
	
	int64_t next_fib() {
		d = e;
		e = f;
		f = d + e;
		idx += 1;
		return f;
	}
	
	int64_t get_fib(size_t i) {
		if(i < idx) {
			cout << "get_fib() error: requested index < current index" << endl;
			exit(1);
		}
		while(idx < i) (void) next_fib();
		return f;		
	}	
};

struct Column0 {
	int64_t a_n2 = 0;
	int64_t a_n1 = 1;
	int64_t a_n  = 3;	// 3*a_n1 + n2
	size_t idx = 2;
	
	int64_t next_col0() {
		a_n2 = a_n1;
		a_n1 = a_n;
		a_n  = 3*a_n1 + a_n2;
		idx += 1;
		return a_n;
	}
};

struct Row0 {
	int64_t a_n2 = 0;
	int64_t a_n1 = 1;
	int64_t a_n  = 1;	// 3*a_n2 + n1
	size_t idx = 2;
	
	int64_t next_col0() {
		a_n2 = a_n1;
		a_n1 = a_n;
		a_n  = 3*a_n1 + a_n2;
		idx += 1;
		return a_n;
	}	
};

struct Status {
	int64_t S = 30;
	int64_t k = 3;
	int64_t fib_k = 2;
	int64_t idx   = 2; // controlled by fib[k]
	int64_t w_r0  = 3;
	int64_t w_r1  = 7;
	int64_t w_c0  = 1;
	int64_t w_c1  = 5;
	int64_t temp  = 0;
	const int64_t modulus = 97;
}

int main(int argc, char **argv)
{
	const int64_t target = 5;
	Fibonacci fib;
	Status status;
	// Initialised for S(3), Sum = 30, fib[3] = 2
	while(status.k != target) {
		/*
		 * increment k
		 * calc fib[k] -> next row/col index
		 * while status.idx != fib[k]
		 * 		move col0 up 1 row
		 * 		move col1 up 1 row
		 * 		move row0 rt 1 col
		 * 		move row1 rt 1 col
		 * calc rowsum at this k
		 * calc modified colsum (exclude final vakue)
		 * S += (rowsum + colsum
		 */
	 }
 }
	
	

	



	
	return 0;
}

