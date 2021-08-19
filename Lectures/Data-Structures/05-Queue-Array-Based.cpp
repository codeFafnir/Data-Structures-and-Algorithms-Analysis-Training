#include <bits/stdc++.h>
using namespace std;

// Initialize a queue with dynamic length
int front_idx, rear_idx;
int n, capacity;
int* arr;

// This function updates the capacity of the queue
void reserve(int new_capacity) {
    // Initialize a new queue with the new capacity
    int* temp = new int[new_capacity];
    // copy the elements in the current queue to the new queue
    for (int i = 0 ; i < n ; i++)
        temp[i] = arr[(front_idx + i) % capacity];
    // delete the old queue
    delete[] arr;
    // set the temp queue with new capacity to be the queue
    arr = temp;
    // reset front_idx and rear_idx
    if (n == 0)
        front_idx = rear_idx = 0;
    else
        front_idx = 0, rear_idx = n - 1;
    // set the current capacity of the queue to be the new capacity
    capacity = new_capacity;
}

// This function inserts an element at the begin of the queue
void push(int new_data) {
    // check if we need to update the capacity of the queue
    if (n == capacity)
        reserve(2 * capacity + 1);
    // check if the queue is empty
    if (n == 0)
        front_idx = rear_idx = 0; 
    // update the rear_idx of the queue
    else
        rear_idx = (rear_idx + 1) % capacity;
    // insert the new element
    arr[rear_idx] = new_data; 
    // update the size of the queue
    n = n + 1;
}

// This function deletes the first element in the queue
void pop() {
    // check if the queue is empty
    if (n == 0)
        return;
    // check if the queue has only one element 
    if (front_idx == rear_idx) 
        front_idx = rear_idx = 0; 
    // otherwise update the front_idx of the queue
    else
        front_idx = (front_idx + 1) % capacity; 
    // update the size of the queue
    n = n - 1;
    // check if we need to update the capacity of the queue
    if (n < capacity / 2)
        reserve(capacity / 2);
}

// This function returns the value of the first element in the queue
int front() {
    // check if the queue is empty 
    // to return the biggest integer value as an invalid value
    if (n == 0)
        return INT_MAX;
    // otherwise return the real value
    else
        return arr[front_idx];
}

// This function returns the value of the last element in the queue
int back() {
    // check if the queue is empty 
    // to return the biggest integer value as an invalid value
    if (n == 0)
        return INT_MAX;
    // otherwise return the real value
    else
        return arr[rear_idx];
}

int main() {

    // Functionality Testing 

    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 2147483647 and Queue back: 2147483647
    ----------------------------------------------------
    */

    push(10);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 10
    ----------------------------------------------------
    */

    push(20);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 20
    ----------------------------------------------------
    */

    push(30);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 30
    ----------------------------------------------------
    */

    push(40);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 40
    ----------------------------------------------------
    */

    push(50);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 50
    ----------------------------------------------------
    */

    while (n > 0) {
        cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
        pop();
        cout << "queue front has been deleted\n";
        cout << "----------------------------------------------------\n";
    }
    cout << "Queue is empty now\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 50
    queue front has been deleted
    ----------------------------------------------------
    Queue front: 20 and Queue back: 50
    queue front has been deleted
    ----------------------------------------------------
    Queue front: 30 and Queue back: 50
    queue front has been deleted
    ----------------------------------------------------
    Queue front: 40 and Queue back: 50
    queue front has been deleted
    ----------------------------------------------------
    Queue front: 50 and Queue back: 50
    queue front has been deleted
    ----------------------------------------------------
    Queue is empty now
    */

    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 2147483647 and Queue back: 2147483647
    ----------------------------------------------------
    */

    push(10);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 10
    ----------------------------------------------------
    */

    push(20);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 20
    ----------------------------------------------------
    */

    push(30);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 30
    ----------------------------------------------------
    */

    while (n > 0) {
        cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
        pop();
        cout << "queue front has been deleted\n";
        cout << "----------------------------------------------------\n";
    }
    cout << "Queue is empty now\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 30
    queue front has been deleted
    ----------------------------------------------------
    Queue front: 20 and Queue back: 30
    queue front has been deleted
    ----------------------------------------------------
    Queue front: 30 and Queue back: 30
    queue front has been deleted
    ----------------------------------------------------
    Queue is empty now
    */

}
