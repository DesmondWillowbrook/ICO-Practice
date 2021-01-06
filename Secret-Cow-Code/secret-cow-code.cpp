#include<bits/stdc++.h>

using namespace std;

string s;

char Anti_F (long long int n) {    
    if (n < s.length()) {
        return s.at(n);
    }

	size_t length = s.length();

    // Finds separator
    while(2 * length <= n) {
        length *= 2;
    }

    // Handles case of shift from first position to last position in prev. iteration
    if (length == n) {
        return Anti_F(length - 1);
    }

    // N - Separator - 1: Yields position in prev. iteration
    return Anti_F(n - length - 1);
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

    out << Anti_F(n) << endl;

    out.close();
}