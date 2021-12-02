#include<bits/stdc++.h>

using namespace std;

uint* a, b;
int lcis (int i, int j) {

}

int main () {
	uint n, m; 
	cin >> n; uint a[n + 1]; for (uint i = 1; i <= n; i++) {cin >> a[i];}
	cin >> m; uint b[m + 1]; for (uint i = 1; i <= m; i++) {cin >> b[i];}

	pair<uint, uint> dp[n + 1][m + 1];
	dp[0][0] = {0, 0};
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j] && )
		}
	}
}