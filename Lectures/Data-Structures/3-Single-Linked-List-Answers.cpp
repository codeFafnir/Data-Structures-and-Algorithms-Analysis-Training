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
// This function searches for a node in the linked list in iterative way
bool search_node_iterative(int key) {
	node* curr = head;
	while (curr != NULL) {
		if (curr->data == key)
			return true;
		curr = curr->next;
	}
	return false;
}
// This function search node of linked list in recursive way
bool search_node_recursive(node* curr, int key) {
    if (curr == NULL)
		return false;
    return (curr->data == key) || search_node_recursive(curr->next, key);
}
// This function prints the contents of the linked list in iterative way
void print_linked_list_iterative() {
    node* curr = head;
	while (curr != NULL) {
		cout << curr->data << ' ';
		curr = curr->next;
	}
}
// This function prints the contents of the linked list in recursive way
void print_linked_list_recursive(node* curr) {
    if (curr == NULL)
        return;
	cout << curr->data << ' ';
    print_linked_list_recursive(curr->next);
}
// This function prints length of linked list in iterative way
int get_length_iterative() {
	int length = 0;
	node* curr = head;
	while (curr != NULL) {
		curr = curr->next;
		length++;
	}
	return length;
}
// This function prints length of linked list in recursive way
int get_length_recursive(node* curr) {
    if (curr == NULL)
		return 0;
    return 1 + get_length_recursive(curr->next);
}
// This function inserts a value in a given index
void insert_at(int idx, int new_data) {
	int n = get_length_iterative();
	if (idx < 0 || idx > n)
		return;
	if (idx == 0) {
		insert_begin(new_data);
		return;
	}
	int i = 1;
	node* prev = head;
	while (i < idx) {
		prev = prev->next;
		i++;
	}
	insert_node(prev, new_data);
}
// This function deletes a node in a given index
void delete_at(int idx) {
	int n = get_length_iterative();
	if (idx < 0 || idx >= n)
		return;
	if (idx == 0) {
		delete_begin();
	    return;
    }    
    int i = 1;
    node* prev = head;
    while (i < idx) {
        prev = prev->next;
    	i++;
    }
    delete_node(prev);
}
// This function gets the node in a given index
node* at(int idx) {
	int n = get_length_iterative();
	if (idx < 0 || idx >= n)
    	return NULL;
    int i = 0;
    node* curr = head;
    while (i < idx) {
        curr = curr->next;
    	i++;
    }
    return curr;
}
// This function gets the middle node of the linked list
node* print_middle() {
	if (head == NULL)
		return NULL;
	// iterate by 2 pointer, slow iterator reach half and fast iterator reach end 
    node* slow_ptr = head;
    node* fast_ptr = head->next;
	while (fast_ptr != NULL && fast_ptr->next != NULL) {
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}
	return slow_ptr;
}
// This function prints linked list nodes in reversed order
void print_linked_list_reverse(node* curr) {
    if (curr == NULL)
        return;
    print_linked_list_reverse(curr->next);
	cout << curr->data << ' ';
}
// This function deletes all nodes in the linked list in iterative way
void delete_list_iterative() {
	node* curr = head;
	while (curr != NULL) {
		head = head->next;
		delete(curr);
		curr = head;
	}
}
// This function deletes all nodes in the linked list in recursive way
void delete_list_recursive(node* curr) {
	if (curr == NULL)
		return;
	delete_list_recursive(curr->next);
	delete(curr);
}
// This function reverses the linked list
void reverse() {
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;
    while (curr != NULL) {
        next = curr->next;  
        curr->next = prev;
		// move the prev and curr nodes
        prev = curr;
        curr = next;
    }
    head = prev;
}
// This function prints number of time that node occurs in linked list in iterative way
int count_key_iterative(int key) {
	int cnt = 0;
	node* curr = head;
	while (curr != NULL) {
	    if (curr->data == key)
    		cnt++;
		curr = curr->next;
	}
	return cnt;
}
// This function prints number of time that node occurs in linked list in recursive way
int count_key_recursive(node *curr, int key) {
    if (curr == NULL)
        return 0;
    return (curr->data == key) + count_key_recursive(curr->next, key);
}
// This function removes duplication in the linked list
void remove_duplication() {
    if (head == NULL)
        return;
    // first iterator 
    node* curr1 = head;
    while (curr1->next != NULL) {
        // second iterator
        node* curr2 = curr1->next;
        // previous of second iterator
        node* prev2 = curr1;
        while (curr2 !=  NULL) {
            // check if it is a duplication
            if (curr2->data == curr1->data) {
                delete_node(prev2);
                curr2 = prev2;
            }
            // move previous and current of second iterator
            prev2 = curr2;
            curr2 = curr2->next;
        }
        if (curr1->next != NULL)
            curr1 = curr1->next;
    }
}
// This function delects loops in the linked list
bool detect_loop() {
    node* slow_ptr = head;
    node* fast_ptr = head;
    while (fast_ptr && fast_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr)
			return true;
    }
    return false;
}
// This function counts the nodes present in loop
int count_nodes(node* curr) {
    int res = 1;  
    node* temp = curr;
    while (temp->next != curr) {  
        res++;
        temp = temp->next;
    }
    return res;  
}
// This function detects and counts loop nodes in the linked list
int loop_length() {  
    node* slow_ptr = head;
    node* fast_ptr = head;
    while (fast_ptr && fast_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr)
            return count_nodes(slow_ptr);  
    }  
    return 0;  
}
// This function swaps 2 nodes by their indices
void swap_nodes(int i, int j) {
	if (i == j)
		return;
	int n = get_length_iterative();
	if (i < 0 || i >= n)
		return;
	if (j < 0 || j >= n)
		return;
	// search for x (keep track of prevX and currX
	node* prev1 = at(i-1);
	node* curr1 = at(i);
   	// search for y (keep track of prevY and currY
	node* prev2 = at(j-1);
	node* curr2 = at(j);
	// if either x or y is not present, nothing to do
   	if (curr1 == NULL || curr2 == NULL)
   		return;
	// if x is not head of linked list
   	if (prev1 != NULL)
       	prev1->next = curr2;
   	// else make y as new head
    else 
   	   	head = curr2;
   	// if y is not head of linked list
   	if (prev2 != NULL)
       	prev2->next = curr1;
   	// else make x as new head
    else 
   	   	head = curr1;
   	// swap next pointers
   	node* temp = curr2->next;
   	curr2->next = curr1->next;
   	curr1->next  = temp;
}

