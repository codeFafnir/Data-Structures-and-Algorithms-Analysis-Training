#include <bits/stdc++.h>
using namespace std;

// Initialize an deque with dynamic length
int front_idx = -1, rear_idx = -1;
int n;
int capacity;
int* arr;

// This function updates the capacity of the deque
void reserve(int new_capacity) {
    // Initialize a new deque with the new capacity
    int* temp = new int[new_capacity];
    // copy the elements in the current deque to the new deque
    for (int i = 0 ; i < n ; i++)
        temp[i] = arr[(front_idx + i) % capacity];
    // delete the old deque
	delete[] arr;
    // set the temp deque with new capacity to be the deque
	arr = temp;
    // reset front_idx and rear_idx
    front_idx = 0;
    rear_idx = n - 1;
    // set the current capacity of the deque to be the new capacity
	capacity = new_capacity;
}

// This function inserts an element at the begin of the deque
void insert_begin(int new_data) {
    // check if we need to update the capacity of the deque
    if (n == capacity)
        reserve(2 * capacity + 1);
    // check if the deque is empty
    if (n == 0)
        front_idx = rear_idx = 0;   
    // update the front_idx of the deque
    else 
        front_idx = (front_idx - 1 + capacity) % capacity;
    // insert current element into Deque 
    arr[front_idx] = new_data;
	// update the size of the deque
	n = n + 1;
}

// This function inserts an element at the end of the deque
void insert_end(int new_data) {
    // check if we need to update the capacity of the deque
    if (n == capacity)
        reserve(2 * capacity + 1);
    // check if the deque is empty
    if (n == 0)
        front_idx = rear_idx = 0;
    // update the rear_idx of the deque
    else
        rear_idx = (rear_idx + 1) % capacity;
    // insert the new element
    arr[rear_idx] = new_data; 
	// update the size of the deque
	n = n + 1;
}

// This function deletes the first element in the deque
void delete_begin() {
	// check if the deque is empty
    if (n == 0)
        return;
    // check if the deque has only one element 
    if (front_idx == rear_idx) 
        front_idx = rear_idx = -1; 
    // otherwise update the front_idx of the queue
    else
        front_idx = (front_idx + 1) % capacity; 
	// update the size of the deque
	n = n - 1;
    // check if we need to update the capacity of the deque
    if (n < capacity / 2)
        reserve(capacity / 2);
}

// This function deletes the last element in the deque
void delete_end() {
	// check if the deque is empty
    if (n == 0)
        return;
    // check if the deque has only one element 
    if (front_idx == rear_idx) 
        front_idx = rear_idx = -1; 
    // update the rear_idx of the deque
    else
        rear_idx = (rear_idx - 1 + capacity) % capacity;
	// update the size of the deque
	n = n - 1;
    // check if we need to update the capacity of the deque
    if (n < capacity / 2)
        reserve(capacity / 2);
}

// This function returns the value of the first element in the deque
int front() {
	// check if the deque is empty 
    // to return the biggest integer value as an invalid value
    if (n == 0)
        return INT_MAX;
    // otherwise return the real value
    else
        return arr[front_idx];
}

// This function returns the value of the last element in the deque
int back() {
	// check if the deque is empty 
    // to return the biggest integer value as an invalid value
    if (n == 0)
        return INT_MAX;
    // otherwise return the real value
    else
        return arr[rear_idx];
}

// This function prints the contents of the deque
void print_deque() {
    // loop to print the elements in the deque
	for (int i = 0 ; i < n ; i++)
		cout << arr[(front_idx + i) % capacity] << ' ';
}

// This function prints the contents of the deque
void print_deque_reverse() {
    // loop to print the elements in the deque
	for (int i = n-1 ; i >= 0 ; i--)
		cout << arr[(front_idx + i) % capacity] << ' ';
}

