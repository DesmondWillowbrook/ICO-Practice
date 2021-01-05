#include<bits/stdc++.h>

using namespace std;

string s;

int lshift (int p) {
    if (p - 1 < 0) {
        return s.length() - 1;
    } else {
        return p - 1;
    }
}

char F (long long int n) {
    if (n < s.length()) {
        return s.at(n);
    }
    
    // closest power of 2
    int pos = n - (s.length() * pow(2, log2(n / s.length())));

    #ifdef DEBUG
    printf ("Pos is: %d\n", pos);
    #endif

    pos = lshift(pos);
    n = (s.length() * (pow(2, log2(n / s.length())) - 1)) + pos;

    #ifdef DEBUG
    printf ("New N: F(%lld)\n", n);
    #endif
    return F (n);
}

int main () {
    ifstream in;
    in.open("cowcode.in");

    long long int n; // character in string to be printed
    in >> s >> n;
    in.close();

    // shift to zero-based indexing
    n--;
    ofstream out;
    out.open("cowcode.out");

    out << F(n) << endl;

    out.close();
}