int main() {

	for (int i = 10 ; i <= 40 ; i+=10)
		insert_end(i);
	cout << "linked list length : " << get_length_iterative() << '\n';
    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "---------------------------------------\n";

	for (int i = 5 ; i <= 35 ; i+=10)
		insert_begin(i);
	cout << "linked list length : " << get_length_recursive(head) << '\n';
    cout << "linked list items : \n";
	print_linked_list_recursive(head);
    cout << "\n";
    cout << "---------------------------------------\n";
		
	for (int i = 0 ; i < 5 ; i++) {
        cout << "add element " << i*5+70 << " at position " << i << "\n";
		insert_at(i, i*5+70);
        cout << "linked list items : \n";
        print_linked_list_iterative();
        cout << "\n";
	}
    cout << "---------------------------------------\n";
	
	for (int i = 3 ; i < 8 ; i++) {
        cout << "delete element at position " << i << "\n";
		delete_at(i);
        cout << "linked list items : \n";
        print_linked_list_iterative();
        cout << "\n";
	}
    cout << "---------------------------------------\n";

	if (search_node_iterative(90))
		cout << "element " << 90 << " Found\n";
	else
		cout << "element " << 90 << " Not Found\n";
	if (search_node_iterative(95))
		cout << "element " << 95 << " Found\n";
	else
		cout << "element " << 95 << " Not Found\n";
	if (search_node_recursive(head, 80))
		cout << "element " << 80 << " Found\n";
	else
		cout << "element " << 80 << " Not Found\n";	
	if (search_node_recursive(head, 85))
		cout << "element " << 85 << " Found\n";
	else
		cout << "element " << 85 << " Not Found\n";
    cout << "---------------------------------------\n";

    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "---------------------------------------\n";

    cout << "add element " << 30 << " at position " << 3 << "\n";
    insert_at(3, 30);
    cout << "add element " << 30 << " at position " << 5 << "\n";
    insert_at(5, 30);
    cout << "add element " << 80 << " at position " << 7 << "\n";
    insert_at(7, 80);
    cout << "add element " << 80 << " at position " << 8 << "\n";
    insert_at(8, 80);
    cout << "---------------------------------------\n";

    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "---------------------------------------\n";

    cout << "number of time 30 occurs is : ";
    cout << count_key_iterative(30) << '\n';
    cout << "number of time 80 occurs is : ";
    cout << count_key_recursive(head, 80) << '\n';
    cout << "number of time 10 occurs is : ";
    cout << count_key_iterative(10) << '\n';
    cout << "number of time 40 occurs is : ";
    cout << count_key_recursive(head, 40) << '\n';
    cout << "---------------------------------------\n";

    cout << "reverse linked list\n";
	reverse();
    cout << "linked list items : \n";
	print_linked_list_recursive(head);
    cout << "\n";
    cout << "---------------------------------------\n";

    cout << "remove duplication in linked list\n";
    remove_duplication();    
    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "---------------------------------------\n";

    cout << "linked list nodes : \n";
    int n = get_length_recursive(head);
	for (int i = 0 ; i < n ; i++)
		cout << at(i)->data << ' ';
    cout << "\n";
    cout << "---------------------------------------\n";

    cout << "linked list in reversed order :\n";
    print_linked_list_reverse(head);
    cout << "\n";
    cout << "---------------------------------------\n";

	for (int i = 2 ; i < 6 ; i++) {
        cout << "delete element at position " << i << "\n";
		delete_at(i);
        cout << "linked list items : \n";
        print_linked_list_iterative();
        cout << "\n";
	}
    cout << "---------------------------------------\n";

    cout << "is the linked list has a loop : " << detect_loop() << '\n';
    cout << "the length of the deteced loop is : " << loop_length() << '\n';
    cout << "---------------------------------------\n";

    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "the middle item is : " << print_middle()->data << '\n';
    cout << "---------------------------------------\n";
    cout << "delete the last item\n";
    delete_end();
    cout << "---------------------------------------\n";
    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "the middle item is : " << print_middle()->data << '\n';
    cout << "---------------------------------------\n";

    cout << "update the 3 items to be 30\n";
    at(0)->data = 30;
    at(1)->data = 30;
    at(2)->data = 30;
    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "---------------------------------------\n";

    cout << "remove duplication in linked list\n";
    remove_duplication();    
    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "---------------------------------------\n";

	for (int i = 10 ; i <= 40 ; i+=10)
		insert_end(i);
	cout << "linked list length : " << get_length_iterative() << '\n';
    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "---------------------------------------\n";

    cout << "delete all nodes in the linked list\n";
    delete_list_iterative();
	cout << "linked list length : " << get_length_iterative() << '\n';
    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "---------------------------------------\n";

	for (int i = 10 ; i <= 40 ; i+=10)
		insert_end(i);
	cout << "linked list length : " << get_length_iterative() << '\n';
    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "---------------------------------------\n";

    cout << "delete all nodes in the linked list\n";
    delete_list_recursive(head);
    head = NULL;
	cout << "linked list length : " << get_length_recursive(head) << '\n';
    cout << "linked list items : \n";
	print_linked_list_recursive(head);
    cout << "\n";
    cout << "---------------------------------------\n";

	for (int i = 10 ; i <= 40 ; i+=10)
		insert_end(i);
	cout << "linked list length : " << get_length_iterative() << '\n';
    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "---------------------------------------\n";

	for (int i = 5 ; i <= 35 ; i+=10)
		insert_begin(i);
	cout << "linked list length : " << get_length_recursive(head) << '\n';
    cout << "linked list items : \n";
	print_linked_list_recursive(head);
    cout << "\n";
    cout << "---------------------------------------\n";
	
    cout << "swap node 2 and 5 in linked list\n";
    swap_nodes(2, 5);
    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "---------------------------------------\n";

    cout << "swap node 0 and 5 in linked list\n";
    swap_nodes(0, 5);
    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "---------------------------------------\n";

    cout << "swap node 2 and 7 in linked list\n";
    swap_nodes(2, 7);
    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "---------------------------------------\n";

    cout << "swap node 0 and 7 in linked list\n";
    swap_nodes(0, 7);
    cout << "linked list items : \n";
	print_linked_list_iterative();
    cout << "\n";
    cout << "---------------------------------------\n";

    cout << "connect the last node with the third node to create a cycle\n";
    at(7)->next = at(2);
    cout << "is the linked list has a loop : " << detect_loop() << '\n';
    cout << "the length of the deteced loop is : " << loop_length() << '\n';
    cout << "---------------------------------------\n";

}
