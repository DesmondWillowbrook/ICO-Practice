#include <bits/stdc++.h>
using namespace std;
using l = long long;
int main()
{
	l t; cin >> t;
	while(t--){
		l n, lim; cin >> n >> lim;
		string s;
		cin >> s;
		vector<l> res(n);
		l cnt=0;
		for(int i=0; i<n; ++i) {
			res[i]=0;
			here:   
			s[i]=='0'? ++cnt:--cnt; //cout <<"cnt is\t" << abs(cnt) << "\n";
			if(abs(cnt)>lim) {
				res[i]=1; cnt=0;
				goto here;
			}
		}
		res[0]=1;
		for(auto &i:res) cout << i;
		cout << "\n";
	}
	return 0;
}