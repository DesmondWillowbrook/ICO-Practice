#include <bits/stdc++.h>

using namespace std;

bool check_break (char s) {
    if (s == ' ' || s == '\n' || s == ',' || s == '.' || s == ':' || s == ';' || s == '\'' )
        return true;
    return false;
}

int main () {
    int N;
    cin >> N;

    set<string> s;
    char in = 0;
    string word = "";

    while (N >= 0) {
        while (isalpha(in = getchar()))
            word += tolower(in);
        if (!word.empty()) {s.insert(word); word.clear();}

        #ifdef DEBUG
        printf ("N: %d\n", N);
        #endif

        if (in == '\n' || in == EOF) N--;
    }

    cout << s.size() << endl;
    for (const string& str: s) 
        cout << str << "\n";
}