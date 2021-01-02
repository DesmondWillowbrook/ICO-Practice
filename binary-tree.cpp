/* Most amazing thing about this program:
*  It only took one SEGFAULT, and that too
*  was only due to me assigning pointers by: 
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

#include<bits/stdc++.h>

using namespace std;

struct node {
    struct node* left;
    struct node* right;
    uint content;
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

void efficient_pre_order(struct node* n) {
    stack<struct node*> pointers;
    pointers.push(n);

    struct node* curr;
    while (!pointers.empty()) {
        curr = pointers.top();
        cout << curr->content << " ";
        pointers.pop();


        if (curr->right != NULL) {
            pointers.push(curr->right);
        }
        if (curr->left != NULL) {
            pointers.push(curr->left);
        }
    }
}

int main() {
    struct node* start = (struct node*) malloc(sizeof(struct node));

    // init start with value
    uint in;
    cin >> in;
    start->content = in;


    struct node *curr, *prev;
    struct node **fin;

    //impl. unbalanced binary tree
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

    cout << "Post order: ";
    post_order(start);
    cout << endl;

    cout << "Pre order: ";
    pre_order(start);
    cout << endl;

    cout << "In order: ";
    in_order(start);
    cout << endl;

    cout << "Efficient pre order: ";
    efficient_pre_order(start);
    cout << endl;
}