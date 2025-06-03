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

ll MOD = 998244353;
int verbose = -1;
int all_cases = -1;

ll power2mod(const int pow) {
	if (pow == 0) {
		return 1ll;
	}
	if (pow % 2) {
		return (power2mod(pow - 1) * 2) % MOD;
	}
	return power2mod(pow / 2) * (power2mod(pow/2)) % MOD;
}

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> q(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> q[i];
	}
	vector<int> pre_max_p(n); // value of max p(i)
	vector<int> pre_max_q(n); // value of max q(i)
	vector<int> idx_p(n);
	vector<int> idx_q(n);
	for (int i = 0; i < n; i++) {
		idx_p[p[i]] = i;
		idx_q[q[i]] = i;
	}
	pre_max_p[0] = p[0];
	pre_max_q[0] = q[0];
	for (int i = 1; i < n; i++) {
		pre_max_p[i] = max(pre_max_p[i - 1], p[i]);
		pre_max_q[i] = max(pre_max_q[i - 1], q[i]);
	}
	vector<ll> r(n);
	for (int i = 0; i < n; i++) {
		// find
		int max_p_index = idx_p[pre_max_p[i]];
		int max_q_index = idx_q[pre_max_q[i]];

		if (pre_max_p[i]>pre_max_q[i]) {
			// cout<<"choose p "<<endl;
			r[i] = power2mod(p[max_p_index]) + power2mod(q[i-max_p_index]);
		}else if (pre_max_p[i]<pre_max_q[i]){
			// cout<<"choose q "<<endl;
			r[i] = power2mod(q[max_q_index]) + power2mod(p[i-max_q_index]);
		}else {
			// cout<<"choose equal "<<endl;
			// ==
			// cout<<"i = "<<i<<endl;
			int mx_value = pre_max_p[i];
			int index_p = idx_p[mx_value];
			int index_q = idx_q[mx_value];
			// cout<<"index p ="<< index_p<<endl;
			// cout<<"index q ="<< index_q<<endl;
			r[i] = power2mod(mx_value) + power2mod(max(p[i-index_q],q[i-index_p]));
			// cout<<"2^"<<mx_value<<" + 2^"<<max(p[i-index_q],q[i-index_p])<<" = "<<r[i]<<endl;
		}
		r[i]%=MOD;
	}
	print(r.begin(), r.end());
	cout<<endl;
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
