#include <bits/stdc++.h>
using namespace std;

// AVL tree node
struct node {
	int data;
	node* left;
	node* right;
	int height;
};

// Initialize a global pointer for root
node* root;

// This function do inorder traversal of the AVL tree in recursive way
void inOrder_recursive(node* curr) {
	// base case we reach a null node
    if (curr == NULL)
    	return;
	// repeat the same definition of inorder traversal
	inOrder_recursive(curr->left);
	cout << curr->data << ' ';
	inOrder_recursive(curr->right);
}
// This function do inorder traversal of the AVL tree in iterative way
void inOrder_iterative() {
    if (root == NULL)
        return;
    stack<node*> stk;
    node* curr = root;
    while (curr != NULL || !stk.empty()) {
        while (curr !=  NULL) {
            stk.push(curr); 
            curr = curr->left; 
        }
        curr = stk.top();
        stk.pop();
        cout << curr->data << ' ';
        curr = curr->right;  
    }
}
// This function do preorder traversal of the AVL tree in recursive way
void preOrder_recursive(node* curr) {
	// base case we reach a null node
    if (curr == NULL)
    	return;
	// repeat the same definition of preOrder traversal
	cout << curr->data << ' ';
	preOrder_recursive(curr->left);
	preOrder_recursive(curr->right);
}
// This function do preorder traversal of the AVL tree in iterative way
void preOrder_iterative() {
    if (root == NULL)
        return;
    stack<node*> stk;
    node* curr = root;
	stk.push(root);
    while (!stk.empty()) {
		node *curr = stk.top();
		stk.pop();
        cout << curr->data << ' ';
		if (curr->right)
			stk.push(curr->right);
		if (curr->left)
			stk.push(curr->left);
	}
}
// This function do postorder traversal of the AVL tree in recursive way
void postOrder_recursive(node* curr) {
	// base case we reach a null node
    if (curr == NULL)
    	return;
	// repeat the same definition of postorder traversal
	postOrder_recursive(curr->left);
	postOrder_recursive(curr->right);
	cout << curr->data << ' ';
}
// This function do postorder traversal of the AVL tree in iterative way
void postOrder_iterative() {
    if (root == NULL)
        return;
    stack<node*> stk, res;
    node* curr = root;
	stk.push(root);
    while (!stk.empty()) {
		node *curr = stk.top();
		stk.pop();
        res.push(curr);
		if (curr->left)
			stk.push(curr->left);
		if (curr->right)
			stk.push(curr->right);
	}
    while (!res.empty()) {
    	cout << res.top()->data << ' ';
        res.pop();
    }
}
// This function do breadth first traversal of the AVL tree
void bfs() {
    if (root == NULL)
        return;
	queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        // dequeue the front node and make it curr
        node* curr = q.front();
        q.pop();
        cout << curr->data << ' ';
        // enqueue the left child
        if (curr->left != NULL)
        	q.push(curr->left);
        // enqueue the right child
        if (curr->right != NULL)
        	q.push(curr->right);
    }
}
// This function do level order traversal line by line in a AVL tree
void print_level_order_lines() {
    if (root == NULL)
    	return;
    queue<node*> q;
    q.push(root);
    // cnt_node (queue size) indicates number of nodes at current level
    int cnt_node = q.size();
    while (cnt_node > 0) {
        // Dequeue all nodes of current level and Enqueue all nodes of next level
        while (cnt_node > 0) {
            node* curr = q.front();
            cout << curr->data << ' ';
            q.pop();
            if (curr->left  != NULL) 
				q.push(curr->left);
            if (curr->right != NULL) 
				q.push(curr->right);
            cnt_node--;
        }
        cout << "\n";
        cnt_node = q.size();
    }
}
// Recursive helper function given a node, and an array containing 
// the path from the root node up to but not including this node, 
// print out all the root-leaf paths
void print_paths_recursion(node* curr, vector<int> path) {
	if (curr == NULL)
		return;
	// append this node to the path array
	path.push_back(curr->data);
	// it's a leaf, so print the path that led to here
	if (curr->left == NULL && curr->right == NULL) {
        // condition that prints out an array on a line
    	for (int i = 0; i < path.size(); i++)
    		cout << path[i] << ' ';
    	cout << "\n";
	}
  	else {
		print_paths_recursion(curr->left, path);
    	print_paths_recursion(curr->right, path);
  	}
}
// This function prints out all of its root-to-leaf paths, one per line.
void print_paths() {
	vector<int> path;
	print_paths_recursion(root, path);
}
// This function searches if the given data in the AVL tree
bool search(node* curr, int data) {
	// base case we reach a null node
	if (curr == NULL)
		return false;
	// check if we find the data at the curr node
	if (curr->data == data)
		return true;
	// repeat the same definition of search at left or right subtrees
    if (data < curr->data)
        return search(curr->left, data);
    else
        return search(curr->right, data);
}
// This function computes the height of a tree, Height is the number of nodes 
// along the longest path from the root down to the farthest leaf node
int height(node* curr) {
	// base case we reach a null node
	if (curr == NULL)
		return 0;
	// return height of root of this subtree
    return curr->height;
}
// This function computes right rotate subtree rooted with y
node* right_rotate(node* y) {
    // check if the given node and it's left branch are NULLs
    if (y == NULL || y->left == NULL)
        return NULL;
    // constract x and T2 pointers (check slides)
    node* x  = y->left;
    node* T2 = x->right;    
    // perform rotation
    x->right = y;
    y->left  = T2;
    // update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    // return new root
    return x;
}
// This function computes left rotate subtree rooted with x
node* left_rotate(node* x) {
    // check if the given node and it's left branch are NULLs
    if (x == NULL || x->right == NULL)
        return NULL;
    // constract y and T2 pointers (check slides)
    node* y  = x->right;
    node* T2 = y->left;
    // perform rotation
    y->left  = x;
    x->right = T2;
    // update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    // return new root
    return y;
}
// This function calculates the balance factor of the given node
int calc_balance_factor(node* curr) {
	// base case we reach a null node
    if (curr == NULL)
        return 0;
	// return the difference between the height of left and right subtrees
    return height(curr->left) - height(curr->right);
}
// This function inserts a new node with given key in the AVL tree
node* insert_node(node* curr, int new_data) {
	// base case we reach a null node
    if (curr == NULL) {
        node* new_node = new node();
        new_node->data = new_data;
        new_node->height = 1;
        return new_node;
    }
	// repeat the same definition of insert at left or right subtrees
    if (new_data < curr->data)
        curr->left  = insert_node(curr->left, new_data);
    else if (new_data > curr->data)
        curr->right = insert_node(curr->right, new_data);
    // duplicate keys are not allowed in the AVL
    else
        return curr;
 
    // update the height of this curr node
    curr->height = 1 + max(height(curr->left), height(curr->right));
    // get the balance factor of this curr node 
    // to check whether this node became unbalanced
    int balance = calc_balance_factor(curr);
    // If this node becomes unbalanced, then there are 4 cases
    // case I: left left case
    if (balance > 1 && new_data < curr->left->data)
        return right_rotate(curr);
    // case II: right right case
    if (balance < -1 && new_data > curr->right->data)
        return left_rotate(curr);
    // case III: left right case
    if (balance > 1 && new_data > curr->left->data) {
        curr->left =  left_rotate(curr->left);
        return right_rotate(curr);
    }
    // case IV: right left case
    if (balance < -1 && new_data < curr->right->data) {
        curr->right = right_rotate(curr->right);
        return left_rotate(curr);
    }
    // return the (unchanged) node pointer
    return curr;
}
// This function returns the node with minimum value found in the given tree
node* min_node(node* curr) {
    node* res = curr;
    // loop down to find the leftmost leaf
    while (res->left != NULL)
        res = res->left;
	// return the nearest data node of curr data node 
    return res;
}
// This function returns the node with maximum value found in the given tree
node* max_node(node* curr) {
    node* res = curr;
    // loop down to find the rightmost leaf
    while (res->right != NULL)
        res = res->right;
	// return the nearest data node of curr data node 
    return res;
}
// This function deletes the given data in the AVL tree if exists
node* delete_node(node* curr, int data) {
	// base case we reach a null node
    if (curr == NULL)
    	return curr;
	// repeat the same definition of insert at left or right subtrees
    if (data < curr->data)
        curr->left = delete_node(curr->left, data); 
    else if (data > curr->data)
        curr->right = delete_node(curr->right, data); 
    // if the given data is same as curr's data, then we will delete this node
    else {
        // node with no child
        if (curr->left == NULL && curr->right == NULL) {
            node* temp = curr;
            curr = NULL;
            delete(temp);
        }
        // node with only one child
        else if (curr->left == NULL) {
            node* temp = curr->right;
            curr = temp;
            delete(temp);
        }
        // node with only one child
        else if (curr->right == NULL) {
            node* temp = curr->left;
            curr = temp;
            delete(temp);
        }
        // node with two children
        else {
            // get the inorder successor (smallest in the right subtree)
            node* temp = min_node(curr->right);
            // copy the inorder successor's content to this node
            curr->data = temp->data;
            // delete the inorder successor
            curr->right = delete_node(curr->right, temp->data);
        }
    }

    // return curr node if the tree had only one node
    if (curr == NULL)
        return curr;
    // update the height of this curr node
    curr->height = 1 + max(height(curr->left), height(curr->right));
    // get the balance factor of this curr node 
    // to check whether this node became unbalanced
    int balance = calc_balance_factor(curr);
    // If this node becomes unbalanced, then there are 4 cases
    // case I: left left case
    if (balance > 1 && calc_balance_factor(curr->left) >= 0) 
        return right_rotate(curr); 
    // case II: right right case
    if (balance < -1 && calc_balance_factor(curr->right) <= 0) 
        return left_rotate(curr); 
    // case III: left right case
    if (balance > 1 && calc_balance_factor(curr->left) < 0) { 
        curr->left =  left_rotate(curr->left); 
        return right_rotate(curr); 
    }
    // case IV: right left case
    if (balance < -1 && calc_balance_factor(curr->right) > 0) { 
        curr->right = right_rotate(curr->right); 
        return left_rotate(curr); 
    } 
    // return the (unchanged) node pointer
    return curr;
}
// This function traverses the AVL tree in postorder to delete all nodes
void delete_tree(node* curr) {
	if (curr == NULL)
    	return;
    delete_tree(curr->left);
    delete_tree(curr->right);
    delete(curr);
}
// This function returns pointer to LCA of two given values n1 and n2 in a BST
node* find_LCA(node* curr, int n1, int n2) {
	if (curr == NULL)
		return NULL;
    if (curr->data > n1 && curr->data > n2)
        return find_LCA(curr->left, n1, n2);
    if (curr->data < n1 && curr->data < n2)
        return find_LCA(curr->right, n1, n2);
    return curr;
}
// This function traverses all types in the binary tree
void traverse_all_types() {
	cout << "Binary Tree in-order traversal    : ";
    inOrder_recursive(root);
    cout << "\n";
	cout << "Binary Tree in-order traversal    : ";
    inOrder_iterative();
    cout << "\n";
	cout << "Binary Tree pre-order traversal   : ";
    preOrder_recursive(root);
    cout << "\n";
	cout << "Binary Tree pre-order traversal   : ";
    preOrder_iterative();
    cout << "\n";
	cout << "Binary Tree post-order traversal  : ";
    postOrder_recursive(root);
    cout << "\n";
	cout << "Binary Tree post-order traversal  : ";
    postOrder_iterative();
    cout << "\n";
    cout << "Binary Tree level-order traversal : ";
	bfs();
	cout << "\n";
	cout << "Binary Tree paths traversal : \n";
	print_paths();
	cout << "Binary Tree level order lines traversal : \n";
    print_level_order_lines();
}

