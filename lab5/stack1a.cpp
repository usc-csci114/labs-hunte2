#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    vector<int> numbers;
    int number;
    
    cout << "Enter integers (atop input using Ctrl-D):" << endl;
    while (cin >> number) {
        numbers.push_back(number);
    }
    cout << "In order: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    stack<int> stack;
    for (int num : numbers) {
        stack.push(num);
    }

    cout << "Reversed order: ";
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;

    return 0;
}
