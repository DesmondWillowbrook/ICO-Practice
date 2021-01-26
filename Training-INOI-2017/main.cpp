#include<bits/stdc++.h>

using namespace std;

uint max_str = 0, max_xp = 0;

uint train (uint strength) {
    //find sum of digits
    uint digit_sum = 0;
    for(uint n = strength; n != 0; n /= 10) digit_sum += n % 10;

    return pow(digit_sum, 3);
}

int main () {
    /*
    Sol 1:
    Maintain vec. of possible (XV, STR) combinations upto current city
    Then delete pairs where XV < XV(max) && STR < STR(max),
        where XV(max) and STR(max) represent the highest XV and STR values in all pairs.
    Repeat until final city not reached.
    Then print pair with highest XV

    For pairs: .first == STR, .second == XP
    */

    size_t N; cin >> N;
    
    uint exp[N], init_str;
    cin >> init_str;

    for (size_t i = 0; i < N; i++) cin >> exp[i];

    vector<pair<uint, uint>> v = {{init_str, 0}};
    v.reserve(5000);

    for (size_t i = 0; i < N; i++) {
        // find max_str, max_xp
        for (size_t j = 0; j < v.size(); j++) {
            max_str = max(v[j].first, max_str);
            max_xp = max(v[j].second, max_xp);
        }

        // removes all pairs where str < max_str AND xp < max_xp
        remove_if(v.begin(), v.end(), [](pair<uint, uint> n) {return ((n.first < max_str) && (n.second < max_xp));});

        // For each (XP, STR), add two pairs (and remove original): (XP + Str*XP[i], STR), (XP, train(STR))
        // better yet, we will modify original and add one new (to be on the safe side)

        #ifdef DEBUG
        printf ("City %ld\n", i);
        #endif

        size_t vec_size = v.size();
        for (size_t j = 0; j < vec_size; j++) {
            #ifdef DEBUG
            printf ("Considering STR: %d, XP: %d\n", v[j].first, v[j].second);
            #endif

            // case 1: Pikachu is trained
            v.push_back ({v[j].first + train(v[j].first), v[j].second});

            // case 2: Pikachu has battle (STR stays same, EXP += STR * XP[i])
            v[j].second = v[j].second + (v[j].first * exp[i]);
        }
    }

    for (size_t i = 0; i < v.size(); i++) {
        #ifdef DEBUG
        printf ("Considering STR: %d, XP: %d\n", v[i].first, v[i].second);
        #endif
        max_xp = max (max_xp, v[i].second);
    }
    cout << max_xp << endl;
}