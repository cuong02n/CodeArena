/*
    author : cuong2905say
    problem: Codeforces 2242A - Two Equal Bigrams
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2> A) {
	os << "{ " << A.first << ", " << A.second << " }";
	return os;
}

int MOD = 1e9 + 7;

void solve() {
	int k;
	cin >> k;
	int cnt2 = 0;       // so chu cai co so luong >= 2
	bool has3 = false;  // ton tai chu cai co so luong >= 3
	for (int i = 0; i < k; i++) {
		ll c;
		cin >> c;
		if (c >= 2) cnt2++;
		if (c >= 3) has3 = true;
	}
	// YES neu: co chu cai >=3 (xxx -> "xx" hai lan)
	//       hoac >=2 chu cai deu >=2 (xyxy -> "xy" hai lan)
	bool ok = has3 || cnt2 >= 2;
	cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

	return 0;
}
