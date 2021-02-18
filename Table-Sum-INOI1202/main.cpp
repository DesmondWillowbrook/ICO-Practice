#include<bits/stdc++.h>

using namespace std;

size_t N;

int main () {
    cin >> N;
    multiset<int> nums; int a[N];

    for (size_t i = 0; i < N; i++) {
        cin >> a[i]; a[i] += i + 1;
        nums.insert(a[i]);
    }

    for (size_t i = 0; i < N; i++) {
        cout << *nums.rbegin() + i << " ";

        // update nth number which has fallen off (i.e. in reverse order)
        int n = N - 1 - i;

        #ifdef DEBUG
        printf ("For iteration %ld, falloff number is: [%d]\n", i + 1, n);
        #endif

        nums.erase (nums.find(a[n]));
        // A number at iteration i can be written as: a[j] + j + i IF i < N - i
        // else, it is written as: a[j] + j + i - N.
        // we are storing nums as a[j] + j, i is added when printing.
        // so all we need to do is subtract N when a number falls off.
        a[n] -= N;
        nums.insert (a[n]);
    }
    cout << endl;
}