int main() {

	// Functionality Testing 

    cout << "Deque front: " << front() << " and Deque back: " << back() << '\n';
    cout << "Deque items forward:  ";
    print_deque();
    cout << '\n';
    cout << "Deque items backward: ";
    print_deque_reverse();
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Deque front: 2147483647 and Deque back: 2147483647
	Deque items forward:  
	Deque items backward: 
	----------------------------------------------------
	*/

    cout << "adding the following elements 10 20 30 40 50\n";
	insert_end(10);
	insert_end(20);
	insert_end(30);
	insert_end(40);
	insert_end(50);
    cout << "the above elements have been added to the deque\n";

	/* Expected Output:
	adding the following elements 10 20 30 40 50
	the above elements have been added to the deque
	*/

    cout << "Deque front: " << front() << " and Deque back: " << back() << '\n';
    cout << "Deque items forward:  ";
    print_deque();
    cout << '\n';
    cout << "Deque items backward: ";
    print_deque_reverse();
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Deque front: 10 and Deque back: 50
	Deque items forward:  10 20 30 40 50 
	Deque items backward: 50 40 30 20 10 
	----------------------------------------------------
	*/

    cout << "add element 60 at the end of the deque\n";
	insert_end(60);
    cout << "Deque front: " << front() << " and Deque back: " << back() << '\n';
    cout << "Deque items forward:  ";
    print_deque();
    cout << '\n';
    cout << "Deque items backward: ";
    print_deque_reverse();
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	add element 60 at the end of the deque
	Deque front: 10 and Deque back: 60
	Deque items forward:  10 20 30 40 50 60 
	Deque items backward: 60 50 40 30 20 10 
	----------------------------------------------------
	*/

    cout << "add element 20 at the begin of the deque\n";
	insert_begin(20);
    cout << "Deque front: " << front() << " and Deque back: " << back() << '\n';
    cout << "Deque items forward:  ";
    print_deque();
    cout << '\n';
    cout << "Deque items backward: ";
    print_deque_reverse();
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	add element 20 at the begin of the deque
	Deque front: 20 and Deque back: 60
	Deque items forward:  20 10 20 30 40 50 60 
	Deque items backward: 60 50 40 30 20 10 20 
	----------------------------------------------------
	*/

    cout << "add element 70 at the begin of the deque\n";
	insert_begin(70);
    cout << "Deque front: " << front() << " and Deque back: " << back() << '\n';
    cout << "Deque items forward:  ";
    print_deque();
    cout << '\n';
    cout << "Deque items backward: ";
    print_deque_reverse();
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	add element 70 at the begin of the deque
	Deque front: 70 and Deque back: 60
	Deque items forward:  70 20 10 20 30 40 50 60 
	Deque items backward: 60 50 40 30 20 10 20 70 
	----------------------------------------------------
	*/

    cout << "delete the first element \n";
	delete_begin();
    cout << "Deque front: " << front() << " and Deque back: " << back() << '\n';
    cout << "Deque items forward:  ";
    print_deque();
    cout << '\n';
    cout << "Deque items backward: ";
    print_deque_reverse();
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	delete the first element 
	Deque front: 20 and Deque back: 60
	Deque items forward:  20 10 20 30 40 50 60 
	Deque items backward: 60 50 40 30 20 10 20 
	----------------------------------------------------
	*/

    cout << "delete the last element \n";
	delete_end();
    cout << "Deque front: " << front() << " and Deque back: " << back() << '\n';
    cout << "Deque items forward:  ";
    print_deque();
    cout << '\n';
    cout << "Deque items backward: ";
    print_deque_reverse();
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	delete the last element 
	Deque front: 20 and Deque back: 50
	Deque items forward:  20 10 20 30 40 50 
	Deque items backward: 50 40 30 20 10 20 
	----------------------------------------------------
	*/

    cout << "delete the first element \n";
	delete_begin();
    cout << "Deque front: " << front() << " and Deque back: " << back() << '\n';
    cout << "Deque items forward:  ";
    print_deque();
    cout << '\n';
    cout << "Deque items backward: ";
    print_deque_reverse();
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	delete the first element 
	Deque front: 10 and Deque back: 50
	Deque items forward:  10 20 30 40 50 
	Deque items backward: 50 40 30 20 10 
	----------------------------------------------------
	*/

    cout << "delete the last element \n";
	delete_end();
    cout << "Deque front: " << front() << " and Deque back: " << back() << '\n';
    cout << "Deque items forward:  ";
    print_deque();
    cout << '\n';
    cout << "Deque items backward: ";
    print_deque_reverse();
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	delete the last element 
	Deque front: 10 and Deque back: 40
	Deque items forward:  10 20 30 40 
	Deque items backward: 40 30 20 10 
	----------------------------------------------------
	*/

    cout << "deleting the following elements 10 20 30 40\n";
    delete_end();
    delete_end();
    delete_end();
    delete_end();
    cout << "the above elements have been deleted from the deque\n";

	/* Expected Output:
	deleting the following elements 10 20 30 40
	the above elements have been deleted from the deque
	*/

    cout << "Deque front: " << front() << " and Deque back: " << back() << '\n';
    cout << "Deque items forward:  ";
    print_deque();
    cout << '\n';
    cout << "Deque items backward: ";
    print_deque_reverse();
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Deque front: 2147483647 and Deque back: 2147483647
	Deque items forward:  
	Deque items backward: 
	----------------------------------------------------
	*/

    cout << "adding the following elements 40 30 20 10\n";
	insert_begin(10);
	insert_begin(20);
	insert_begin(30);
	insert_begin(40);
    cout << "the above elements have been added to the deque\n";

	/* Expected Output:
	adding the following elements 40 30 20 10
	the above elements have been added to the deque
	*/

    cout << "Deque front: " << front() << " and Deque back: " << back() << '\n';
    cout << "Deque items forward:  ";
    print_deque();
    cout << '\n';
    cout << "Deque items backward: ";
    print_deque_reverse();
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Deque front: 40 and Deque back: 10
	Deque items forward:  40 30 20 10 
	Deque items backward: 10 20 30 40 
	----------------------------------------------------
	*/

    cout << "deleting the following elements 40 30 20 10\n";
    delete_begin();
    delete_begin();
    delete_begin();
    delete_begin();
    cout << "the above elements have been deleted from the deque\n";

	/* Expected Output:
	deleting the following elements 40 30 20 10
	the above elements have been deleted from the deque
	*/

    cout << "Deque front: " << front() << " and Deque back: " << back() << '\n';
    cout << "Deque items forward:  ";
    print_deque();
    cout << '\n';
    cout << "Deque items backward: ";
    print_deque_reverse();
    cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Deque front: 2147483647 and Deque back: 2147483647
	Deque items forward:  
	Deque items backward: 
	----------------------------------------------------
	*/

}
