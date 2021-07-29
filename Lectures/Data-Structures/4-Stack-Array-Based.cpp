#include <bits/stdc++.h>
using namespace std;

// Initialize a stack with dynamic length
int n;
int capacity;
int* arr;

// This function updates the capacity of the stack
void reserve(int new_capacity) {
    // Initialize a new stack with the new capacity
    int* temp = new int[new_capacity];
    // copy the elements in the current stack to the new stack
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];
    // delete the old stack
	delete[] arr;
    // set the temp stack with new capacity to be the stack
	arr = temp;
    // set the current capacity of the stack to be the new capacity
	capacity = new_capacity;
}

// This function inserts an element at the begin of the stack
void push(int new_data) {
    // check if we need to update the capacity of the stack
    if (n == capacity)
        reserve(2 * capacity + 1);
    // insert the new element
	arr[n] = new_data;
	// update the size of the stack
	n = n + 1;
}

// This function deletes the first element in the stack
void pop() {
	// check if the stack is empty
	if (n == 0)
		return;
	// update the size of the stack
	n = n - 1;
    // check if we need to update the capacity of the stack
    if (n < capacity / 2)
        reserve(capacity / 2);
}

// This function returns the value of the first element in the stack
int top() {
	// check if the stack is empty 
	// to return the biggest integer value as an invalid value
    if (n == 0)
        return INT_MAX;
    // otherwise return the real value
    else
        return arr[n-1];
}

int main() {

	// Functionality Testing 
	
    cout << "Stack top: " << top() << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Stack top: 2147483647
	----------------------------------------------------
	*/

	push(10);
    cout << "Stack top: " << top() << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Stack top: 10
	----------------------------------------------------
	*/

	push(20);
    cout << "Stack top: " << top() << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Stack top: 20
	----------------------------------------------------
	*/

	push(30);
    cout << "Stack top: " << top() << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Stack top: 30
	----------------------------------------------------
	*/

	push(40);
    cout << "Stack top: " << top() << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Stack top: 40
	----------------------------------------------------
	*/

	push(50);
    cout << "Stack top: " << top() << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Stack top: 50
	----------------------------------------------------
	*/

	while (n > 0) {
		cout << "Stack top: " << top() << '\n';
		pop();
		cout << "Stack top has been deleted\n";
        cout << "----------------------------------------------------\n";
	}
	cout << "Stack is empty now\n";

	/* Expected Output:
	Stack top: 50
	Stack top has been deleted
	----------------------------------------------------
	Stack top: 40
	Stack top has been deleted
	----------------------------------------------------
	Stack top: 30
	Stack top has been deleted
	----------------------------------------------------
	Stack top: 20
	Stack top has been deleted
	----------------------------------------------------
	Stack top: 10
	Stack top has been deleted
	----------------------------------------------------
	Stack is empty now	
	*/

	push(10);
    cout << "Stack top: " << top() << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Stack top: 10
	----------------------------------------------------
	*/

	push(20);
    cout << "Stack top: " << top() << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Stack top: 20
	----------------------------------------------------
	*/

	push(30);
    cout << "Stack top: " << top() << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Stack top: 30
	----------------------------------------------------
	*/

	while (n > 0) {
		cout << "Stack top: " << top() << '\n';
		pop();
		cout << "Stack top has been deleted\n";
        cout << "----------------------------------------------------\n";
	}
	cout << "Stack is empty now\n";

	/* Expected Output:
	Stack top: 30
	Stack top has been deleted
	----------------------------------------------------
	Stack top: 20
	Stack top has been deleted
	----------------------------------------------------
	Stack top: 10
	Stack top has been deleted
	----------------------------------------------------
	Stack is empty now	
	*/
	
}

