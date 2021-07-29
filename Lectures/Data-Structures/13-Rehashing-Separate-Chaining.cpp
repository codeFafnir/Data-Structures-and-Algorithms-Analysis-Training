#include <bits/stdc++.h>
using namespace std;

// A single linked list node
struct node {
    string data;
    node* next;
};

// This function inserts a node at the begin of the linked list
node* insert_begin(node* curr_head, string key) {
    // allocate new node and put it's data
    node* new_node = new node();
    new_node->data = key;
    // check if the linked list is empty
    if (curr_head == NULL) {
        curr_head = new_node;
    }
    // otherwise insert the new node in the begin of the linked list
    else {
        // set next of the new node to be the head
        new_node->next = curr_head;
        // set the new node as a head
        curr_head = new_node;
    }
    return curr_head;
}

// This function require a node to delete the node after it in the linked list
node* delete_node(node* curr_head, string key) {
    // check if the linked list is empty
    if (curr_head == NULL)
        return curr_head;
    // check if the first node in the list is the deleted node
    if (curr_head->data == key) {
        // get the node which it will be deleted
        node* temp_node = curr_head;
        // shift the head to be the next node 
        curr_head = curr_head->next;
        // delete the temp node
        delete(temp_node);
    }
    // otherwise loop till reach the deleted node
    else {
        // get the deleted node and the prev node of it in the linked list
        node* curr = curr_head;
        node* prev = NULL;
        while (curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }
        // jump the deleted node
        prev->next = curr->next;
        // delete the node which selected
        delete(curr);
    }
    return curr_head;
}

// This function searches for a node in the linked list
bool search_node(node* curr_head, string key) {
    // iterate on the nodes till reach the last node in the linked list
	node* curr = curr_head;
	while (curr != NULL) {
        // check if the given key exists in the linked list
		if (curr->data == key)
			return true;
		curr = curr->next;
	}
	return false;
}

// This function prints the contents of the linked list
void print_linked_list(node* curr_head) {
    // print the data nodes starting from head till reach the last node
    node* curr = curr_head;
	while (curr != NULL) {
		cout << curr->data << "\n";
		curr = curr->next;
	}
}

// This function deletes all nodes in the linked list in iterative way
void delete_linked_list(node* curr_head) {
	node* curr = curr_head;
	while (curr != NULL) {
		curr_head = curr_head->next;
		delete(curr);
		curr = curr_head;
	}
}

// Initialize a hash table with dynamic length
int n;
int capacity;
// Initialize a global array pointer for heads
node** head;

// Initialize the load_factor
const float load_factor = 0.5;

// This function find the next prime of the given number
int get_next_prime(int x) {
    // loop for maximum 150 numbers after x to find a prime one
    for (int i = x + 1 ; i < x + 150 ; i++) {
        bool is_prime = true;
        // loop to check if the current number is prime
        for (int j = 2 ; j * j <= i ; j++) {
            if (i % j == 0)
                is_prime = false;                
        }
        // if the current number is prime return it
        if (is_prime)
            return i;
    }
    // return the given number
    return x;
}

// This function calculates the hash value of the given key with type string
int hash_function_str_complex(string key) {
    int res = 0;
    for (int i = 0 ; i < key.size() ; i++)
        res = (res + 37LL * key[i]) % capacity;
    return res;
}

// This function reinserts the elements in the hash table
void reinsert_items(node** temp, int old_capacity) {
    // loop on all items in the hash table to reinsert them again
    for (int i = 0 ; i < old_capacity ; i++) {
        // check if the current item empty
        if (head[i] == NULL)
            continue;
		// loop till insert all nodes 
		node* curr = head[i];
		while (curr != NULL) {
			// calculate the hash value of the given key
			int idx = hash_function_str_complex(curr->data);
			// insert the new element
			temp[idx] = insert_begin(temp[idx], curr->data);
			curr = curr->next;
		}
    }
}

// This function updates the capacity of the hash table
void reserve(int new_capacity) {
    // Initialize a new hash table with the new capacity
    node** temp = new node*[new_capacity];
    for (int i = 0 ; i < new_capacity ; i++)
        temp[i] = NULL;
    // store the old capacity to use it in reinserting the items
    int old_capacity = capacity;
    // set the current capacity of the hash table to be the new capacity
	capacity = new_capacity;
    // copy the elements in the current hash table to the new hash table
    reinsert_items(temp, old_capacity);
    // delete the old hash table
    for (int i = 0 ; i < old_capacity ; i++)
        delete_linked_list(head[i]);
	delete head;
    // set the temp hash table with new capacity to be the hash table
	head = temp;
}

// This function searches for an element in the hash table
bool search_item(string key) {
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // return whether the current position in the hash table contain the given key
    return search_node(head[idx], key);
}

// This function inserts an element in the hash table
void insert_item(string key) {
	// check if the given key exists or not 
    if (search_item(key) == true)
        return;
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // insert the new element
    head[idx] = insert_begin(head[idx], key);
	// update the size of the hash table
	n = n + 1;
    // check if we need to update the capacity of the hash table
    if (1.0 * n / capacity >= load_factor)
        reserve(get_next_prime(2 * capacity));
}

// This function deletes an element at the given index in the hash table
void delete_item(string key) {
	// check if the given key exists or not 
    if (search_item(key) == false)
        return;
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // delete the given key from it's list
    head[idx] = delete_node(head[idx], key);
	// update the size of the hash table
	n = n - 1;
    // check if we need to update the capacity of the min-heap
    if (n < capacity / 2)
        reserve(get_next_prime(capacity / 2));
}

// This function prints the contents of the hash table
void print_hash_table() {
    // loop to print the elements in the hash table
    for (int i = 0 ; i < capacity ; i++) {
        if (head[i] == NULL)
            continue;
        cout << "index " << i << ":\n";
        print_linked_list(head[i]);
    }
}

int main() {

	// Functionality Testing 

    capacity = 2;
    head = new node*[capacity];
	for (int i = 0 ; i < capacity ; i++)
		head[i] = NULL;

    cout << "Hash Table capacity: " << capacity << '\n';
    cout << "Hash Table size: " << n << '\n';
    cout << "----------------------------------------------------\n";

    for (char i = 'a' ; i <= 'm' ; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0 ; j < 75 ; j++) {
            insert_item(item);
            item += i;
        }

        cout << "Hash Table capacity: " << capacity << '\n';
        cout << "Hash Table size: " << n << '\n';
        cout << "----------------------------------------------------\n";
    }
	
    for (char i = 'a' ; i <= 'm' ; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0 ; j < 75 ; j++) {
            if (search_item(item) == false)
                cout << item << " not found\n";
            item += i;
        }
    }

	//print_hash_table();
    cout << "----------------------------------------------------\n";

    for (char i = 'a' ; i <= 'm' ; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0 ; j < 75 ; j++) {
            if (j < 10) {
                item += i;
                continue;
            }
            delete_item(item);
            item += i;
        }

        cout << "Hash Table capacity: " << capacity << '\n';
        cout << "Hash Table size: " << n << '\n';
        cout << "----------------------------------------------------\n";
    }

    for (char i = 'a' ; i <= 'm' ; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0 ; j < 10 ; j++) {
            if (search_item(item) == false)
                cout << item << " not found\n";
            item += i;
        }
    }

	//print_hash_table();
    cout << "----------------------------------------------------\n";

}
