#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, score1 = 0, score2 = 0, tmp;
    pair<uint, uint> lead;

    cin >> n;
    while (n--) {
        cin >> tmp;
        score1 += tmp;
        cin >> tmp;
        score2 += tmp;

        if (lead.second < abs(score1 - score2)) {
            if (score1 > score2) {
                lead.first = 1;
                lead.second = score1 - score2;
            } else {
                lead.first = 2;
                lead.second = score2 - score1;
            }
        }

        #ifdef DEBUG
        printf("Cumulative: %d %d\nLead is: %d by %d\n", score1, score2, lead.first, lead.second);
        #endif
    }

    cout << lead.first << " " << lead.second << endl;
}