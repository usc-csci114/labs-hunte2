#include <iostream>
#include <chrono>
#include <list>

using namespace std;


int main(){
	size_t size = 100000;
	
	for(int x = 0; x < 20; x++)
	{
		
		//1. Resize my_list to have size*x items
		list<int> my_list(size * x);
		
		//2. log the start time (see part 1)
		const auto start = std::chrono::steady_clock::now();
		
		//3. Use a for loop with an iterator to iterate through all items in the list
		//   The body of the for loop can be empty
		for (auto it = my_list.begin(); it != my_list.end(); ++it) {
		}
		
		//4. log the end time and calculate the diff
		const auto end = std::chrono::steady_clock::now();
		const std::chrono::duration<double> diff = end - start;

		cout << "Iterating linked list for size " << my_list.size() << ": ";
		cout << diff.count() << endl;
	}
}
