#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()
#define sc scan_single()

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2> A) {
	os << "{ " << A.first << ", " << A.second << " }";
	return os;
}

template <class T1, class T2, class T3>
ostream& operator<<(ostream& os, tuple<T1, T2, T3> A) {
	os << "{ " << get<0>(A) << ", " << get<1>(A) << ", " << get<2>(A) << " }";
	return os;
}

template <class it>
void print(it begin, it end) {
	for (it i = begin; i != end; ++i) {
		cout << *i << " ";
	}
}

int MOD = 1e9 + 7;
int verbose = -1;
int all_cases = -1;

void solve() {
	int n;
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	vector<int> l(n);
	vector<int> r(n);
	for (int i = 0; i < n; ++i) {
		cin >> l[i];
		cin >> r[i];
	}
	// find height
	int max_height[n];
	int min_height[n];
	max_height[0] = 0;
	min_height[0] = 0;
	for (int i = 1; i < n; ++i) {
		if (d[i] == 0) {
			max_height[i] = max_height[i - 1];
			min_height[i] = min_height[i - 1];
		} else if (d[i] == 1) {
			max_height[i] = max_height[i - 1] + 1;
			min_height[i] = min_height[i - 1] + 1;
		} else {
			max_height[i] = max_height[i - 1] + 1;
			min_height[i] = min_height[i - 1];
		}
		max_height[i] = min(max_height[i], r[i]);
		min_height[i] = max(min_height[i], l[i]);
		if (min_height[i] > max_height[i]) {
			cout << -1 << endl;
			return;
		}
	}
	vector<int> h(n);
	h[n - 1] = max_height[n - 1];
	if (l[0] != 0) {
		cout << -1 << endl;
		return;
	}

	for (int i = n - 1 - 1; i >= 0; --i) {
		if (d[+1] == 0) {
			h[i] = h[i + 1];
		} else if (d[i + 1] == 1) {
			h[i] = h[i + 1] - 1;
		} else {
			//  d == -1;
			if (h[i + 1] <= max_height[i] && min_height[i] <= h[i + 1]) {
				h[i] = h[i + 1];
				d[i + 1] = 0;
			} else if (h[i + 1] - 1 == max_height[i]) {
				h[i] = h[i + 1] - 1;
				d[i + 1] = 1;
			} else {
				cout << "WTF is this" << endl;
			}
		}
	}
	// print(all(h));
	// cout<<endl;

	if (d[0] == -1) {
		d[0] = 0;
	}else if (d[0]==1) {
		cout << -1 << endl;
		return;
	}
	print(all(d));
	cout << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const auto start = chrono::steady_clock::now();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
#ifndef ONLINE_JUDGE
		cout << "-------- case " << i + 1 << "-------- " << endl;
#endif
		solve();
	}

	const auto end = chrono::steady_clock::now();
#ifndef ONLINE_JUDGE
	const auto time_span = chrono::duration_cast<chrono::duration<double>>(end - start);
	cout << "time use: " << time_span.count() << endl;
#endif

	return 0;
}
