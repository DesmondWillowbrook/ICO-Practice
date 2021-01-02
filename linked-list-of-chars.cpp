#include<bits/stdc++.h>

using namespace std;

struct node {
    struct node* next;
    char content;
};

int main() {
    char in;
    struct node* curr;
    struct node* start = (struct node*) malloc(sizeof(node));
    curr = start;

    size_t size = 0;

    while (cin >> in) {
        curr->content = in;
        curr->next = (struct node*) malloc(sizeof(node));
        curr = curr->next;
        size++;
    }
    size--; // move size to 0-based indexing (as it was operating on 1-based till now)
    curr->next = 0;

    curr = start;

    for (size_t i = 0; i < size/2; i++) {
        curr = curr->next;
    }

    cout << curr->content;
    if (size % 2 != 0) {
        cout << curr->next->content;
    }

    cout << endl;
}