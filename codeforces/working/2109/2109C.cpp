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
	//
	// Created by NMCuong on 17-May-25.
	//
	int n;
	cin >> n;
	cout << "digit" << endl;
	cout.flush();
	int x1;
	cin >> x1;
	//1 -> 81

	cout << "digit" << endl;
	cout.flush();
	int x2;
	cin >> x2;
	//1-> 16

	cout << "add -8" << endl;
	cout.flush();
	int x3;
	cin >> x3;
	// 1-> 8

	cout << "add -4" << endl;
	cout.flush();
	int x4;
	cin >> x4;
	// 1->4

	cout << "add -2" << endl;
	cout.flush();
	int x5;
	cin >> x5;
	// 1->2

	cout << "add -1" << endl;
	cout.flush();
	int x6;
	cin >> x6;
	// 1

	cout << "add " << n - 1 << endl;
	cout.flush();
	int x7;
	cin >> x7;

	cout << "!" << endl;
	cout.flush();
	int x8;
	cin >> x8;
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
