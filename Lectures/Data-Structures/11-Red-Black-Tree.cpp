#include <bits/stdc++.h>
using namespace std;

#define RED   0
#define BLACK 1

// Red Black tree node
struct node {
    int data;
    bool color;
    node* left;
    node* right;
    node* parent;
};

// Initialize a global pointer for root
node* root;

void insert_case1(node*);
void insert_case2(node*);
void insert_case3(node*);
void insert_case4(node*);
void insert_case5(node*);
void delete_case1(node*);
void delete_case2(node*);
void delete_case3(node*);
void delete_case4(node*);
void delete_case5(node*);
void delete_case6(node*);

// This function do inorder traversal of the Red Black tree
void inOrder(node* curr) {
    // base case we reach a null node
    if (curr == NULL)
        return;
    // repeat the same definition of inorder traversal
    inOrder(curr->left);
    cout << curr->data << ' ';
    inOrder(curr->right);
}

// This function do preorder traversal of the Red Black tree
void preOrder(node* curr) {
    // base case we reach a null node
    if (curr == NULL)
        return;
    // repeat the same definition of preOrder traversal
    cout << curr->data << ' ';
    preOrder(curr->left);
    preOrder(curr->right);
}

// This function do postorder traversal of the Red Black tree
void postOrder(node* curr) {
    // base case we reach a null node
    if (curr == NULL)
        return;
    // repeat the same definition of postorder traversal
    postOrder(curr->left);
    postOrder(curr->right);
    cout << curr->data << ' ';
}

// This function searches if the given data in the Red Black tree
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

// This function gets the grandparent of the given node in the Red Black tree
node* grandparent(node* x) {
    if (x == NULL || x->parent == NULL)
        return NULL;
    return x->parent->parent;
}

// This function gets the sibling of the given node in the Red Black tree
node* sibling(node* x) {
    if (x == NULL || x->parent == NULL)
        return NULL;
    if (x == x->parent->left)
        return x->parent->right;
    else
        return x->parent->left;
}

// This function gets the uncle of the given node in the Red Black tree
node* uncle(node* x) {
    if (x == NULL)
        return NULL;
    return sibling(x->parent);
}

// This function gets the color of the given node in the Red Black tree
bool node_color(node* x) {
    if (x == NULL)
        return BLACK;
    return x->color;
}

// This function computes right rotate subtree rooted with y
void right_rotate(node* y) {
    // check if the given node and it's left branch are NULLs
    if (y == NULL || y->left == NULL)
        return;
    // constract x and T2 pointers (check slides)
    node* x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    // replace node y with node x
    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->parent = y->parent;
    // perform rotation
    x->right = y;
    y->parent = x;
}

// This function computes left rotate subtree rooted with x
void left_rotate(node* x) {
    // check if the given node and it's left branch are NULLs
    if (x == NULL || x->right == NULL)
        return;
    // constract y and T2 pointers (check slides)
    node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    // replace node x with node y
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->parent = x->parent;
    // perform rotation
    y->left = x;
    x->parent = y;
}

void insert_case1(node* x) {
    if (x->parent == NULL)
        x->color = BLACK;
    else
        insert_case2(x);
}
void insert_case2(node* x) {
    if (node_color(x->parent) == BLACK)
        return;
    else
        insert_case3(x);
}
void insert_case3(node* x) {
    if (node_color(uncle(x)) == RED) {
        x->parent->color = BLACK;
        uncle(x)->color = BLACK;
        grandparent(x)->color = RED;
        insert_case1(grandparent(x));
    }
    else
        insert_case4(x);
}
void insert_case4(node* x) {
    if (x == x->parent->right && x->parent == grandparent(x)->left) {
        left_rotate(x->parent);
        x = x->left;
    }
    else if (x == x->parent->left && x->parent == grandparent(x)->right) {
        right_rotate(x->parent);
        x = x->right;
    }
    insert_case5(x);
}
void insert_case5(node* x) {
    x->parent->color = BLACK;
    grandparent(x)->color = RED;
    if (x == x->parent->left && x->parent == grandparent(x)->left)
        right_rotate(grandparent(x));
    else
        left_rotate(grandparent(x));
}

