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

int solve1(int n, int m, int a, int b) {
	int x = 1, y = 1;
	int cnt = 0;
	// cout << "start (" << x << "," << y << ") to (" << n << "," << m << "), current: " << "(" << a << "," << b << ")" <<endl;
	while (n > x) {
		if (a + a >= n + x) {
			x = a;
		} else {
			n = a;
		}
		a = (n + x) / 2;
		cnt++;
		// cout << " (" << x << ") to (" << n << "), current: " << "(" << a << ")" <<endl;
	}
	// cout << "start (" << y << ") to ("<< m << "), current: " << "(" << b << ")" << endl;
	while (m > y) {
		if (b + b >= m + y) {
			// cout<<"more than"<<endl;
			y = b;
		} else {
			// cout<<"less than"<<endl;
			m = b;
		}
		b = (m + y) / 2;
		cnt++;
		// cout << " (" << y << ") to ("<< m << "), current: " << "(" << b << ")" << endl;
	}
	return cnt;
}

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int x = 1, y = 1;
	int ver_first = solve1(n, m, (n + 1) / 2, b);
	int hor_first = solve1(n, m, a, (m + 1) / 2);
	cout << min(ver_first, hor_first) << endl;
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
