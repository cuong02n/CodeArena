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

template <class T1>
T1 kadane(vector<T1>& a,string s) {
	T1 max_sum = a[0], current_sum = a[0];
	for (int i = 1; i < a.size(); ++i) {
		if (s[i] == '0') {
			current_sum = -3e18;
			continue;
		}
		current_sum = max(current_sum + a[i], a[i]);
		max_sum = max(max_sum, current_sum);
	}
	return max_sum;
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
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	ll max_sum = a[0];
	ll current_sum = a[0];
	if (s[0] == '0') {
		max_sum = -3e18;
		current_sum = -3e18;
	}
	for (int i = 1; i < n; ++i) {
		if (s[i] == '0') {
			current_sum = -3e18;
			continue;
		}
		current_sum = max(current_sum + a[i], a[i]);
		max_sum = max(max_sum, current_sum);
	}
	if (max_sum == k) {
		cout << "YES" << endl;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				cout << -1000000000000000000 << " ";
			} else {
				cout << a[i] << " ";
			}
		}
		cout << endl;
		return;
	}
	if (max_sum > k) {
		cout << "NO" << endl;
		return;
	}

	// 1 number 0
	int first_0 = -1;
	int second_0 = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0' && first_0 == -1) {
			first_0 = i;
			continue;
		}
		if (s[i] == '0' && first_0 != -1) {
			second_0 = i;
			break;
		}
	}
	if (first_0 == -1) {
		cout << "NO" << endl;
		return;
	}
	if (second_0 == -1) second_0 = n;
	cout << "YES" << endl;
	for (int i = second_0; i < n; ++i) {
		if (s[i] == '0')
			a[i] = -1e18;
	}
	ll lo = -1e18, hi = 1e18, best = -1e18;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll old = a[first_0];
		a[first_0] = mid;
		if (kadane(a,s) < k) {
			lo = mid + 1;
		} else if (kadane(a,s) > k) {
			hi = mid - 1;
		} else {
			best = mid;
			break;
		}
		a[first_0] = old; // reset
	}
	if (best <= -1e18) {
		a[first_0] = best;
	}
	print(all(a));
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
