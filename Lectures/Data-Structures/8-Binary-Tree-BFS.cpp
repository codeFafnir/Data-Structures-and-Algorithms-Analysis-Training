#include <bits/stdc++.h>
using namespace std;

// A binary tree node
struct node {
	int data;
	node* left;
	node* right;
};

// Initialize a global pointer for root
node* root;

// This function do inorder traversal of the binary tree
void inOrder(node* curr) {
	// base case we reach a null node
    if (curr == NULL)
    	return;
	// repeat the same definition of inorder traversal
	inOrder(curr->left);
	cout << curr->data << ' ';
	inOrder(curr->right);
}

// This function do preorder traversal of the binary tree
void preOrder(node* curr) {
	// base case we reach a null node
    if (curr == NULL)
    	return;
	// repeat the same definition of preOrder traversal
	cout << curr->data << ' ';
	preOrder(curr->left);
	preOrder(curr->right);
}

// This function do postorder traversal of the binary tree
void postOrder(node* curr) {
	// base case we reach a null node
    if (curr == NULL)
    	return;
	// repeat the same definition of postorder traversal
	postOrder(curr->left);
	postOrder(curr->right);
	cout << curr->data << ' ';
}

// This function searches if the given data in the binary tree
bool search(node* curr, int data) {
	// base case we reach a null node
	if (curr == NULL)
		return false;
	// check if we find the data at the curr node
	if (curr->data == data)
		return true;
	// repeat the same definition of search at left and right subtrees
    bool left_search  = search(curr->left, data);
	bool right_search = search(curr->right, data);
	return left_search || right_search;
}

// This function traverses the binary tree in postorder to delete all nodes
void delete_tree(node* curr) {
	// base case we reach a null node
	if (curr == NULL)
    	return;
	// repeat the same definition of postorder traversal
    delete_tree(curr->left);
    delete_tree(curr->right);
    delete(curr);
}

// A queue node
struct q_node {
    node* data;
    q_node* prev;
    q_node* next;
};

// Initialize a global pointers for head and tail
q_node* head;
q_node* tail;

// This function adds a node at the begin of the queue
void push(node* new_data) {
    // allocate new node and put it's data
    q_node* new_node = new q_node();
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
    q_node* temp_node = head;
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
node* front() {
	// check if the queue is empty 
    // to return the biggest integer value as an invalid value
    if (head == NULL)
        return NULL;
    // otherwise return the real value
    else
        return head->data;
}

// This function returns the value of the last node in the queue
node* back() {
	// check if the queue is empty 
    // to return the biggest integer value as an invalid value
    if (tail == NULL)
        return NULL;
    // otherwise return the real value
    else
        return tail->data;
}

// This function do breadth first traversal of the binary tree
void bfs() {
    if (root == NULL)
        return;
	// starting with the root of the binary tree
    push(root);
    // iterate on the nodes till reach all node in the binary tree
    while (head != NULL) {
        // dequeue the front node and make it curr
        node* curr = front();
        pop();
        cout << curr->data << ' ';
        // enqueue the left child
        if (curr->left != NULL)
        	push(curr->left);
        // enqueue the right child
        if (curr->right != NULL)
        	push(curr->right);
    }
}

int main() {

	// Functionality Testing 
	
    // first level of the binary tree (root only)
	root = new node();
	root->data = 5;

	cout << "Binary Tree in-order traversal   : ";
    inOrder(root);
    cout << "\n";
	cout << "Binary Tree pre-order traversal  : ";
    preOrder(root);
    cout << "\n";
	cout << "Binary Tree post-order traversal : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	Binary Tree in-order traversal   : 5 
	Binary Tree pre-order traversal  : 5 
	Binary Tree post-order traversal : 5 
	----------------------------------------------------
	*/
	/*	Tree Diagram
				   5
	*/

    // second level of the binary tree
	root->left = new node();
	root->left->data = 7;
	root->right = new node();
	root->right->data = 11;

	cout << "Binary Tree in-order traversal   : ";
    inOrder(root);
    cout << "\n";
	cout << "Binary Tree pre-order traversal  : ";
    preOrder(root);
    cout << "\n";
	cout << "Binary Tree post-order traversal : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	Binary Tree in-order traversal   : 7 5 11 
	Binary Tree pre-order traversal  : 5 7 11 
	Binary Tree post-order traversal : 7 11 5 
	----------------------------------------------------
	*/
	/*	Tree Diagram
				   5
			  /         \
			 7           11
	*/

    // third level of the binary tree
	root->left->left = new node();
	root->left->left->data = 4;
	root->left->right = new node();
	root->left->right->data = 6;
	root->right->left = new node();
	root->right->left->data = 9;
	root->right->right = new node();
	root->right->right->data = 13;
    
	cout << "Binary Tree in-order traversal   : ";
    inOrder(root);
    cout << "\n";
	cout << "Binary Tree pre-order traversal  : ";
    preOrder(root);
    cout << "\n";
	cout << "Binary Tree post-order traversal : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	Binary Tree in-order traversal   : 4 7 6 5 9 11 13 
	Binary Tree pre-order traversal  : 5 7 4 6 11 9 13 
	Binary Tree post-order traversal : 4 6 7 9 13 11 5 
	----------------------------------------------------
	*/
	/*	Tree Diagram
				   5
			  /         \
			 7           11
		   /   \       /    \
		  4     6     9      13
	*/

	cout << "Binary Tree breadth first traversal : ";
    bfs();
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	Binary Tree breadth first traversal : 5 7 11 4 6 9 13 
	----------------------------------------------------
	*/
	
	if (search(root, 9))
		cout << "element " << 9 << " in the tree\n";
	else
		cout << "element " << 9 << " not in the tree\n";

	if (search(root, 4))
		cout << "element " << 4 << " in the tree\n";
	else
		cout << "element " << 4 << " not in the tree\n";

	if (search(root, 8))
		cout << "element " << 8 << " in the tree\n";
	else
		cout << "element " << 8 << " not in the tree\n";

	if (search(root, 3))
		cout << "element " << 3 << " in the tree\n";
	else
		cout << "element " << 3 << " not in the tree\n";
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	element 9 in the tree
	element 4 in the tree
	element 8 not in the tree
	element 3 not in the tree
	----------------------------------------------------
	*/

    delete_tree(root);
    root = NULL;

	cout << "Binary Tree in-order traversal   : ";
    inOrder(root);
    cout << "\n";
	cout << "Binary Tree pre-order traversal  : ";
    preOrder(root);
    cout << "\n";
	cout << "Binary Tree post-order traversal : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	Binary Tree in-order traversal   : 
	Binary Tree pre-order traversal  : 
	Binary Tree post-order traversal : 
	----------------------------------------------------
	*/

}
