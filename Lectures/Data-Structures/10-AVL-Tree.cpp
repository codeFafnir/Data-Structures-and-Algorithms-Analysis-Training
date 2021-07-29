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

// This function do inorder traversal of the AVL tree
void inOrder(node* curr) {
	// base case we reach a null node
    if (curr == NULL)
    	return;
	// repeat the same definition of inorder traversal
	inOrder(curr->left);
	cout << curr->data << ' ';
	inOrder(curr->right);
}

// This function do preorder traversal of the AVL tree
void preOrder(node* curr) {
	// base case we reach a null node
    if (curr == NULL)
    	return;
	// repeat the same definition of preOrder traversal
	cout << curr->data << ' ';
	preOrder(curr->left);
	preOrder(curr->right);
}

// This function do postorder traversal of the AVL tree
void postOrder(node* curr) {
	// base case we reach a null node
    if (curr == NULL)
    	return;
	// repeat the same definition of postorder traversal
	postOrder(curr->left);
	postOrder(curr->right);
	cout << curr->data << ' ';
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

int main() {

	// Functionality Testing
	
    root = insert_node(root, 350);

/*	Tree Diagram
                350
*/

	cout << "AVL Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "AVL Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "AVL Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	AVL Tree in-order   : 350 
	AVL Tree pre-order  : 350 
	AVL Tree post-order : 350 
	----------------------------------------------------
	*/

    root = insert_node(root, 300);

/*	Tree Diagram
                350
              /
          300
*/

	cout << "AVL Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "AVL Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "AVL Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	AVL Tree in-order   : 300 350 
	AVL Tree pre-order  : 350 300 
	AVL Tree post-order : 300 350 
	----------------------------------------------------
	*/

    root = insert_node(root, 250);

/*	Tree Diagram
                300
              /     \
          250         350
*/

	cout << "AVL Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "AVL Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "AVL Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	AVL Tree in-order   : 250 300 350 
	AVL Tree pre-order  : 300 250 350 
	AVL Tree post-order : 250 350 300 
	----------------------------------------------------
	*/

    root = insert_node(root, 200);

/*	Tree Diagram
                300
              /     \
          250         350
         /
	  200
*/

	cout << "AVL Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "AVL Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "AVL Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	AVL Tree in-order   : 200 250 300 350 
	AVL Tree pre-order  : 300 250 200 350 
	AVL Tree post-order : 200 250 350 300 
	----------------------------------------------------
	*/

    root = insert_node(root, 150);

/*	Tree Diagram
                300
              /     \
          200         350
         /   \
	  150     250
*/

	cout << "AVL Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "AVL Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "AVL Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	AVL Tree in-order   : 150 200 250 300 350 
	AVL Tree pre-order  : 300 200 150 250 350 
	AVL Tree post-order : 150 250 200 350 300 
	----------------------------------------------------
	*/

    root = insert_node(root, 100);

/*	Tree Diagram
                200
              /     \
          150         300
         /           /   \
	  100         250     350
*/

	cout << "AVL Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "AVL Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "AVL Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	AVL Tree in-order   : 100 150 200 250 300 350 
	AVL Tree pre-order  : 200 150 100 300 250 350 
	AVL Tree post-order : 100 150 250 350 300 200 
	----------------------------------------------------
	*/

    root = insert_node(root, 50);

/*	Tree Diagram
                200
              /     \
          100         300
         /   \       /   \
	   50     150 250     350
*/

	cout << "AVL Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "AVL Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "AVL Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	AVL Tree in-order   : 50 100 150 200 250 300 350 
	AVL Tree pre-order  : 200 100 50 150 300 250 350 
	AVL Tree post-order : 50 150 100 250 350 300 200 
	----------------------------------------------------
	*/

    root = insert_node(root, 40);

/*	Tree Diagram
                200
              /     \
          100         300
         /   \       /   \
	   50     150 250     350
      /
	40
*/

	cout << "AVL Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "AVL Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "AVL Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	AVL Tree in-order   : 40 50 100 150 200 250 300 350 
	AVL Tree pre-order  : 200 100 50 40 150 300 250 350 
	AVL Tree post-order : 40 50 150 100 250 350 300 200 
	----------------------------------------------------
	*/

    cout << "The minimum value in the tree of root 200 is: ";
    cout << min_node(root)->data << '\n';
    cout << "The maximum value in the tree of root 200 is: ";
    cout << max_node(root)->data << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	The minimum value in the tree of root 200 is: 40
	The maximum value in the tree of root 200 is: 350
	----------------------------------------------------
	*/

    cout << "The minimum value in the tree of root 100 is: ";
    cout << min_node(root->left)->data << '\n';
    cout << "The maximum value in the tree of root 100 is: ";
    cout << max_node(root->left)->data << '\n';
    cout << "The minimum value in the tree of root 300 is: ";
    cout << min_node(root->right)->data << '\n';
    cout << "The maximum value in the tree of root 300 is: ";
    cout << max_node(root->right)->data << '\n';
    cout << "----------------------------------------------------\n";

	/* Expected Output:
	The minimum value in the tree of root 100 is: 40
	The maximum value in the tree of root 100 is: 150
	The minimum value in the tree of root 300 is: 250
	The maximum value in the tree of root 300 is: 350
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

	/* Expected Output:
	element 150 in the tree
	element 100 in the tree
	element 75 not in the tree
	element 95 not in the tree
	----------------------------------------------------
	*/

    root = delete_node(root, 300);

/*	Tree Diagram
                200
              /     \
          100         350
         /   \       /
	   50     150 250
      /
	40
*/

	cout << "AVL Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "AVL Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "AVL Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	AVL Tree in-order   : 40 50 100 150 200 250 350 
	AVL Tree pre-order  : 200 100 50 40 150 350 250 
	AVL Tree post-order : 40 50 150 100 250 350 200 
	----------------------------------------------------
	*/

    root = delete_node(root, 250);

/*	Tree Diagram
                100
              /     \
           50         200
         /           /   \
	   40         150     350
*/

	cout << "AVL Tree in-order   : ";
    inOrder(root);
    cout << "\n";
	cout << "AVL Tree pre-order  : ";
    preOrder(root);
    cout << "\n";
	cout << "AVL Tree post-order : ";
    postOrder(root);
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	AVL Tree in-order   : 40 50 100 150 200 350 
	AVL Tree pre-order  : 100 50 40 200 150 350 
	AVL Tree post-order : 40 50 150 350 200 100 
	----------------------------------------------------
	*/

}

