#include <bits/stdc++.h>

using namespace std;

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

        if (in == '\n' || in == EOF) N--;
    }

    cout << s.size() << endl;
    for (const string& str: s) 
        cout << str << "\n";
}