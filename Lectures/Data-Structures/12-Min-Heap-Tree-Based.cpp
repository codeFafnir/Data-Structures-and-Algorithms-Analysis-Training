#include <bits/stdc++.h>
using namespace std;

// A binary heap node
struct node {
	int data;
	node* left;
	node* right;
	node* parent;
};

// Initialize a global pointer for root and size of the heap
node* root;
int n;

// This function gets the node based on the index
node* get_parent_node(node* curr, int idx, int target, int level) {
	// base case we reach a null node
	if (curr == NULL)
		return NULL;
	// return the target node
	if (target == 2*idx+1 || target == 2*idx+2)
		return curr;
	int child = (target - (1<<level) + 1) / (1<<level);
	// repeat the same definition of get node at left or right subtrees
	if (child == 2*idx+1)
		return get_parent_node(curr->left, child, target, level-1);
	if (child == 2*idx+2)
		return get_parent_node(curr->right, child, target, level-1);
	return NULL;
}

// This function inserts an element at the given index in the min-heap
void push(int item) {
	// update the size of the min-heap
	n = n + 1;
	// the first node in the heap tree
	if (n == 1) {
		node* new_node = new node();
		new_node->data = item;
		root = new_node;
		return;
	}
	// get the parent of the last node
	node* parent_last_node = get_parent_node(root, 0, n-1, log2(n)-1);
    // insert the new element
	node* new_node = new node();
	new_node->data = item;
	if (parent_last_node->left == NULL)
		parent_last_node->left = new_node;
	else
		parent_last_node->right = new_node;
	new_node->parent = parent_last_node;
	// loop to shif the values of the parents till the root of this path
	node* curr = new_node;
	while (curr != root && curr->parent->data > curr->data) {
		swap(curr->data, curr->parent->data);
        curr = curr->parent;
	}
}

// This function deletes an element at index idx in the min-heap
void pop() {
	// check if the min-heap is empty
	if (n == 0)
		return;
	// update the size of the min-heap
	n = n - 1;
	// the first node in the heap tree
	if (n == 0) {
		node* temp = root;
		delete(temp);
		root = NULL;
		return;
	}
	// get the last node
	node* parent_last_node = get_parent_node(root, 0, n, log2(n+1)-1);
    // delete the root of the min-heap by replace it with the last element
	if (parent_last_node->right != NULL) {
        swap(root->data, parent_last_node->right->data);
		node* temp = parent_last_node->right;
		delete(temp);
		parent_last_node->right = NULL;
	}
    else {
        swap(root->data, parent_last_node->left->data);
		node* temp = parent_last_node->left;
		delete(temp);
		parent_last_node->left = NULL;
	}
	// loop to shif the values of the parents till the root of this path
	node* curr = root;
	node* prev = NULL;
	while (curr != prev) {
        // store the prev index
		prev = curr;
        // get the left and right children
		node* left_child = curr->left;
		node* right_child = curr->right;
        // get the index of the minimum child
        if (left_child != NULL && left_child->data < curr->data)
            curr = left_child;
        if (right_child != NULL && right_child->data < curr->data)
            curr = right_child;
        // swap the old parent with the minimum child
        swap(prev->data, curr->data);
	}
}

// This function gets the value of the root in the min-heap
int get_root() {
	// check if the min-heap is empty 
	// to return the biggest integer value as an invalid value
	if (n == 0)
		return INT_MAX;
    // otherwise return the real value
    else
        return root->data;
}

int main() {

	// Functionality Testing
	
    cout << "Min-Heap root: " << get_root() << '\n';
	push(25);
    cout << "Min-Heap root: " << get_root() << '\n';
	push(30);
    cout << "Min-Heap root: " << get_root() << '\n';
	push(15);
    cout << "Min-Heap root: " << get_root() << '\n';
	push(20);
    cout << "Min-Heap root: " << get_root() << '\n';
	push(10);
    cout << "Min-Heap root: " << get_root() << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
    Min-Heap root: 2147483647
    Min-Heap root: 25
    Min-Heap root: 25
    Min-Heap root: 15
    Min-Heap root: 15
    Min-Heap root: 10
	----------------------------------------------------
	*/

	while (n > 0) {
		pop();
		cout << "Min-Heap root has been deleted and the current root is: ";
        cout << get_root() << '\n';
	}
	cout << "Min-Heap is empty now\n";
    cout << "----------------------------------------------------\n";

	/* Expected Output:
    Min-Heap root has been deleted and the current root is: 15
    Min-Heap root has been deleted and the current root is: 20
    Min-Heap root has been deleted and the current root is: 25
    Min-Heap root has been deleted and the current root is: 30
    Min-Heap root has been deleted and the current root is: 2147483647
	Min-Heap is empty now
	----------------------------------------------------
	*/

    for (int i = 16; i >= 1; i--) {
        push(i);
        cout << "Min-Heap root: " << get_root() << '\n';
    }
    cout << "----------------------------------------------------\n";

	/* Expected Output:
    Min-Heap root: 16
    Min-Heap root: 15
    Min-Heap root: 14
    Min-Heap root: 13
    Min-Heap root: 12
    Min-Heap root: 11
    Min-Heap root: 10
    Min-Heap root: 9
    Min-Heap root: 8
    Min-Heap root: 7
    Min-Heap root: 6
    Min-Heap root: 5
    Min-Heap root: 4
    Min-Heap root: 3
    Min-Heap root: 2
    Min-Heap root: 1
    ----------------------------------------------------
	*/

	while (n > 0) {
		pop();
		cout << "Min-Heap root has been deleted and the current root is: ";
        cout << get_root() << '\n';
	}
	cout << "Min-Heap is empty now\n";
    cout << "----------------------------------------------------\n";

	/* Expected Output:
    Min-Heap root has been deleted and the current root is: 2
    Min-Heap root has been deleted and the current root is: 3
    Min-Heap root has been deleted and the current root is: 4
    Min-Heap root has been deleted and the current root is: 5
    Min-Heap root has been deleted and the current root is: 6
    Min-Heap root has been deleted and the current root is: 7
    Min-Heap root has been deleted and the current root is: 8
    Min-Heap root has been deleted and the current root is: 9
    Min-Heap root has been deleted and the current root is: 10
    Min-Heap root has been deleted and the current root is: 11
    Min-Heap root has been deleted and the current root is: 12
    Min-Heap root has been deleted and the current root is: 13
    Min-Heap root has been deleted and the current root is: 14
    Min-Heap root has been deleted and the current root is: 15
    Min-Heap root has been deleted and the current root is: 16
    Min-Heap root has been deleted and the current root is: 2147483647
	Min-Heap is empty now
	----------------------------------------------------
	*/

}
