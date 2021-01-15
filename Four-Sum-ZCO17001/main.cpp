#include<bits/stdc++.h>

using namespace std;

size_t N, ans = 0;
unsigned long int T;

unsigned long int sum (vector<pair<unsigned long int, unsigned long int>>::iterator i) {
    return (*i).first + (*i).second;
}

unsigned long int sum_and_check (vector<pair<unsigned long int, unsigned long int>>::iterator i) {
    return (*i).first + (*i).second;
}

int main() {
    cin >> N >> T;
    int arr[N];

    for (size_t i = 0; i < N; i++) cin >> arr[i];
    sort (arr, arr + N);

    vector<pair<unsigned long int, unsigned long int>> pairs;
    for (size_t i = 0; i < N; i++)
        for (size_t j = i + 1; j < N; j++)
            pairs.push_back({arr[i], arr[j]});
    sort (pairs.begin(), pairs.end());

    #ifdef DEBUG
    cout << "Pair Sums: \n";
    for (auto ele: pairs) cout << ele << " ";
    cout << endl;
    #endif

    auto left = pairs.begin(), right = --pairs.end();
    while (left < right) {
        while (sum(left) + sum(right) > T) right--;
        if (sum(left) + sum(right) == T) ans++;
        #ifdef DEBUG
        if (*left + *right == T) printf ("Pair: %ld, %ld == %ld\n", *left, *right, T);
        #endif
        left++;
    }

    cout << ans << endl;
}