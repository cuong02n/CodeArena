#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()

using namespace std;
using ll = long long;
using ull = unsigned long long;

int N;
int LOG;
vector<int> bitCnt;
vector<ll> bitSum;

void add(int i, int val) {
    for (; i <= N; i += i & (-i)) {
        bitCnt[i]++;
        bitSum[i] += val;
    }
}

int need_cnt(ll need) {
    int p = 0, cnt = 0;
    ll rem = need;
    for (int pw = LOG; pw; pw >>= 1) {
        if (p + pw <= N && bitSum[p + pw] < rem) {
            rem -= bitSum[p + pw];
            cnt += bitCnt[p + pw];
            p += pw;
        }
    }
    return cnt + 1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    N = n * m;
    vector<int> a(N);
    vector<pair<int, int>> ord(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        ord[i] = {a[i], i};
    }
    sort(all(ord), greater<pair<int, int>>());

    vector<int> rk(N);
    for (int r = 0; r < N; r++) rk[ord[r].second] = r + 1;

    bitCnt.assign(N + 1, 0);
    bitSum.assign(N + 1, 0);
    LOG = 1;
    while ((LOG << 1) <= N) LOG <<= 1;

    int ans = m;
    ll tot = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            int idx = i * m + j;
            add(rk[idx], a[idx]);
            tot += a[idx];
        }
        if (tot >= v[i]) ans = min(ans, need_cnt(v[i]));
    }

    cout << ans << "\n";
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
