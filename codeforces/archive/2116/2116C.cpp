//
// Created by NMCuong on 31-May-25.
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
bool g[5000][5000];
int N = 5000;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(all(a));

	int gcd_all = a[0];
	for (int i = 1; i < n; ++i) {
		gcd_all = __gcd(gcd_all, a[i]);
	}
	for (int i = 0; i < n; ++i) {
		a[i] /= gcd_all;
	}
	print(all(a));
	cout<<endl;
	int res = n+1;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 1) {
			res--;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (g[a[i]][a[j]]) {
				res--;
				cout<<res<<endl;
				return;
			}
		}
	}
	cout<<res<<endl;
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

	memset(g, 1, sizeof(g));
	// for (int i = 0; i <=N; ++i) {
		// for (int j = 0; j <= N; ++j) {
			// g[i][j] = 1;
		// }
	// }
	for (int i = 2; i <= N; ++i) {
		for (int j = i; j <= N; j += i) {
			for (int k = i; k < j; k += i) {
				g[k][j] = false;
			}
		}
	}
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
