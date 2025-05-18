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

bool check(int m1, int m2, int m3, int s1, int s2, int s3) {
	int x1 = (m1 * 2 >= s1) ? 1 : 0;
	int y1 = (m2 * 2 >= s2) ? 1 : 0;
	int z1 = (m3 * 2 >= s3) ? 1 : 0;
	return x1 + y1 + z1 >= 2;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int smaller_than_k = count_if(a.begin(), a.end(), [&](int x) { return x <= k; });
	int m1 = 0, m2 = k, m3 = 0;
	// m : numer smaller than k;
	int s1 = 1, s2 = n - 2, s3 = 1;
	cout << smaller_than_k << endl;
	if (a[0] <= k) {
		m1++;
		m2--;
	}
	if (a[n - 1] <= k) {
		m3++;
		m2--;
	}
	if (check(m1, m2, m3, s1, s2, s3)) {
		cout << "YES" << endl;
		return;
	}
	// find l;
	// n = 3
	// 0 -> 0, 1-> 1, 2-> 2
	for (int i = 0, nz = 0, s = 0; i < n - 1; i++) {
		if (nz = 1)
	}
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
