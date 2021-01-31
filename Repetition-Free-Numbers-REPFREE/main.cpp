#include <bits/stdc++.h>

using namespace std;

bool is_valid (long unsigned int num) {
    bool digits[9] = {0};

    do {
        if (num % 10 == 0) return false;

        if (digits[(num % 10) - 1] == true) return false;
        else digits[(num % 10) - 1] = true;

        num /= 10;
    } while (num != 0);

    return true;
}

int main () {
    long unsigned int MAX = 1000000000;
    long unsigned int num; cin >> num; num++;

    while (!is_valid(num) && num < MAX) num++;

    if (num == MAX) num = 0;
    cout << num << endl;
}