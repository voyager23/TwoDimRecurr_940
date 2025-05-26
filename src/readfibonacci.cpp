
// Template code for reading a list of values from OEIS
// Edit for specific lists and formats

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cstdint>
#include <unordered_map>

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
	
	// Read line by line. Formnat is "number number"
	const uint64_t MaxFib = maxfib;	// the index of the highest fibonacci number requested
	uint64_t index = 0;
	size_t pos;
    std::string line;
    
    while (std::getline(file, line)) {  // Read one line at a time
		// get index and Fibonacci. Insert into map
		uint64_t idx = std::stoull(line, &pos, 10);
		if(idx == 0) continue;
		line.erase(0,pos);
		uint64_t fib = std::stoull(line, &pos, 10);
		if(idx > maxfib) break;
		std::cout << idx << "  " << fib << std::endl;
		fib_map.insert(std::pair(idx,fib));
    }
	// close file
    file.close(); // Close the file	
	// return size of map
	 
	return fib_map.size();
}

#if(1)
int main(int argc, char **argv) {
	std::unordered_map<int64_t, int64_t> fib_map;
	
	std::cout << read_fibonacci_map("b000045.txt", 50, fib_map) << " items in map." << std::endl;
	
	return 0;
}
#endif
