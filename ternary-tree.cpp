#include<bits/stdc++.h>

using namespace std;

struct node {
    struct node* children[3];
    int content;
};

void pre_order(struct node* n) {
    if (n == NULL) {
        return;
    }

    cout << n->content << " ";
    for (size_t i = 0; i < sizeof(n->children) / sizeof(n->children[0]); i++) {
        pre_order(n->children[i]);
    }
}

void post_order(struct node* n) {
    if (n == NULL) {
        return;
    }

    for (size_t i = 0; i < sizeof(n->children) / sizeof(n->children[0]); i++) {
        post_order(n->children[i]);
    }
    cout << n->content << " ";
}

void build_tern_tree (struct node* n) {    
    int in;

    for (size_t i = 0; i < sizeof(n->children) / sizeof(n->children[0]); i++) {
        printf("Enter value at %ld of %d: ", i, n->content);
        cin >> in;

        if (in != -1) {
            n->children[i] = (struct node*) malloc(sizeof(struct node));
            n->children[i]->content = in;
            build_tern_tree(n->children[i]);
        }
    }
}

int main() {
    struct node* start = (struct node*) malloc(sizeof(struct node));

    // init start with value
    cout << "Enter initial value: ";
    cout << "You can input -1 to finish adding a right/left node" << endl;

    cin >> start->content;

    //construct a binary tree
    build_tern_tree(start);

    cout << "Post order: ";
    post_order(start);
    cout << endl;

    cout << "Pre order: ";
    pre_order(start);
    cout << endl;
}