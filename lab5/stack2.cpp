#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void fillrand(vector<int>& v) {
    for(size_t i = 0; i < v.size(); i++) {
        v[i] = rand() % 1000; 
    }
}

int main() {
    srand(time(0));
    vector<int> v(100);
    fillrand(v);
    
    priority_queue<int> pq(v.begin(), v.end());
    

    list<int> sort;
    while(!pq.empty()) {
        sort.push_front(pq.top());
        pq.pop();
    }
    
    for(int x : sort) {
        cout << x << " "; //print the rand sorted numbers
    }
    cout << endl;
    
    cout << "Time analysis:" << endl;
    cout << "Size\tTime" << endl;
    
    for(int size = 10000; size <= 320000; size *= 2) {
        vector<int> v2(size);
        fillrand(v2);
        
        auto start = chrono::high_resolution_clock::now();
        
        priority_queue<int> pq2(v2.begin(), v2.end());
        while(!pq2.empty()) {
            pq2.pop();
        }
        
        auto end = chrono::high_resolution_clock::now();
        auto time = chrono::duration_cast<chrono::milliseconds>(end - start).count(); //check time diff
        
        cout << size << "     " << time << endl; //show size and time differential
    }
    
    /*Size	Time
    10000     8
    20000     16
    40000     34
    80000     71
    160000    148
    320000    359*/

    //time slightly increases by over double over time, so O(nlogn) is very likely


    return 0;
}