int main() {
	
	// level 1
	root = insert_node(root, 100);
	// level 2
	root = insert_node(root, 50);
	root = insert_node(root, 150);
	// level 3
	root = insert_node(root, 25);
	root = insert_node(root, 75);
	root = insert_node(root, 125);
	root = insert_node(root, 175);

    traverse_all_types();
    cout << "----------------------------------------------------\n";

    root = delete_node(root, 100);
    cout << "delete node 100" << '\n';

    traverse_all_types();
    cout << "----------------------------------------------------\n";
    
	cout << "max value in BST is   : " << max_node(root)->data << "\n";
	cout << "min value in BST is   : " << min_node(root)->data << "\n";    

	root = insert_node(root, 135);
	root = insert_node(root, 80);
	root = insert_node(root, 130);

    traverse_all_types();
    cout << "----------------------------------------------------\n";
    
    cout << "LCA of 25, 75   is : " << find_LCA(root, 25, 75 )->data << "\n";
    cout << "LCA of 135, 175 is : " << find_LCA(root, 135, 175)->data << "\n";
    cout << "LCA of 25, 80   is : " << find_LCA(root, 25, 80 )->data << "\n";
    cout << "LCA of 130, 175 is : " << find_LCA(root, 130, 175)->data << "\n";
    cout << "LCA of 80, 50   is : " << find_LCA(root, 80, 50 )->data << "\n";
    cout << "LCA of 130,150  is : " << find_LCA(root, 130, 150)->data << "\n";
    cout << "LCA of 25, 175  is : " << find_LCA(root, 25, 175)->data << "\n";
    cout << "LCA of 80, 130  is : " << find_LCA(root, 80, 130)->data << "\n";

	delete_tree(root);
    root = NULL;

}
