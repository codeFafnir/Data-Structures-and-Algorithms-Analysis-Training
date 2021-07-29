#include <bits/stdc++.h>
using namespace std;

// A single linked list node
struct node {
    int data;
    node* next;
};

// Initialize a global pointer for head
node* head;

// This function inserts a node at the begin of the linked list
void insert_begin(int new_data) {
    // allocate new node and put it's data
    node* new_node = new node();
    new_node->data = new_data;
    // check if the linked list is empty
    if (head == NULL) {
        head = new_node;
    }
    // otherwise insert the new node in the begin of the linked list
    else {
        // set next of the new node to be the head
        new_node->next = head;
        // set the new node as a head
        head = new_node;
    }
}

// This function inserts a node at the end of the linked list
void insert_end(int new_data) {
    // allocate new node and put it's data
    node* new_node = new node();
    new_node->data = new_data;    
    // check if the linked list is empty
    if (head == NULL) {
        head = new_node;
    }
    // otherwise reach the end of the linked list
    else {
        // get the last node in the linked list
        node* curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        // set the next of the last node to be the new node
        curr->next = new_node;
    }
}

// This function require a node to add the new node after it in the linked list
void insert_node(node* prev_node, int new_data) {
    // check if the given prev node is NULL
    if (prev_node == NULL)
        return;
    // allocate new node and put it's data
    node* new_node = new node();
    new_node->data = new_data;
    // set the next of the new node to be the next of the prev node
    new_node->next = prev_node->next;
    // move the next of the prev node to be the new node
    prev_node->next = new_node;
}

// This function deletes the first node in the linked list
void delete_begin() {
    // check if the linked list is empty
    if (head == NULL)
        return;
    // get the node which it will be deleted
    node* temp_node = head;
    // check if the linked list has only one node
    if (head->next == NULL) {
        // delete the temp node
        delete(temp_node);
        head = NULL;
    }
    // otherwise the linked list has nodes more than one
    else {
        // shift the head to be the next node 
        head = head->next;
        // delete the temp node
        delete(temp_node);
    }
}

// This function deletes the last node in the linked list
void delete_end() {
    // check if the linked list is empty
    if (head == NULL)
        return;
    // get the last node and the prev node of it in the linked list
    node* curr = head;
    node* prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    // check if the linked list has only one node
    if (prev == NULL) {
        // delete the node which selected
        delete(curr);
        head = NULL;
    }
    // otherwise the linked list has nodes more than one
    else {
        // jump the deleted node
        prev->next = curr->next;
        // delete the node which selected
        delete(curr);
    }
}

// This function require a node to delete the node after it in the linked list
void delete_node(node* prev_node) {
    // check if the given prev node is NULL
    if (prev_node == NULL || prev_node->next == NULL)
        return;
    // get the deleted node in the linked list
    node* temp_node = prev_node->next;    
    // jump the deleted node
    prev_node->next = temp_node->next;
    // delete the node which selected
    delete(temp_node);
}

// This function searches for a node in the linked list
bool search_node(int key) {
    // iterate on the nodes till reach the last node in the linked list
	node* curr = head;
	while (curr != NULL) {
        // check if the given key exists in the linked list
		if (curr->data == key)
			return true;
		curr = curr->next;
	}
	return false;
}

// This function prints the contents of the linked list
void print_linked_list() {
    // print the data nodes starting from head till reach the last node
    node* curr = head;
	while (curr != NULL) {
		cout << curr->data << ' ';
		curr = curr->next;
	}
}

