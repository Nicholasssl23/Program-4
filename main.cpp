#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
public:
    SpecialStack() {}

    void push(int value) {
        data.push(value);
    }

    void pop() {
        if (data.empty()) {
            throw 1; // Throw an exception if the stack is empty
        }
        data.pop();
    }

    int peek() {
        if (data.empty()) {
            throw 1; // Throw an exception if the stack is empty
        }
        return data.top();
    }

    bool empty() {
        return data.empty();
    }

    void popOdd() {
        stack<int> temp;
        bool foundOdd = false;

        // Find and remove the latest odd number
        while (!data.empty()) {
            int current = data.top();
            data.pop();
            if (current % 2 != 0 && !foundOdd) {
                foundOdd = true; // Found and removed the odd number
            } else {
                temp.push(current);
            }
        }

        if (!foundOdd) {
            throw 1; // Throw an exception if no odd number is found
        }

        // Restore the remaining elements
        while (!temp.empty()) {
            data.push(temp.top());
            temp.pop();
        }
    }

    void popEven() {
        stack<int> temp;
        bool foundEven = false;

        // Find and remove the latest even number
        while (!data.empty()) {
            int current = data.top();
            data.pop();
            if (current % 2 == 0 && !foundEven) {
                foundEven = true; // Found and removed the even number
            } else {
                temp.push(current);
            }
        }

        if (!foundEven) {
            throw 1; // Throw an exception if no even number is found
        }

        // Restore the remaining elements
        while (!temp.empty()) {
            data.push(temp.top());
            temp.pop();
        }
    }

    void printStack() {
        stack<int> temp = data; // Create a copy to avoid modifying the original stack
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

private:
    stack<int> data;
};

int main() {
    SpecialStack one, two, three, four;

    try {
        cout << "Stack one" << endl;
        one.push(41);
        one.push(66);
        one.push(91);
        one.push(88);
        one.push(33);
        one.popEven();
        one.printStack();
    }
    catch (int e) {
        cout << "Unable to complete operations on Stack one" << endl << endl;
    }

    try {
        cout << "Stack two" << endl;
        two.push(1);
        two.push(9);
        two.push(6);
        two.push(2);
        two.push(8);
        two.push(6);
        two.push(4);
        two.popOdd();
        two.printStack();
    }
    catch (int e) {
        cout << "Unable to complete operations on Stack two" << endl << endl;
    }

    try {
        cout << "Stack three" << endl;
        three.popEven();
        three.printStack();
    }
    catch (int e) {
        cout << "Unable to complete operations on Stack three" << endl << endl;
    }

    try {
        cout << "Stack four" << endl;
        four.pop();
        four.printStack();
    }
    catch (int e) {
        cout << "Unable to complete operations on Stack four" << endl << endl;
    }
    return 0;
}