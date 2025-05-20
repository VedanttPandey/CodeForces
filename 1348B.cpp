#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		set<int> s;
		for (auto &i : a) {
			cin >> i;
			s.insert(i);
		}
		if (s.size() > k) {
			cout << -1 << "\n";
			continue;
		}

		
		vector<int> pattern(s.begin(), s.end());

		
		while (pattern.size() < k)
			pattern.push_back(1);

		vector<int> neww;
		
		for (int i = 0; i < n; ++i)
			neww.insert(neww.end(), pattern.begin(), pattern.end());

		cout << neww.size() << "\n";
		for (auto &i : neww) {
			cout << i << " ";
		}
		cout << "\n";
	}
}
