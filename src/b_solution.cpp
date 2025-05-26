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


int main(int argc, char **argv)
{
	unordered_map<int64_t, int64_t> fib_map;
	(void) read_fibonacci_map("b000045.txt", 50, fib_map);
	const int64_t K = 5;
	int64_t S = 2;
	int64_t i, fi, j, fj;	// fibonacci row, fibonacci col
	int64_t x = 1, y = 1;	// current working column x, row y.
	
	for(i = 2; i <= K; ++i) {
		fi = fib_map[i];
		for(j = 2; j <= K; ++j) {
			fj = fib_map[j];
			cout << "a(" << fi << "," << fj << ")" << endl;
		}
	}	
	return 0;
}

