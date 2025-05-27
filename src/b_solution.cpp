/*
 * b_solution.cpp
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
#include <fstream>
#include <string>
#include <set>
#include <cstdint>
#include <array>
#include <unordered_map>

using namespace std;

/* Read text file from OEIS A000045
 * Format is n  fib
 *           1   1
 * 			 2   2
 *          50   12,586,269,025
 */
 
 int read_fibonacci_map(std::string fname, uint64_t maxfib, std::unordered_map<int64_t, int64_t>& fib_map);
 int read_fibonacci_map(std::string fname, uint64_t maxfib, std::unordered_map<int64_t, int64_t>& fib_map) {
	 
	 if(!fib_map.empty()) fib_map.clear();
	
	// open file or error message
    std::ifstream file(fname); // Open the file
    if (!file) {
        std::cerr << "Error opening file!\n";
        return 1;
    }
	
	// Read line by line. Format is "number number"
	size_t pos;
    std::string line;
    
    while (std::getline(file, line)) {  // Read one line at a time
		// get index and Fibonacci. Insert into map
		uint64_t idx = std::stoull(line, &pos, 10);
		if(idx == 0) continue;
		line.erase(0,pos);
		uint64_t fib = std::stoull(line, &pos, 10);
		if(idx > maxfib) break;
		// debug print std::cout << idx << "  " << fib << std::endl;
		fib_map.insert(std::pair(idx,fib));
    }
	// close file
    file.close(); // Close the file	
	// return size of map
	 
	return fib_map.size();
}

struct ColDataBlk {
	array<int64_t, 3> a;	// a[0] is most recent, a[1] and a[2] prev values
	int64_t posn;
	
	ColDataBlk(int64_t _a0, int64_t _a1, int64_t _a2, int64_t p) {
		a[0] = _a0;
		a[1] = _a1;
		a[2] = _a2;
		posn = p;
	}
	
	void move_east(int64_t fib_col) {
		if(fib_col < posn) {
			cout << "move_east cannot move to lower index." << endl;
			exit(1);
		}
		while(posn < fib_col) {
			a[2] = a[1];
			a[1] = a[0];
			a[0] = a[1] + 3*a[2];
			posn++;
		}
	}
};

struct RowDataBlk {
	array<int64_t, 3> a;	// a[0] is most recent, a[1] and a[2] prev values
	int64_t posn;
	
	RowDataBlk(int64_t _a0, int64_t _a1, int64_t _a2, int64_t p) {
		a[0] = _a0;
		a[1] = _a1;
		a[2] = _a2;
		posn = p;
	}
	
	void move_north(int64_t fib_col) {
		if(fib_col < posn) {
			cout << "move_north cannot move to lower index." << endl;
			exit(1);
		}
		while(posn < fib_col) {
			a[2] = a[1];
			a[1] = a[0];
			a[0] = a[1] + 3*a[2];
			posn++;
		}
	}
	
	void prt_block() {
		cout << "Posn: " << posn << "  " << a[0] << "," << a[1] << "," << a[2] << endl;
	}
};

int main(int argc, char **argv)
{
	unordered_map<int64_t, int64_t> fib_map;
	(void) read_fibonacci_map("b000045.txt", 50, fib_map);
	const int64_t K = 5;
	int64_t S = 2;
	int64_t i, fi, j, fj;	// fibonacci row, fibonacci col
	int64_t x = 1, y = 1;	// current working column x, row y.
	
	// setup the initial RowDataBlk
	RowDataBlk rdb(1,0,0,0);
	rdb.prt_block();
	for(i = 2; i <= K; ++i) {
		fi = fib_map[i];
		rdb.move_north(fi);
		rdb.prt_block();
	}	
	return 0;
}

