#include <bits/stdc++.h>
using namespace std;

// A deque node
struct node {
    int data;
    node* prev;
    node* next;
};

// Initialize a global pointers for head and tail
node* head;
node* tail;

// This function inserts a node at the begin of the deque
void insert_begin(int new_data) {
    // allocate new node and put it's data
    node* new_node = new node();
    new_node->data = new_data;
    // check if the deque is empty
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    }
    // otherwise insert the new node in the begin of the deque
    else {
        // set next of the new node to be the head and vice versa
        new_node->next = head;
        head->prev = new_node;
        // set the new node as a head
        head = new_node;
    }
}

// This function inserts a node at the end of the deque
void insert_end(int new_data) {
    // allocate new node and put it's data
    node* new_node = new node();
    new_node->data = new_data;
    // check if the deque is empty
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    }
    // otherwise reach the end of the deque
    else {
        // set the next of the last node to be the new node and vice versa
        tail->next = new_node;
        new_node->prev = tail;
        // set the new node as a tail
        tail = new_node;
    }
}

// This function deletes the first node in the deque
void delete_begin() {
    // check if the deque is empty
    if (head == NULL)
        return;
    // get the node which it will be deleted
    node* temp_node = head;
    // check if the deque contain only one node
    if (head == tail) {
        // delete the temp node
        delete(temp_node);
        head = NULL;
        tail = NULL;
    }
    // otherwise the deque contain nodes more than one
    else {
        // shift the head to be the next node 
        head = head->next;
        head->prev = NULL;
        // delete the temp node
        delete(temp_node);
    }
}

// This function deletes the last node in the deque
void delete_end() {
    // check if the deque is empty
    if (head == NULL)
        return;
    // get the node which it will be deleted
    node* temp_node = tail;
    // check if the deque contain only one node
    if (head == tail) {
        // delete the temp node
        delete(temp_node);
        head = NULL;
        tail = NULL;
    }
    // otherwise the deque contain nodes more than one
    else {
        // jump the deleted node
        tail = tail->prev;
        tail->next = NULL;
        // delete the node which selected
        delete(temp_node);
    }
}

// This function prints the contents of the deque
void print_deque() {
    // print the data nodes starting from head till reach the last node
    node* curr = head;
	while (curr != NULL) {
		cout << curr->data << ' ';
		curr = curr->next;
	}
}

// This function returns the value of the first element in the deque
int front() {
	// check if the deque is empty 
    // to return the biggest integer value as an invalid value
    if (head == NULL)
        return INT_MAX;
    // otherwise return the real value
    else
        return head->data;
}

// This function returns the value of the last element in the deque
int back() {
	// check if the deque is empty 
    // to return the biggest integer value as an invalid value
    if (tail == NULL)
        return INT_MAX;
    // otherwise return the real value
    else
        return tail->data;
}

// This function prints the contents of the deque
void print_deque_reverse() {
    // print the data nodes starting from tail till reach the first node
    node* curr = tail;
	while (curr != NULL) {
		cout << curr->data << ' ';
		curr = curr->prev;
	}
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
	Deque front: 20 and Deque back: 20
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
	Deque front: 10 and Deque back: 20
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
	Deque front: 10 and Deque back: 20
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