// This function inserts a new node with given key in the Red Black tree
void insert_node(int data) {
    // create a new node
    node* new_node = new node();
    new_node->data = data;
    new_node->color = RED;
    // if the tree is empty
    if (root == NULL) {
        root = new_node;
        root->color = BLACK;
        return;
    }
    node* curr = root;
    while (curr != NULL) {
        // repeat the same definition of insert at left subtrees
        if (data < curr->data) {
            if (curr->left == NULL) {
                curr->left = new_node;
                break;
            }
            curr = curr->left;
        }
        // repeat the same definition of insert at right subtrees
        else if (data > curr->data) {
            if (curr->right == NULL) {
                curr->right = new_node;
                break;
            }
            curr = curr->right;
        }
        // duplicate keys are not allowed in the Red Black tree
        else
            return;
    }
    new_node->parent = curr;
    insert_case1(new_node);
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

void delete_case1(node* x) {
    if (x->parent == NULL)
        return;
    delete_case2(x);
}
void delete_case2(node* x) {
    node* s = sibling(x);
    if (node_color(s) == RED) {
        x->parent->color = RED;
        s->color = BLACK;
        if (x == x->parent->left)
            left_rotate(x->parent);
        else
            right_rotate(x->parent);
    }
    delete_case3(x);
}
void delete_case3(node* x) {
    node* s = sibling(x);
    if ((x->parent->color == BLACK) && (s->color == BLACK) &&
        (node_color(s->left) == BLACK) && (node_color(s->right) == BLACK)) {
        s->color = RED;
        delete_case1(x->parent);
    }
    else
        delete_case4(x);
}
void delete_case4(node* x) {
    node* s = sibling(x);
    if ((x->parent->color == RED) && (s->color == BLACK) &&
        (node_color(s->left) == BLACK) && (node_color(s->right) == BLACK)) {
        s->color = RED;
        x->parent->color = BLACK;
    }
    else
        delete_case5(x);
}
void delete_case5(node* x) {
    node* s = sibling(x);
    if (s->color == BLACK) {
        if ((x == x->parent->left) && (node_color(s->right) == BLACK) && (node_color(s->left) == RED)) {
            s->color = RED;
            s->left->color = BLACK;
            right_rotate(s);
        }
        else if ((x == x->parent->right) && (node_color(s->left) == BLACK) && (node_color(s->right) == RED)) {
            s->color = RED;
            s->right->color = BLACK;
            left_rotate(s);
        }
    }
    delete_case6(x);
}
void delete_case6(node* x) {
    node* s = sibling(x);
    s->color = x->parent->color;
    x->parent->color = BLACK;
    if (x == x->parent->left) {
        s->right->color = BLACK;
        left_rotate(x->parent);
    }
    else {
        s->left->color = BLACK;
        right_rotate(x->parent);
    }
}

void delete_child(node* x) {
    if (x == NULL)
        return;
    // get the only child of node x
    node* child;
    if (x->right == NULL)
        child = x->left;
    else
        child = x->right;
    // replace node x with node child
    if (x->parent == NULL)
        root = child;
    else if (x == x->parent->left)
        x->parent->left = child;
    else
        x->parent->right = child;
    if (child != NULL)
        child->parent = x->parent;
    // fix the violation if exists
    if (node_color(x) == BLACK) {
        if (node_color(child) == RED)
            child->color = BLACK;
        else {
            delete_case1(x);
        }
    }
    delete(x);
}

// This function deletes the given data in the Red Black tree if exists
void delete_node(node* curr, int data) {
    // base case we reach a null node
    if (curr == NULL)
        return;
    // repeat the same definition of delete at left subtrees
    if (data < curr->data)
        delete_node(curr->left, data);
    // repeat the same definition of delete at right subtrees
    else if (data > curr->data)
        delete_node(curr->right, data);
    // if the given data is same as curr's data, then we will delete this node
    else {
        if (curr->left == NULL || curr->right == NULL) {
            delete_child(curr);
        }
        else {
            // get the inorder successor (smallest in the right subtree)
            node* temp = min_node(curr->right);
            // copy the inorder successor's content to this node
            curr->data = temp->data;
            // delete the inorder successor
            delete_node(curr->right, temp->data);
        }
    }
}

void print_tree_structure(node* curr, string indent, bool last) {
    if (curr == NULL)
        return;
    cout << indent;
    if (last) {
        cout << "R----";
        indent += "   ";
    }
    else {
        cout << "L----";
        indent += "|  ";
    }
    cout << curr->data << " (" << (curr->color==0 ? "RED" : "BLACK") << ")" << endl;
    print_tree_structure(curr->left, indent, false);
    print_tree_structure(curr->right, indent, true);
}

int main() {
    for (int i=10;i<=100;i+=10)
      insert_node(i);
    for (int i=200;i>100;i-=10)
      insert_node(i);
    cout << "\nLevel Order Traversal of Created Tree\n";
    print_tree_structure(root, "", true);
    delete_node(root, 70);
    delete_node(root, 120);
    delete_node(root, 200);
    delete_node(root, 190);
    delete_node(root, 180);
    delete_node(root, 40);
    cout << "\nLevel Order Traversal of Created Tree\n";
    print_tree_structure(root, "", true);
}
