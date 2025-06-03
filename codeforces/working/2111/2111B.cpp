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

// return 0 or 1
int solveCubic(const int w, const int l, const int h, const int n) {
	const int fibo[] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
	const int edge_length = fibo[n];
	const int more_length = fibo[n - 1] + edge_length;
	if (w < edge_length || l < edge_length || h < edge_length) {
		return 0;
	}
	if (w >= more_length || l >= more_length || h >= more_length) {
		return 1;
	}
	return 0;
}


void solve() {
	int n, m;
	cin >> n >> m;
	// n : cubes
	// m : box

	vector<int> res(m);
	for (int i = 0; i < m; ++i) {
		int w, l, h;
		cin >> w >> l >> h;
		res[i] = solveCubic(w, l, h, n);
	}
	for (int i = 0; i < m; ++i) {
		cout << res[i];
	}
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
