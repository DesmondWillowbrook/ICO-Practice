#include<bits/stdc++.h>

using namespace std;

int main () {
	string a; cin >> a;
	auto len = a.length();
	if (len == 1) {
		cout << 1 << endl;
		return 0;
	}

	int ans = (len*(len-1))/2 + 1;
	int occurences[26] = {0}; //could've used a multiset or even an unordered_multiset
	for (int i = 0; i < len; i++) {
		occurences[a[i]-'a']++;
	}
	for (int i = 0; i != 26; i++) {
		int c = occurences[i];
		if (c > 1) {
			#ifdef DEBUG
			printf ("Repetition noticed: of char %c, repeated %d times.\n", 'a'+i, occurences[i]);
			#endif

			ans -= (c*(c-1))/2;
		}
	}

	cout << ans << endl;
}