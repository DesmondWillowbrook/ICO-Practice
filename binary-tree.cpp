/* Most amazing thing about this program:
*  It only took one SEGFAULT, and that too
*  was only due to assigning pointers by: 
*       curr, prev = start;
*  instead of:
*       curr = prev = start;
*  Lesson: When in doubt, DON'T be stylish/concise. 
*/

/* 
Definition of Pre-order, Post-order, In-order used: (Competitive Programmer's Handbook, by Antti Laaksonen - pg. 139)
a. n-order: first traverse the left subtree, then process the root, then traversethe right subtree
b. pre-order:  first  process  the  root,  then  traverse  the  left  subtree,  thentraverse the right subtree
c. post-order: first traverse the left subtree, then traverse the right subtree,then process the root
*/

/*
Input to build tree on pg. 139 (compile with SELFIN defined):
1 2 4 -1 -1 5 6 -1 -1 -1 3 -1 7 -1 -1
*/

#include<bits/stdc++.h>

using namespace std;

struct node {
    struct node* left;
    struct node* right;
    int content;
};

void pre_order(struct node* n) {
    if (n == NULL) {
        return;
    }

    cout << n->content << " ";
    pre_order(n->left);
    pre_order(n->right);
}

void post_order(struct node* n) {
    if (n == NULL) {
        return;
    }

    post_order(n->left);
    post_order(n->right);
    cout << n->content << " ";
}

void in_order(struct node* n) {
    if (n == NULL) {
        return;
    }

    in_order(n->left);
    cout << n->content << " ";
    in_order(n->right);
}

void stack_pre_order(struct node* n) {
    stack<struct node*> s;
    s.push(n);

    struct node* curr;
    while (!s.empty()) {
        curr = s.top();
        cout << curr->content << " ";
        s.pop();

        if (curr->right != NULL) {
            s.push(curr->right);
        }
        if (curr->left != NULL) {
            s.push(curr->left);
        }
    }
}

// Recursively expands first left node then right node.
// expand <- i.e. pushes children into stack (such that left child is on top)
void post_order_expand(stack<struct node*>& s) {
    struct node* curr = NULL;
    while (curr != s.top()) { //i.e. terminates when both curr->right and curr->left are NULL
        curr = s.top();

        if (curr->right != NULL) {
            s.push(curr->right);
            post_order_expand(s);
        }
        if (curr->left != NULL) {
            s.push(curr->left);
            post_order_expand(s);
        }
    }
}

void stack_post_order(struct node* n) {
    stack<struct node*> s;
    s.push(n);

    struct node* curr = s.top();
    post_order_expand(s);
    
    while (!s.empty()) {
        cout << s.top()->content << " ";
        s.pop();
    }
}


#ifdef SELFIN
void build_bin_tree (struct node* n) {    
    int in;

    cout << "Enter value at left of " << n->content << ": ";
    cin >> in;

    if (in != -1) {
        n->left = (struct node*) malloc(sizeof(struct node));
        n->left->content = in;
        build_bin_tree(n->left);
    }

    cout << "Enter value at right of " << n->content << ": ";
    cin >> in;

    if (in != -1) {
        n->right = (struct node*) malloc(sizeof(struct node));
        n->right->content = in;
        build_bin_tree(n->right);
    }
}
#endif

int main() {
    struct node* start = (struct node*) malloc(sizeof(struct node));

    // init start with value
    #ifdef SELFIN
    cout << "Enter initial value: ";
    cout << "You can input -1 to finish adding a right/left node" << endl;
    #endif

    cin >> start->content;

    struct node *curr, *prev;
    struct node **fin;

    //construct a binary tree
    #ifndef SELFIN
    int in;
    while (cin >> in) {
        curr = prev = start;
        while (curr != NULL) {
            if (curr->content > in) {
                prev = curr;
                curr = curr->right;
            } else if (curr->content < in) {
                prev = curr;
                curr = curr->left;
            }
        }

        fin = prev->content > in ? &prev->right : &prev->left;

        // allocate node in right/left (depending on value of in)
        *fin = (struct node*) malloc(sizeof(struct node));
        (*fin)->content = in;
    }
    #endif

    #ifdef SELFIN
    build_bin_tree(start);
    #endif

    cout << "Post order: ";
    post_order(start);
    cout << endl;

    cout << "Pre order: ";
    pre_order(start);
    cout << endl;

    cout << "In order: ";
    in_order(start);
    cout << endl;

    cout << "Stack pre order: ";
    stack_pre_order(start);
    cout << endl;

    cout << "Stack post order: ";
    stack_post_order(start);
    cout << endl;

}