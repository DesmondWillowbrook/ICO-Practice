#include<bits/stdc++.h>

using namespace std;

size_t N, M, W, B;
long long unsigned int ans = 0;

int main () {
    cin >> N >> M >> W >> B;
    vector<pair<size_t, bool>> non_e [M];

    size_t x, y;
    for (size_t i = 0; i < W; i++) {cin >> x >> y; non_e[y].push_back({x, false});} 
    for (size_t i = 0; i < B; i++) {cin >> x >> y; non_e[y].push_back({x, true});}

    for (size_t y = 0; y < M; y++) {
        // descending order so we can use as stack
        // as the top is smallest, which is what we want
        sort(non_e[y].begin(), non_e[y].end());
        #ifdef DEBUG
        printf ("Heatbeat for sorting %ld row\n", y);
        #endif
        
        // incase last is E, then push B and increment ans by 1 (since now last can't be counted using normal loop)
        if (!non_e[y].empty()) {
            if (non_e[y].back().first != N) {non_e[y].push_back({N, true}); ans++;}
            else non_e[y].back().second = true;
        } else non_e[y].push_back({N, true});
    }

    /*
    Strat:
    E = empty, B => (true <- Will stop completely), W => (Non-E after this will stop completely)
    We can calculate in linear time sum of distances of rays between any two non-E points.
    */

    // consider per row (since that's the direction in which rays are traveling)
    for (size_t y = 0; y < M; y++) {
        size_t processed_till = 0;
        while (processed_till < N) {
            #ifdef DEBUG
            printf ("Sizeof vec: %ld\n", non_e[y].size());
            #endif
            auto point = non_e[y].back(); non_e[y].pop_back();
            if (point.second == false) { // in-case point is W
                auto start = point;
                // we have now found where the beam ends i.e. at the next non-E point
                point = non_e[y].back(); non_e[y].pop_back();
                ans += ((start.first - processed_till) * (2 * point.first + 3 - start.first - processed_till)) / 2;
            }
            else {
                ans += ((point.first - processed_till) * (point.first - processed_till + 3)) / 2;
                processed_till += point.first + 1; // we have now processed till after the non-E point
            }
        }
    }

    cout << ans << endl;
}