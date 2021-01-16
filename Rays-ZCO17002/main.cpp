#include<bits/stdc++.h>

using namespace std;

size_t N, M, W, B;
long long unsigned int ans = 0;

int main () {
    cin >> N >> M >> W >> B;
    pair<size_t, size_t> w [W], b[B];

    for (size_t i = 0; i < W; i++) cin >> w[i].first >> w[i].second;
    for (size_t i = 0; i < B; i++) cin >> b[i].first >> b[i].second;

    sort (w, w + W, greater<pair<size_t, size_t>>()); sort (b, b + B);

    long unsigned int dp[N] = {0};

    /*
    Strat: DP soln.:
        L(x, y) =
            if ((x,y) == B)
                0
            else if ((x, y) == W)
                str--
                if (str == 0)
                    0
           return  1 + L (x - 1, y)

    Start from
    */

    // consider per row (since that's the direction in which rays are traveling)
    for (uint y = 0; y < M; y++) {

    }

    cout << ans << endl;
}