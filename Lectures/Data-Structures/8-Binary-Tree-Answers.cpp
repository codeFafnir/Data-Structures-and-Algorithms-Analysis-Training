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
// This function searches if the given data in the binary tree in recursive way
bool search_recursive(node* curr, int data) {
	if (curr == NULL)
		return false;
	if (curr->data == data)
		return true;
    bool left_search  = search_recursive(curr->left, data);
	bool right_search = search_recursive(curr->right, data);
	return left_search || right_search;
}
// This function searches if the given data in the binary tree in iterative way
bool search_iterative(int data) {
    if (root == NULL)
        return false;
    stack<node*> stk;
    node* curr = root;
	stk.push(root);
    while (!stk.empty()) {
		node *curr = stk.top();
		stk.pop();
        if (curr->data == data)
            return true;
		if (curr->right)
			stk.push(curr->right);
		if (curr->left)
			stk.push(curr->left);
	}
    return false;
}
// This function traverses the binary tree in postorder to delete all nodes in recursive way
void delete_tree_recursive(node* curr) {
	if (curr == NULL)
    	return;
    delete_tree_recursive(curr->left);
    delete_tree_recursive(curr->right);
    delete(curr);
}
// This function traverses the binary tree in postorder to delete all nodes in iterative way
void delete_tree_iterative() {
    if (root == NULL)
        return;
    stack<node*> stk;
    node* curr = root;
	stk.push(root);
    while (!stk.empty()) {
		node *curr = stk.top();
		stk.pop();
		if (curr->left)
			stk.push(curr->left);
		if (curr->right)
			stk.push(curr->right);
        delete(curr);
	}
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
// This function returns the maximum value in the binary tree in recursive way
int find_max_value_recursive(node* curr) {
    if (curr == NULL)
      return INT_MIN;
    int res = curr->data;
    int left_res  = find_max_value_recursive(curr->left);
    int right_res = find_max_value_recursive(curr->right);
    return max(res, max(left_res, right_res));
}
// This function returns the maximum value in the binary tree in iterative way
int find_max_value_iterative() {
    int res = INT_MIN;
    if (root == NULL)
        return res;
    stack<node*> stk;
    node* curr = root;
	stk.push(root);
    while (!stk.empty()) {
		node *curr = stk.top();
        res = max(res, curr->data);
		stk.pop();
		if (curr->left)
			stk.push(curr->left);
		if (curr->right)
			stk.push(curr->right);
	}
    return res;
}
// This function returns the minimum value in the binary tree in recursive way
int find_min_value_recursive(node* curr) {
    if (curr == NULL)
      return INT_MAX;
    int res = curr->data;
    int left_res  = find_min_value_recursive(curr->left);
    int right_res = find_min_value_recursive(curr->right);
    return min(res, min(left_res, right_res));
}
// This function returns the minimum value in the binary tree in iterative way
int find_min_value_iterative() {
    int res = INT_MAX;
    if (root == NULL)
        return res;
    stack<node*> stk;
    node* curr = root;
	stk.push(root);
    while (!stk.empty()) {
		node *curr = stk.top();
        res = min(res, curr->data);
		stk.pop();
		if (curr->left)
			stk.push(curr->left);
		if (curr->right)
			stk.push(curr->right);
	}
    return res;
}
// This function gets the maximum depth in the binary tree
int max_depth(node* curr) {
	if (curr == NULL)
		return 0;
	int left_depth  = max_depth(curr->left);
	int right_depth = max_depth(curr->right);
	return 1 + max(left_depth, right_depth);
}
// This function gets the minimum depth in the binary tree
int min_depth(node* curr) {
	if (curr == NULL)
		return 0;
	int left_depth  = min_depth(curr->left);
	int right_depth = min_depth(curr->right);
	return 1 + min(left_depth,right_depth);
}
// This function mirrors the binary tree
void mirror(node* curr) {
	if (curr == NULL)
		return;
    mirror(curr->left);
    mirror(curr->right);
    // swap the pointers in this node
    node* temp = curr->left;
    curr->left = curr->right;
	curr->right = temp;
}
// This function counts the number of leaf nodes in a binary tree in recursive way
int count_leaf_recursive(node* curr) {
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right==NULL)
		return 1;
	int left_leaf  = count_leaf_recursive(curr->left);
	int right_leaf = count_leaf_recursive(curr->right);
	return left_leaf + right_leaf;
}
// This function counts the number of leaf nodes in a binary tree in iterative way
int count_leaf_iterative() {
    int res = 0;
    if (root == NULL)
        return res;
	queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        // dequeue the front node and make it curr
        node* curr = q.front();
        q.pop();
        if (curr->left == NULL && curr->right == NULL)
            res++;
        // enqueue the left child
        if (curr->left != NULL)
        	q.push(curr->left);
        // enqueue the right child
        if (curr->right != NULL)
        	q.push(curr->right);
    }
    return res;
}
// This function checks if node equal sum of it's child in a binary tree
bool is_sum_property(node* curr) {
	if (curr == NULL)
		return true;
	if (curr->left == NULL && curr->right == NULL)
    	return true;
	// left_data is left child data
	// right_data is right child data
	int left_data = 0;
	int right_data = 0;
    // get data from left and right
    if (curr->left != NULL)
		left_data = curr->left->data;
    if (curr->right != NULL)
		right_data = curr->right->data;
    // if the node and both of its children
    // satisfy the property return true else false
    return  curr->data == left_data + right_data &&
            is_sum_property(curr->left) &&
            is_sum_property(curr->right);
}
// This function calculates the sum of the values in a binary tree
int sum(node* curr) {
	if (curr == NULL)
		return 0;
	int left_sum = sum(curr->left);
	int right_sum = sum(curr->right);
	return left_sum + curr->data + right_sum;
}
// This function checks if sum property holds for the given node and both of its children in a binary tree
bool is_sum_tree(node* curr) {
    if (curr == NULL)
    	return true;
    if (curr->left == NULL && curr->right == NULL)
		return true;
	// Get sum of all nodes in left and right subtrees
	int left_sum = sum(curr->left);
	int right_sum = sum(curr->right);
	// if the node and both of its children
	// satisfy the property return true else false
	bool left_check  = is_sum_tree(curr->left);
	bool right_check = is_sum_tree(curr->right);
    return left_check && curr->data == left_sum + right_sum && right_check;
}
// This function checks if there exist summation of path equal given sum in a binary tree
bool has_path_sum(node* curr, int sum) {
	if (curr == NULL)
		return sum == 0;
	bool left_res  = has_path_sum(curr->left , sum - curr->data);
	bool right_res = has_path_sum(curr->right, sum - curr->data);
    return left_res || right_res;
}
// This function gets the maximum sum of all paths in a binary tree
int max_path_sum(node* curr) {
	if (curr == NULL)
		return 0;
	int left_path_sum  = max_path_sum(curr->left);
	int right_path_sum = max_path_sum(curr->right);
	return 	curr->data + max(left_path_sum, right_path_sum);
}
// This function gets the minimum sum of all paths in a binary tree
int min_path_sum(node* curr) {
	if (curr == NULL)
		return 0;
	int left_path_sum  = min_path_sum(curr->left);
	int right_path_sum = min_path_sum(curr->right);
	return 	curr->data + min(left_path_sum, right_path_sum);
}
// This function replaces each node with the sum of its inorder predecessor and successor in a binary tree
int replace_node_with_sum(node* curr) {
    if (curr == NULL)
        return 0;
    int sum_left  = replace_node_with_sum(curr->left);
    int sum_right = replace_node_with_sum(curr->right);
    curr->data += sum_left + sum_right;
    return curr->data;
}
// This function returns pointer to LCA of two given values n1 and n2 in a binary tree
node* find_LCA(node* curr, int n1, int n2) {
    if (curr == NULL)
		return NULL;
    if (curr->data == n1 || curr->data == n2)
        return curr;
    node* left_Lca  = find_LCA(curr->left, n1, n2);
    node* right_Lca = find_LCA(curr->right, n1, n2);
    // If both of the above calls return Non-NULL, then one key is present 
    // in once subtree and other is present in other, So this node is the LCA
    if (left_Lca != NULL && right_Lca != NULL)
		return curr;
    // Otherwise check if left subtree or right subtree is LCA
    if (left_Lca != NULL)
        return left_Lca;
	if (right_Lca != NULL)
		return right_Lca;
	return NULL;
}
// This function traverses given tree in Inorder and prints all nodes that have both children in a binary tree
void find_full_nodes(node* curr) {
    if (curr == NULL)
        return;
    find_full_nodes(curr->left);
    if (curr->left != NULL && curr->right != NULL)
        cout << curr->data << " ";
    find_full_nodes(curr->right);
}
// This function computes the height of a binary tree
// Height is the number of nodes along the longest path from the root node down to the farthest leaf node
int height(node* curr) {
	if (curr == NULL)
		return 0;
	int left_height  = height(curr->left);
	int right_height = height(curr->right);
	return 1 + max(left_height, right_height);
}
// This function gets diameter of a binary tree
int diameter(node* curr) {
	if (curr == NULL)
		return 0;
	int left_height  = height(curr->left);
	int right_height = height(curr->right);
	int left_diameter  = diameter(curr->left);
	int right_diameter = diameter(curr->right);
	return max(left_height + right_height + 1, max(left_diameter, right_diameter));
}
// This function computes the number of nodes in a binary tree
int size(node* curr) {
	if (curr == NULL)
		return 0;
    int left_size  = size(curr->left);
    int right_size = size(curr->right);
	return left_size + 1 + right_size;
}
// This function checks if the binary tree is complete or not
bool is_complete_tree(node* curr, int index, int tree_size) {
    if (curr == NULL)
        return true;
    // If index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if (index >= tree_size)
        return false;
    bool left_subtree  = is_complete_tree(curr->left, 2*index+1, tree_size);
    bool right_subtree = is_complete_tree(curr->right, 2*index+2, tree_size);
    return left_subtree && right_subtree;
}
// This function checks if the binary tree is full or not
bool is_full_tree(node* curr) {
    if (curr == NULL)
        return true;
    if (curr->left == NULL && curr->right == NULL)
        return true;
    if (curr->left != NULL && curr->right != NULL)
        return is_full_tree(curr->left) && is_full_tree(curr->right);
    return false;
}
// This function checks if the binary tree is perfect or not
bool is_perfect_tree(node* curr, int max_depth, int curr_depth = 1) {
    if (curr == NULL)
        return true;
	if (curr->left == NULL && curr->right == NULL)
		return curr_depth == max_depth;
	if (curr->left == NULL || curr->right == NULL)
		return false;
	return  is_perfect_tree(curr->left, max_depth, curr_depth+1) &&
		    is_perfect_tree(curr->right, max_depth, curr_depth+1);
}
// This function checks if the binary tree is pathological or not
bool is_pathological_tree(node* curr) {
    if (curr == NULL)
        return true;
    if (curr->left == NULL && curr->right == NULL)
        return true;
    if (curr->left != NULL ^ curr->right != NULL)
        return is_pathological_tree(curr->left) && is_pathological_tree(curr->right);
    return false;
}
// This function checks if the binary tree is skewed or not for left side
bool is_skewed_tree_left(node* curr) {
    if (curr == NULL)
        return true;
    if (curr->right == NULL)
        return is_skewed_tree_left(curr->left);
    return false;
}
// This function checks if the binary tree is skewed or not for right side
bool is_skewed_tree_right(node* curr) {
    if (curr == NULL)
        return true;
    if (curr->left == NULL)
        return is_skewed_tree_right(curr->right);
    return false;
}
// This function checks if the binary tree is skewed or not
bool is_skewed_tree(node* curr) {
	return is_skewed_tree_left(curr) || is_skewed_tree_right(curr);
}
// This function checks if the binary tree is balanced or not
bool is_balanced_tree(node *curr) {
	if (curr == NULL)
		return true;
	int left_height = height(curr->left);
	int right_height = height(curr->right);
	return	left_height - right_height <= 1 &&
			left_height - right_height >= -1 &&
			is_balanced_tree(curr->left) &&
			is_balanced_tree(curr->right);
}
// This function checks if a binary tree is a binary search tree or not
bool is_BST(node *curr) {
	if (curr == NULL)
		return true;
	if (curr->left != NULL && find_max_value_recursive(curr->left) > curr->data) 
		return false;
	if (curr->right != NULL && find_min_value_recursive(curr->right) < curr->data) 
		return false;   
	return is_BST(curr->left) && is_BST(curr->right);
}
// This function checks if a binary tree is a binary search tree or not
bool is_BST(node *curr, int min, int max) {
	if (curr==NULL)
		return true;
	if (curr->data < min || curr->data > max)
		return false; 
	return  is_BST(curr->left,  min, curr->data) &&
			is_BST(curr->right, curr->data, max);
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