int main() {

	// Functionality Testing
	
    cout << "Linked List items: ";
    print_linked_list();
	cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Linked List items: 
	----------------------------------------------------
	*/

    cout << "adding the following elements 10 20 30 40 50\n";
	insert_end(10);
	insert_end(20);
	insert_end(30);
	insert_end(40);
	insert_end(50);
    cout << "the above elements have been added to the linked list\n";

	/* Expected Output:
	adding the following elements 10 20 30 40 50
	the above elements have been added to the linked list
	*/

    cout << "Linked List items: ";
    print_linked_list();
	cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Linked List items: 10 20 30 40 50 
	----------------------------------------------------
	*/

    cout << "add element 60 at the end of the linked list\n";
	insert_end(60);
    cout << "Linked List items: ";
    print_linked_list();
	cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	add element 60 at the end of the linked list
	Linked List items: 10 20 30 40 50 60 
	----------------------------------------------------
	*/

    cout << "add element 20 at the begin of the linked list\n";
	insert_begin(20);
    cout << "Linked List items: ";
    print_linked_list();
	cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	add element 20 at the begin of the linked list
	Linked List items: 20 10 20 30 40 50 60 
	----------------------------------------------------
	*/

    cout << "add element 70 at position 4 : \n";
	insert_node(head->next->next->next, 70);
    cout << "Linked List items: ";
    print_linked_list();
	cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	add element 70 at position 4 : 
	Linked List items: 20 10 20 30 70 40 50 60 
	----------------------------------------------------
	*/

    cout << "add element 90 at position 7 : \n";
	insert_node(head->next->next->next->next->next->next, 90);
    cout << "Linked List items: ";
    print_linked_list();
	cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	add element 90 at position 7 : 
	Linked List items: 20 10 20 30 70 40 50 90 60 
	----------------------------------------------------
	*/

    cout << "delete the first element \n";
	delete_begin();
    cout << "Linked List items: ";
    print_linked_list();
	cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	delete the first element 
	Linked List items: 10 20 30 70 40 50 90 60 
	----------------------------------------------------
	*/

    cout << "delete the last element \n";
	delete_end();
    cout << "Linked List items: ";
    print_linked_list();
	cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	delete the last element 
	Linked List items: 10 20 30 70 40 50 90 
	----------------------------------------------------
	*/

    cout << "delete element at position 3 : \n";
	delete_node(head->next->next);
    cout << "Linked List items: ";
    print_linked_list();
	cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	delete element at position 3 : 
	Linked List items: 10 20 30 40 50 90 
	----------------------------------------------------
	*/

    cout << "delete element at position 2 : \n";
	delete_node(head->next);
    cout << "Linked List items: ";
    print_linked_list();
	cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	delete element at position 2 : 
	Linked List items: 10 20 40 50 90 
	----------------------------------------------------
	*/

	if (search_node(40))
		cout << "element " << 40 << " in the linked list\n";
	else
		cout << "element " << 40 << " not in the linked list\n";

	if (search_node(100))
		cout << "element " << 100 << " in the linked list\n";
	else
		cout << "element " << 100 << " not in the linked list\n";
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	element 40 in the linked list
	element 100 not in the linked list
	----------------------------------------------------
	*/

    cout << "deleting the following elements 10 20 40 50 90\n";
    delete_end();
    delete_end();
    delete_end();
    delete_end();
    delete_end();
    cout << "the above elements have been deleted from the linked list\n";

	/* Expected Output:
	deleting the following elements 10 20 40 50 90
	the above elements have been deleted from the linked list
	*/

    cout << "Linked List items: ";
    print_linked_list();
	cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Linked List items: 
	----------------------------------------------------
	*/

    cout << "adding the following elements 30 20 10\n";
	insert_begin(10);
	insert_begin(20);
	insert_begin(30);
    cout << "the above elements have been added to the linked list\n";

	/* Expected Output:
	adding the following elements 30 20 10
	the above elements have been added to the linked list
	*/

    cout << "Linked List items: ";
    print_linked_list();
	cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Linked List items: 30 20 10 
	----------------------------------------------------
	*/

    cout << "deleting the following elements 30 20 10\n";
    delete_begin();
    delete_begin();
    delete_begin();
    cout << "the above elements have been deleted from the linked list\n";

	/* Expected Output:
	deleting the following elements 30 20 10
	the above elements have been deleted from the linked list
	*/

    cout << "Linked List items: ";
    print_linked_list();
	cout << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	Linked List items: 
	----------------------------------------------------
	*/

}

