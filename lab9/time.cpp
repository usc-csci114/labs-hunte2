#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "hashtable.h"

using namespace std;

void fillrand(vector<int>& v) {
    for(size_t i = 0; i < v.size(); i++) {
        v[i] = rand() % 1000;
    }
}

int main() {
    srand(time(0));
    
    HashTable<int, int> ht;
    for(int i = 0; i < 100; i++) {
        ht.insert(i, rand() % 1000);
    }
    
    cout << "Find values:" << endl;
    for(int i = 0; i < 10; i++) {
        cout << "Key " << i << ": " << ht.find(i) << endl;
    }
    cout << endl;
    
    cout << "Time analysis:" << endl;
    cout << "Size\tTime" << endl;
    
    for(int size = 10000; size <= 160000; size *= 2) {
        HashTable<int, int> ht2;
        vector<int> values(size);
        fillrand(values);
        
        auto start = chrono::high_resolution_clock::now();

        for(int i = 0; i < size; i++) {
            ht2.insert(i, values[i]);
        }
        
        auto end = chrono::high_resolution_clock::now();
        auto time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        
        cout << size << "\t" << time << endl;
    }
    
    return 0;
}