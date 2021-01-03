/// https://www.codechef.com/INOIPRAC/problems/INOI1301

#include<bits/stdc++.h>

using namespace std;

int main() {
    size_t n, k;
    cin >> n ;
    cin >> k;
    k--; //so k corresponds with array indices

    int a[n + 2] = {0}; //in case k = 0 or = n, loops still run properly.
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sol[n + 2] = {0}; //in case k = 0 or = n, loops still run properly.
    sol[k] = 0;
    
    // Forward phase
    sol[k + 1] = a[k + 1]; // Moving forward from k => 
    sol[k + 2] = a[k + 2]; // Moving forward from k => 

    size_t larget_forward_index = k;
    for (size_t i = k + 3; i < n; i++) {
        #ifdef DEBUG
        printf("sol[%ld] = max(%d, %d) + %d = %d\n", i, sol[i - 1], sol[i - 2], a[i], max(sol[i - 1], sol[i - 2]) + a[i]);
        #endif
        sol[i] = max(sol[i - 1], sol[i - 2]) + a[i];
        if (sol[i] > sol[larget_forward_index]) {
            larget_forward_index = i;
        }
    }

    #ifdef DEBUG
    printf("larget_forward_index = %ld\n", larget_forward_index);
    #endif

    sol[k] = a[k];
    // Backward phase (starting point at most < n, atleast = k)
    for (int i = larget_forward_index - 1; i >= 0; i--) {
        #ifdef DEBUG
        printf("sol[%d] = max(%d, %d) + %d = %d\n", i, sol[i + 1], sol[i + 2], a[i], max(sol[i + 1], sol[i + 2]) + a[i]);
        #endif
        sol[i] = max(sol[i + 1], sol[i + 2]) + a[i];
    }

    cout << sol[0] << endl;
}