#include<bits/stdc++.h>

using namespace std;

int main () {
	int n; cin >> n;
	int bricks[n];
	for (int i = 0; i < n; i++) {
		cin >> bricks[i];
	}
	stack<int> s;
	for (int i = 0; i < n; i++) {
		while (!s.empty() && s.top() <= bricks[i]) {
			s.pop();
		}
		s.push(bricks[i]);
	}
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
}