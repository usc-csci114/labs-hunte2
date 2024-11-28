#include <iostream>
#include <chrono>
#include <list>

using namespace std;

template <typename T>
T at(list<T>& ll, size_t idx)
{
	//implement an access-by-index for a linked list

	//1. Use auto to create an iterator for the list ll and set it to the .begin() iterator
	auto it = ll.begin();
	
	//2. Increment the iterator idx times
	for(int i =0; i < idx; i++){
		it++;
	}

	
	//3. Return *it
	return *it;
	
	
}

int main(){
	size_t size = 1000;
	
	for(int x = 0; x < 20; x++)
	{
		//1. Resize my_list to have size*x items
		list<int> my_list(size * x);
		
		//2. log the start time (see part 1)
		const auto start = std::chrono::steady_clock::now();
		
		//3. Use a for loop to iterate through all indexs of my_list by calling 
		//   at<int>(my_list, i)
		for (size_t i = 0; i < my_list.size(); ++i) {
			 at<int>(my_list, i);
		}
		
		//4. log the end time and calculate the diff
		const auto end = std::chrono::steady_clock::now();
		const std::chrono::duration<double> diff = end - start;

		cout << "Iterating linked list for size " << my_list.size() << ": ";
		cout << diff.count() << endl;


		//after viewing the graph, the runtime is no doubt O(n^2) because the R^2 value is .994
	}
}
