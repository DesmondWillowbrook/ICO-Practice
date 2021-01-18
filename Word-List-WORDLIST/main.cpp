#include <bits/stdc++.h>

using namespace std;

bool check_break (char s) {
    if (s == ' ' || s == '\n' || s == ',' || s == '.' || s == ':' || s == ';' || s == '\'' )
        return true;
    return false;
}

int main () {
    size_t N;
    cin >> N;

    vector<string> ss {""};
    
    char c;
    long unsigned int word_num = 0;

    while (scanf ("%c", &c) != EOF) {
        if (check_break(c)) {
            if (ss.back() != "") {ss.push_back(""); word_num++;}
            continue;
        }
        ss.back().push_back(tolower(c));
    }
    // to account for case where last is punctuation
    if (ss.back() == "") {word_num--; ss.pop_back();}

    sort (ss.begin(), ss.end());

    // remove duplicates
    for (size_t i = 1; i < ss.size(); i++)
        if (ss[i] == ss[i - 1]) ss[i] = "";

    cout << word_num << endl;
    for (string& str: ss)
        if (str != "") cout << str << endl;
}