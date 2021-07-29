#include <bits/stdc++.h>
using namespace std;

// A binary search tree node
struct node {
	int data;
	node* left;
	node* right;
};

// Initialize a global pointer for root
node* root;

// This function do inorder traversal of the binary search tree
void inOrder(node* curr) {
	// base case we reach a null node
    if (curr == NULL)
    	return;
	// repeat the same definition of inorder traversal
	inOrder(curr->left);
	cout << curr->data << ' ';
	inOrder(curr->right);
}

// This function do preorder traversal of the binary search tree
void preOrder(node* curr) {
	// base case we reach a null node
    if (curr == NULL)
    	return;
	// repeat the same definition of preOrder traversal
	cout << curr->data << ' ';
	preOrder(curr->left);
	preOrder(curr->right);
}

// This function do postorder traversal of the binary search tree
void postOrder(node* curr) {
	// base case we reach a null node
    if (curr == NULL)
    	return;
	// repeat the same definition of postorder traversal
	postOrder(curr->left);
	postOrder(curr->right);
	cout << curr->data << ' ';
}

// This function searches if the given data in the binary search tree
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

// This function inserts a new node with given key in the binary search tree
node* insert_node(node* curr, int new_data) {
	// base case we reach a null node
    if (curr == NULL) {
		curr = new node();
		curr->data = new_data;
		return curr;
    }
	// repeat the same definition of insert at left or right subtrees
    if (new_data < curr->data)
		curr->left = insert_node(curr->left, new_data);
    else if (new_data > curr->data)
		curr->right = insert_node(curr->right, new_data);
	// return the unchanged node pointer
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

// This function deletes the given data in the binary search tree if exists
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
            delete(curr);
            return NULL;
        }
        // node with only one child
        else if (curr->left == NULL) {
            node* temp = curr->right;
            delete(curr);
            return temp;
        }
        // node with only one child
        else if (curr->right == NULL) {
            node* temp = curr->left;
            delete(curr);
            return temp;
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
	// return the unchanged node pointer
    return curr;
}

// This function traverses the binary search tree in postorder to delete all nodes
void delete_tree(node* curr) {
	// base case we reach a null node
	if (curr == NULL)
    	return;
	// repeat the same definition of postorder traversal
    delete_tree(curr->left);
    delete_tree(curr->right);
    delete(curr);
}

int main() {

	// Functionality Testing 
	
    // first level of the binary search tree (root only)
	root = insert_node(root, 100);

	cout << "Binary Search Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "Binary Search Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "Binary Search Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	Binary Search Tree in-order   : 100 
	Binary Search Tree pre-order  : 100 
	Binary Search Tree post-order : 100 
	----------------------------------------------------
	*/

    // second level of the binary search tree
	root = insert_node(root, 50);
	root = insert_node(root, 150);

	cout << "Binary Search Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "Binary Search Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "Binary Search Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	Binary Search Tree in-order   : 50 100 150 
	Binary Search Tree pre-order  : 100 50 150 
	Binary Search Tree post-order : 50 150 100 
	----------------------------------------------------
	*/

    // third level of the binary search tree
	root = insert_node(root, 25);
	root = insert_node(root, 75);
	root = insert_node(root, 125);
	root = insert_node(root, 175);
    
	cout << "Binary Search Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "Binary Search Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "Binary Search Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	Binary Search Tree in-order   : 25 50 75 100 125 150 175 
	Binary Search Tree pre-order  : 100 50 25 75 150 125 175 
	Binary Search Tree post-order : 25 75 50 125 175 150 100 
	----------------------------------------------------
	*/

/*	Tree Diagram
            100
          /     \
        50       150
       /  \     /   \
     25    75 125   175
*/

    cout << "deleting node 100 \n";
    root = delete_node(root, 100);

/*	Tree Diagram
            125
          /     \
        50       150
       /  \         \
     25    75       175
*/

	cout << "Binary Search Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "Binary Search Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "Binary Search Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output
	deleting node 100 
	Binary Search Tree in-order   : 25 50 75 125 150 175 
	Binary Search Tree pre-order  : 125 50 25 75 150 175 
	Binary Search Tree post-order : 25 75 50 175 150 125 
	----------------------------------------------------
	*/

	if (search(root, 150))
		cout << "element " << 150 << " in the tree\n";
	else
		cout << "element " << 150 << " not in the tree\n";

	if (search(root, 100))
		cout << "element " << 100 << " in the tree\n";
	else
		cout << "element " << 100 << " not in the tree\n";

	if (search(root, 75))
		cout << "element " << 75 << " in the tree\n";
	else
		cout << "element " << 75 << " not in the tree\n";

	if (search(root, 95))
		cout << "element " << 95 << " in the tree\n";
	else
		cout << "element " << 95 << " not in the tree\n";
    cout << "----------------------------------------------------\n";

	/* Expected Output
	element 150 in the tree
	element 100 not in the tree
	element 75 in the tree
	element 95 not in the tree
	----------------------------------------------------
	*/

    cout << "adding the following elements 135 80 130\n";
	root = insert_node(root, 135);
	root = insert_node(root, 80);
	root = insert_node(root, 130);
/*	Tree Diagram
              125
          /         \
        50          150
       /  \        /   \
     25    75    135   175
             \   /
			 80 130
*/
	cout << "Binary Search Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "Binary Search Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "Binary Search Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";
	/* Expected Output
	adding the following elements 135 80 130
	Binary Search Tree in-order   : 25 50 75 80 125 130 135 150 175 
	Binary Search Tree pre-order  : 125 50 25 75 80 150 135 130 175 
	Binary Search Tree post-order : 25 80 75 50 130 135 175 150 125 
	----------------------------------------------------
	*/

    cout << "The minimum value in the tree of root 125 is: ";
    cout << min_node(root)->data << '\n';
    cout << "The maximum value in the tree of root 125 is: ";
    cout << max_node(root)->data << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output
	The minimum value in the tree of root 125 is: 25
	The maximum value in the tree of root 125 is: 175
	----------------------------------------------------
	*/

    cout << "The minimum value in the tree of root 50  is: ";
    cout << min_node(root->left)->data << '\n';
    cout << "The maximum value in the tree of root 50  is: ";
    cout << max_node(root->left)->data << '\n';
    cout << "The minimum value in the tree of root 150 is: ";
    cout << min_node(root->right)->data << '\n';
    cout << "The maximum value in the tree of root 150 is: ";
    cout << max_node(root->right)->data << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output
	The minimum value in the tree of root 50  is: 25
	The maximum value in the tree of root 50  is: 80
	The minimum value in the tree of root 150 is: 130
	The maximum value in the tree of root 150 is: 175
	----------------------------------------------------
	*/

    delete_tree(root);
    root = NULL;

	cout << "Binary Search Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "Binary Search Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "Binary Search Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output
	Binary Search Tree in-order   : 
	Binary Search Tree pre-order  : 
	Binary Search Tree post-order : 
	----------------------------------------------------
	*/

}

