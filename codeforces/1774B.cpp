/*
    author : cuong2905say
    created : 23-08-2023  08:40:34  UTC: +7
*/
#include <bits/stdc++.h>

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
void _print(it begin, it end) {
    for (it i = begin; i != end; i++) {
        cout << *i << " ";
    }
}

void _verbose() {
}

int MOD = 1e9 + 7;
int verbose = -1;
int all_cases = -1;

bool is(int res[], int n, int k) {
    set<int> a;
    int i = 0;
    for (; i < k; i++) {
        if (a.find(res[i]) == a.end()) {
            a.insert(res[i]);
        } else {
            return false;
        }
    }
    while (i < n) {
        a.erase(res[i - k]);
        if (a.find(res[i]) == a.end()) {
            a.insert(res[i]);
        } else {
            return false;
        }
        i++;
    }
    return true;
}
int nxt(int i, int n, int k, queue<int> z) {
    if (i + k >= n) {
        return z.front();
    }
    return i + k;
}

void solve(bool v = false, int all_case = -1) {
    int n, m, k;
    cin >> n >> m >> k;
    int A[m];
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }
    sort(A, A + m, greater<int>());
    int res[n] = {};
    set<int> z;
    for (int i = 0; i < n; i++) {
        z.push(i);
    }
    int indx = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < A[i]; j++) {
            res[indx] = i + 1;
            
            indx = nxt(indx, n, k);
            while (res[indx] != 0) {
                indx++;
            }
        }
    }
    cout << (is(res, n, k) ? "YES" : "NO") << endl;
    if (!v && all_case == all_cases) {
        return;
    }
    if (v && all_case == all_cases) {
        _verbose();
    }
}

void reset() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    chrono::steady_clock::time_point start = chrono::steady_clock::now();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
#ifndef ONLINE_JUDGE
        cout << "case " << i + 1 << ": ";
#endif
        if (verbose == i + 1) {
            solve(true, t);
        } else {
            solve(false, t);
        }
        reset();
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
#ifndef ONLINE_JUDGE
    chrono::duration<double> time_span = chrono::duration_cast<std::chrono::duration<double>>(end - start);
    cout << "time use: " << time_span.count() << endl;
#endif

    return 0;
}
