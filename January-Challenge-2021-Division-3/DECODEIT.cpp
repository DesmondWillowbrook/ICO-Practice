#include<bits/stdc++.h>

using namespace std;


int main() {
    uint t, n;
    char a, tmp;
    cin >> t;

    while(t--) {
        cin >> n;
        n /= 4;
        while (n--) {
            a = 'a';
            for (int i = 3; i >= 0; i--) {
                cin >> tmp;
                a += ((tmp - '0') << i);
                #ifdef DEBUG
                printf("%c += %d\n", a, ((tmp - '0') << i));
                #endif
            }
            cout << a;
        }
        cout << endl;
    }
}