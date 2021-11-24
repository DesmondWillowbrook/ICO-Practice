#include<bits/stdc++.h>

using namespace std;
#define ll long long int;
/*
int lcm (int x, int y) {
	if (x == 1 || y == 1) {return max(x, y);}

}
*/
int main () {
	long int t; cin >> t;
	long long int X, K; 
	
	while(t--) {
		cin >> X >> K;
		cout << X*2 << " " << X*K*((X*K)-1) << endl;
	}
}