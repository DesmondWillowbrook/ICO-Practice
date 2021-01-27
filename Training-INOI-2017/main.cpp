#include<bits/stdc++.h>

using namespace std;

uint train (uint strength) {
    //find sum of digits
    uint digit_sum = 0;
    for(uint n = strength; n != 0; n /= 10) digit_sum += n % 10;

    return pow(digit_sum, 3);
}

uint maxXP (size_t n, size_t s) {

}

int main () {
    /*
    Sol 2:
    Assertion: MaxXP upto N cities when training in S cities is constant

    MaxXP (n, s) = max (MaxXP (n - 1, s - 1), NaxXP (n - 1, s) + STR[s] * XP[n])
    This is ok as training in any S cities will yield the same strength.
    So there is a unique answer for each MaxXP (n, s), which is dependant on previous answers.
    This is DP problem, then.
    */

    size_t N; cin >> N;
    
    uint exp[N], str[N];
    cin >> str[0];
    for (size_t i = 1; i < N; i++) str[i] = str[i - 1] + train(str[i - 1]);
}