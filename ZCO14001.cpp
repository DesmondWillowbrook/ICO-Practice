#include<bits/stdc++.h>

using namespace std;

int n, h;
int in;

void print_boxes (int* boxes) {
    for (int i = 0; i < n; i++) {
        cout << boxes[i] << " ";
    }
    cout << endl;
}

int pos = 0;
bool box_in_hand = false;

void crane (int* boxes, int cmd) {
    #ifdef DEBUG
    print_boxes(boxes);
    for (int i = 0; i < pos; i++) {
        cout << "  ";
    }
    if (box_in_hand) {
        cout << "^";
    } else {
        cout << "|";
    }
    cout << endl;
    #endif

    // move left
    if (cmd == 1 && pos - 1 >= 0)
        pos--;

    // move right
    else if (cmd == 2 && pos + 1 < n)
        pos++;

    // pick up box
    else if (cmd == 3 &&
        box_in_hand == false &&
        boxes[pos] >= 1) //there is a box to pick up
    {
        box_in_hand = true;
        boxes[pos]--;
        return;
    }

    // drop box
    else if (cmd == 4 &&
        box_in_hand == true &&
        boxes[pos] + 1 <= h)
    {
        box_in_hand = false;
        boxes[pos]++;
        return;
    }
}

int main() {
    cin >> n >> h;
    int boxes[n] = {0};

    for (int i = 0; i < n; i++) {
        cin >> boxes[i];
    }

    cin >> in;
    while (in != 0) {
        #ifdef DEBUG
        cout << "=> " << in << endl;
        #endif
        crane(boxes, in);
        cin >> in;
    }

    print_boxes(boxes);
}