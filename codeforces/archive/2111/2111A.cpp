//
// Created by NMCuong on 03-Jun-25.
//
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

void update(int& a, int& b, int& c, const int x) {
	if (a == b && b == c && c == x) {
		return;
	}
	// cout << "a = " << a << " b = " << b << " c = " << c << " x =  " << x << endl;
	if (a <= b && a <= c) {
		// min = a
		a = min((min(b, c) * 2 + 1), x);
	} else if (b <= a && b <= c) {
		b = min(min(a, c) * 2 + 1, x);
	} else {
		c = min(min(a, b) * 2 + 1, x);
	}
}

void solve() {
	int x;
	cin >> x;
	int a = 0, b = 0, c = 0;
	int res = 0;
	while (a < x || b < x || c < x) {
		update(a, b, c, x);
		res++;
	}
	cout << res << endl;
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
