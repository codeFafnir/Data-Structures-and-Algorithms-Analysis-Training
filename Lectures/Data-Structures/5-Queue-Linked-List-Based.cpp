#include <bits/stdc++.h>
using namespace std;

// A queue node
struct node {
    int data;
    node* prev;
    node* next;
};

// Initialize a global pointers for head and tail
node* head;
node* tail;

// This function adds a node at the end of the queue
void push(int new_data) {
    // allocate new node and put it's data
    node* new_node = new node();
    new_node->data = new_data;    
    // check if the queue is empty
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    }
    // otherwise reach the end of the queue
    else {
        // set the next of the last node to be the new node and vice versa
        tail->next = new_node;
        new_node->prev = tail;
        // set the new node as a tail
        tail = new_node;
    }
}

// This function deletes the first node in the queue
void pop() {
    // check if the queue is empty
    if (head == NULL)
        return;
    // get the node which it will be deleted
    node* temp_node = head;
    // check if the queue has only one node
    if (head == tail) {
        // delete the temp node
        delete(temp_node);
        head = NULL;
        tail = NULL;
    }
    // otherwise the queue has nodes more than one
    else {
        // shift the head to be the next node 
        head = head->next;
        head->prev = NULL;
        // delete the temp node
        delete(temp_node);
    }
}

// This function returns the value of the first node in the queue
int front() {
	// check if the queue is empty 
    // to return the biggest integer value as an invalid value
    if (head == NULL)
        return INT_MAX;
    // otherwise return the real value
    else
        return head->data;
}

// This function returns the value of the last node in the queue
int back() {
	// check if the queue is empty 
    // to return the biggest integer value as an invalid value
    if (tail == NULL)
        return INT_MAX;
    // otherwise return the real value
    else
        return tail->data;
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

	while (head != NULL) {
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

	while (head != NULL) {
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
