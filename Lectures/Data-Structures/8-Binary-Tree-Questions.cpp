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

// This function do inorder traversal of the binary tree in recursive way
void inOrder_recursive(node* curr) {
    if (curr == NULL)
    	return;
	inOrder_recursive(curr->left);
	cout << curr->data << ' ';
	inOrder_recursive(curr->right);
}
// This function do inorder traversal of the binary tree in iterative way
void inOrder_iterative() {
	
}
// This function do preorder traversal of the binary tree in recursive way
void preOrder_recursive(node* curr) {
    if (curr == NULL)
    	return;
	cout << curr->data << ' ';
	preOrder_recursive(curr->left);
	preOrder_recursive(curr->right);
}
// This function do preorder traversal of the binary tree in iterative way
void preOrder_iterative() {

}
// This function do postorder traversal of the binary tree in recursive way
void postOrder_recursive(node* curr) {
    if (curr == NULL)
    	return;
	postOrder_recursive(curr->left);
	postOrder_recursive(curr->right);
	cout << curr->data << ' ';
}
// This function do postorder traversal of the binary tree in iterative way
void postOrder_iterative() {

}
// This function searches if the given data in the binary tree in recursive way
bool search_recursive(node* curr, int data) {

}
// This function searches if the given data in the binary tree in iterative way
bool search_iterative(int data) {

}
// This function traverses the binary tree in postorder to delete all nodes in recursive way
void delete_tree_recursive(node* curr) {

}
// This function traverses the binary tree in postorder to delete all nodes in iterative way
void delete_tree_iterative() {

}
// This function do breadth first traversal of the binary tree
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
// This function do level order traversal line by line in a binary tree
void print_level_order_lines() {

}
// Recursive helper function given a node, and an array containing 
// the path from the root node up to but not including this node, 
// print out all the root-leaf paths
void print_paths_recursion(node* curr, vector<int> path) {

}
// This function prints out all of its root-to-leaf paths, one per line.
void print_paths() {
	vector<int> path;
	print_paths_recursion(root, path);
}
// This function returns the maximum value in the binary tree in recursive way
int find_max_value_recursive(node* curr) {

}
// This function returns the maximum value in the binary tree in iterative way
int find_max_value_iterative() {

}
// This function returns the minimum value in the binary tree in recursive way
int find_min_value_recursive(node* curr) {

}
// This function returns the minimum value in the binary tree in iterative way
int find_min_value_iterative() {

}
// This function gets the maximum depth in the binary tree
int max_depth(node* curr) {

}
// This function gets the minimum depth in the binary tree
int min_depth(node* curr) {

}
// This function mirrors the binary tree
void mirror(node* curr) {

}
// This function counts the number of leaf nodes in a binary tree in recursive way
int count_leaf_recursive(node* curr) {

}
// This function counts the number of leaf nodes in a binary tree in iterative way
int count_leaf_iterative() {

}
// This function checks if node equal sum of it's child in a binary tree
bool is_sum_property(node* curr) {

}
// This function calculates the sum of the values in a binary tree
int sum(node* curr) {

}
// This function checks if sum property holds for the given node and both of its children in a binary tree
bool is_sum_tree(node* curr) {

}
// This function checks if there exist summation of path equal given sum in a binary tree
bool has_path_sum(node* curr, int sum) {

}
// This function gets the maximum sum of all paths in a binary tree
int max_path_sum(node* curr) {

}
// This function gets the minimum sum of all paths in a binary tree
int min_path_sum(node* curr) {

}
// This function replaces each node with the sum of its inorder predecessor and successor in a binary tree
int replace_node_with_sum(node* curr) {

}
// This function returns pointer to LCA of two given values n1 and n2 in a binary tree
node* find_LCA(node* curr, int n1, int n2) {

}
// This function traverses given tree in Inorder and prints all nodes that have both children in a binary tree
void find_full_nodes(node* curr) {

}
// This function computes the height of a binary tree
// Height is the number of nodes along the longest path from the root node down to the farthest leaf node
int height(node* curr) {

}
// This function gets diameter of a binary tree
int diameter(node* curr) {

}
// This function computes the number of nodes in a binary tree
int size(node* curr) {

}
// This function checks if the binary tree is complete or not
bool is_complete_tree(node* curr, int index, int tree_size) {

}
// This function checks if the binary tree is full or not
bool is_full_tree(node* curr) {

}
// This function checks if the binary tree is perfect or not
bool is_perfect_tree(node* curr, int max_depth, int curr_depth = 1) {

}
// This function checks if the binary tree is pathological or not
bool is_pathological_tree(node* curr) {

}
// This function checks if the binary tree is skewed or not for left side
bool is_skewed_tree_left(node* curr) {

}
// This function checks if the binary tree is skewed or not for right side
bool is_skewed_tree_right(node* curr) {

}
// This function checks if the binary tree is skewed or not
bool is_skewed_tree(node* curr) {

}
// This function checks if the binary tree is balanced or not
bool is_balanced_tree(node *curr) {

}
// This function checks if a binary tree is a binary search tree or not
bool is_BST(node *curr) {

}
// This function checks if a binary tree is a binary search tree or not
bool is_BST(node *curr, int min, int max) {

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

	/*	Tree Diagram
				   5
			  /         \
			 7           11
		   /   \       /    \
		  4     6     9      13
	*/

    // first level root only
	root = new node();
	root->data = 5;    
    // second level
	root->left = new node();
	root->left->data = 7;
	root->right = new node();
	root->right->data = 11;
    // third level
	root->left->left = new node();
	root->left->left->data = 4;
	root->left->right = new node();
	root->left->right->data = 6;
	root->right->left = new node();
	root->right->left->data = 9;
	root->right->right = new node();
	root->right->right->data = 13;

    traverse_all_types();
    cout << "----------------------------------------------------\n";
    
	cout << "nodes in binary tree is        : " << size(root) << "\n";
	cout << "max value in binary tree is    : " << find_max_value_recursive(root) << "\n";
	cout << "max value in binary tree is    : " << find_max_value_iterative() << "\n";
	cout << "min value in binary tree is    : " << find_min_value_recursive(root) << "\n";
	cout << "min value in binary tree is    : " << find_min_value_iterative() << "\n";
	cout << "max depth in binary tree is    : " << max_depth(root) << "\n";
	cout << "min depth in binary tree is    : " << min_depth(root) << "\n";
	cout << "diameter of binary tree is     : " << diameter(root) << "\n";
	cout << "leafs nodes in binary tree is  : " << count_leaf_recursive(root) << "\n";
	cout << "leafs nodes in binary tree is  : " << count_leaf_iterative() << "\n";
	cout << "full nodes in binary tree is   : "; 
    find_full_nodes(root);
    cout << "\n";
    cout << "----------------------------------------------------\n";
	
	cout << "is complete tree     : " << is_complete_tree(root, 0, size(root)) << "\n";
	cout << "is perfect tree      : " << is_perfect_tree(root, height(root)) << "\n";
	cout << "is full tree         : " << is_full_tree(root) << "\n";
	cout << "is pathological tree : " << is_pathological_tree(root) << "\n";
	cout << "is skewed tree       : " << is_skewed_tree(root) << "\n";
	cout << "is balanced tree     : " << is_balanced_tree(root) << "\n";
    cout << "----------------------------------------------------\n";

	cout << "max sum path in binary tree is : " << max_path_sum(root) << "\n";
	cout << "min sum path in binary tree is : " << min_path_sum(root) << "\n";
	cout << "is sum property binary tree    : " << is_sum_property(root) << "\n";
	cout << "is sum binary tree             : " << is_sum_tree(root) << "\n";
	cout << "has path sum 18 in binary tree : " << has_path_sum(root, 18) << "\n";
	cout << "has path sum 26 in binary tree : " << has_path_sum(root, 26) << "\n";
    cout << "----------------------------------------------------\n";

    cout << "replace nodes with sum of their children in Binary Tree: \n";
    root->data = replace_node_with_sum(root);

    traverse_all_types();
    cout << "----------------------------------------------------\n";

	cout << "max sum path in binary tree is : " << max_path_sum(root) << "\n";
	cout << "min sum path in binary tree is : " << min_path_sum(root) << "\n";
	cout << "is sum property binary tree    : " << is_sum_property(root) << "\n";
	cout << "is sum binary tree             : " << is_sum_tree(root) << "\n";
	cout << "has path sum 18 in binary tree : " << has_path_sum(root, 18) << "\n";
	cout << "has path sum 26 in binary tree : " << has_path_sum(root, 26) << "\n";
    cout << "----------------------------------------------------\n";
    
    cout << "search for 13 in binary tree : " << search_recursive(root, 13) << '\n';
    cout << "search for 13 in binary tree : " << search_iterative(13) << '\n';
    cout << "search for 6 in binary tree  : " << search_recursive(root, 6) << '\n';
    cout << "search for 6 in binary tree  : " << search_iterative(6) << '\n';
    cout << "----------------------------------------------------\n";

    cout << "delete all nodes in the binary tree\n";
    delete_tree_recursive(root);
    root = NULL;
    cout << "----------------------------------------------------\n";

	/*	Tree Diagram
				   5
			  /         \
			 7           11
		               /    \
		              9      13
	*/

    // first level root only
	root = new node();
	root->data = 5;    
    // second level
	root->left = new node();
	root->left->data = 7;
	root->right = new node();
	root->right->data = 11;
    // third level
	root->right->left = new node();
	root->right->left->data = 9;
	root->right->right = new node();
	root->right->right->data = 13;
    
    traverse_all_types();
    cout << "----------------------------------------------------\n";
    
	cout << "nodes in binary tree is        : " << size(root) << "\n";
	cout << "max value in binary tree is    : " << find_max_value_recursive(root) << "\n";
	cout << "max value in binary tree is    : " << find_max_value_iterative() << "\n";
	cout << "min value in binary tree is    : " << find_min_value_recursive(root) << "\n";
	cout << "min value in binary tree is    : " << find_min_value_iterative() << "\n";
	cout << "max depth in binary tree is    : " << max_depth(root) << "\n";
	cout << "min depth in binary tree is    : " << min_depth(root) << "\n";
	cout << "diameter of binary tree is     : " << diameter(root) << "\n";
	cout << "leafs nodes in binary tree is  : " << count_leaf_recursive(root) << "\n";
	cout << "leafs nodes in binary tree is  : " << count_leaf_iterative() << "\n";
	cout << "full nodes in binary tree is   : "; 
    find_full_nodes(root);
    cout << "\n";
    cout << "----------------------------------------------------\n";
	
	cout << "is complete tree     : " << is_complete_tree(root, 0, size(root)) << "\n";
	cout << "is perfect tree      : " << is_perfect_tree(root, height(root)) << "\n";
	cout << "is full tree         : " << is_full_tree(root) << "\n";
	cout << "is pathological tree : " << is_pathological_tree(root) << "\n";
	cout << "is skewed tree       : " << is_skewed_tree(root) << "\n";
	cout << "is balanced tree     : " << is_balanced_tree(root) << "\n";
    cout << "----------------------------------------------------\n";
    
    cout << "search for 13 in binary tree : " << search_recursive(root, 13) << '\n';
    cout << "search for 13 in binary tree : " << search_iterative(13) << '\n';
    cout << "search for 6 in binary tree  : " << search_recursive(root, 6) << '\n';
    cout << "search for 6 in binary tree  : " << search_iterative(6) << '\n';
    cout << "----------------------------------------------------\n";

    cout << "delete all nodes in the binary tree\n";
    delete_tree_iterative();
    root = NULL;
    cout << "----------------------------------------------------\n";

	/*	Tree Diagram
				   5
			  /         \
			 7           11
		   /   \           
		  4     6           
	*/

    // first level root only
	root = new node();
	root->data = 5;    
    // second level
	root->left = new node();
	root->left->data = 7;
	root->right = new node();
	root->right->data = 11;
    // third level
	root->left->left = new node();
	root->left->left->data = 4;
	root->left->right = new node();
	root->left->right->data = 6;
    
    traverse_all_types();
    cout << "----------------------------------------------------\n";
    
	cout << "nodes in binary tree is        : " << size(root) << "\n";
	cout << "max value in binary tree is    : " << find_max_value_recursive(root) << "\n";
	cout << "max value in binary tree is    : " << find_max_value_iterative() << "\n";
	cout << "min value in binary tree is    : " << find_min_value_recursive(root) << "\n";
	cout << "min value in binary tree is    : " << find_min_value_iterative() << "\n";
	cout << "max depth in binary tree is    : " << max_depth(root) << "\n";
	cout << "min depth in binary tree is    : " << min_depth(root) << "\n";
	cout << "diameter of binary tree is     : " << diameter(root) << "\n";
	cout << "leafs nodes in binary tree is  : " << count_leaf_recursive(root) << "\n";
	cout << "leafs nodes in binary tree is  : " << count_leaf_iterative() << "\n";
	cout << "full nodes in binary tree is   : "; 
    find_full_nodes(root);
    cout << "\n";
    cout << "----------------------------------------------------\n";
	
	cout << "is complete tree     : " << is_complete_tree(root, 0, size(root)) << "\n";
	cout << "is perfect tree      : " << is_perfect_tree(root, height(root)) << "\n";
	cout << "is full tree         : " << is_full_tree(root) << "\n";
	cout << "is pathological tree : " << is_pathological_tree(root) << "\n";
	cout << "is skewed tree       : " << is_skewed_tree(root) << "\n";
	cout << "is balanced tree     : " << is_balanced_tree(root) << "\n";
    cout << "----------------------------------------------------\n";
    
    cout << "search for 13 in binary tree : " << search_recursive(root, 13) << '\n';
    cout << "search for 13 in binary tree : " << search_iterative(13) << '\n';
    cout << "search for 6 in binary tree  : " << search_recursive(root, 6) << '\n';
    cout << "search for 6 in binary tree  : " << search_iterative(6) << '\n';
    cout << "----------------------------------------------------\n";

    cout << "delete all nodes in the binary tree\n";
    delete_tree_recursive(root);
    root = NULL;
    cout << "----------------------------------------------------\n";

	/*	Tree Diagram
				   5
			            \
			             11
		               /    
		              9      
	*/

    // first level root only
	root = new node();
	root->data = 5;    
    // second level
	root->right = new node();
	root->right->data = 11;
    // third level
	root->right->left = new node();
	root->right->left->data = 9;
    
    traverse_all_types();
    cout << "----------------------------------------------------\n";

    cout << "mirror the binary tree : \n";
    mirror(root);
    
    traverse_all_types();
    cout << "----------------------------------------------------\n";

	cout << "nodes in binary tree is        : " << size(root) << "\n";
	cout << "max value in binary tree is    : " << find_max_value_recursive(root) << "\n";
	cout << "max value in binary tree is    : " << find_max_value_iterative() << "\n";
	cout << "min value in binary tree is    : " << find_min_value_recursive(root) << "\n";
	cout << "min value in binary tree is    : " << find_min_value_iterative() << "\n";
	cout << "max depth in binary tree is    : " << max_depth(root) << "\n";
	cout << "min depth in binary tree is    : " << min_depth(root) << "\n";
	cout << "diameter of binary tree is     : " << diameter(root) << "\n";
	cout << "leafs nodes in binary tree is  : " << count_leaf_recursive(root) << "\n";
	cout << "leafs nodes in binary tree is  : " << count_leaf_iterative() << "\n";
	cout << "full nodes in binary tree is   : "; 
    find_full_nodes(root);
    cout << "\n";
    cout << "----------------------------------------------------\n";
	
	cout << "is complete tree     : " << is_complete_tree(root, 0, size(root)) << "\n";
	cout << "is perfect tree      : " << is_perfect_tree(root, height(root)) << "\n";
	cout << "is full tree         : " << is_full_tree(root) << "\n";
	cout << "is pathological tree : " << is_pathological_tree(root) << "\n";
	cout << "is skewed tree       : " << is_skewed_tree(root) << "\n";
	cout << "is balanced tree     : " << is_balanced_tree(root) << "\n";
    cout << "----------------------------------------------------\n";
    
    cout << "search for 13 in binary tree : " << search_recursive(root, 13) << '\n';
    cout << "search for 13 in binary tree : " << search_iterative(13) << '\n';
    cout << "search for 6 in binary tree  : " << search_recursive(root, 6) << '\n';
    cout << "search for 6 in binary tree  : " << search_iterative(6) << '\n';
    cout << "----------------------------------------------------\n";

    cout << "delete all nodes in the binary tree\n";
    delete_tree_iterative();
    root = NULL;
    cout << "----------------------------------------------------\n";

	/*	Tree Diagram
				   5
			  /         \
			 7           11
		   /   \       /    \
		  4     6     9      13
	*/

    // first level root only
	root = new node();
	root->data = 5;    
    // second level
	root->left = new node();
	root->left->data = 7;
	root->right = new node();
	root->right->data = 11;
    // third level
	root->left->left = new node();
	root->left->left->data = 4;
	root->left->right = new node();
	root->left->right->data = 6;
	root->right->left = new node();
	root->right->left->data = 9;
	root->right->right = new node();
	root->right->right->data = 13;

    traverse_all_types();
    cout << "----------------------------------------------------\n";

	cout << "is Binary Search Tree : " << is_BST(root) << "\n";
	cout << "is Binary Search Tree : " << is_BST(root, INT_MIN, INT_MAX) << "\n";
	cout << "----------------------------------------------------\n";

    cout << "LCA of 6, 9  is : " << find_LCA(root, 6, 9)->data << "\n";
    cout << "LCA of 4, 13 is : " << find_LCA(root, 4, 13)->data  << "\n";
    cout << "LCA of 9, 13 is : " << find_LCA(root, 9, 13)->data << "\n";
    cout << "LCA of 4, 6  is : " << find_LCA(root, 4, 6)->data << "\n";
    cout << "LCA of 7, 11 is : " << find_LCA(root, 7, 11)->data << "\n";
    cout << "LCA of 5, 6  is : " << find_LCA(root, 5, 6)->data  << "\n";
    cout << "LCA of 5, 9  is : " << find_LCA(root, 5, 9)->data  << "\n";
    cout << "LCA of 7, 9  is : " << find_LCA(root, 7, 9)->data  << "\n";
    cout << "LCA of 6, 11 is : " << find_LCA(root, 6, 11)->data  << "\n";

}
