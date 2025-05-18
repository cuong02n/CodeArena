/*
    author : cuong2905say
    created : 19-07-2023  21:49:02  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2> A) {
    os << " { " << A.first << ", " << A.second << " }";
    return os;
}
template <class T1, class T2, class T3>
ostream& operator<<(ostream& os, tuple<T1, T2, T3> A) {
    os << " { " << get<0>(A) << ", " << get<1>(A) << ", " << get<2>(A) << " }";
    return os;
}
template <class T1, class T2, class T3, class T4>
ostream& operator<<(ostream& os, tuple<T1, T2, T3, T4> A) {
    os << " { " << get<0>(A) << ", " << get<1>(A) << ", " << get<2>(A) << ", " << get<3>(A) << " }";
    return os;
}
template <class T>
ostream& operator<<(ostream& os, vector<T> A) {
    os << " vector : ";
    for (auto x : A) {
        os << x << " ";
    }
    return os;
}
template <class T>
ostream& operator<<(ostream& os, set<T> A) {
    os << " set : ";
    for (auto x : A) {
        os << x << " ";
    }
    return os;
}
template <class T>
ostream& operator<<(ostream& os, multiset<T> A) {
    os << " multiset : ";
    for (auto x : A) {
        os << x << " ";
    }
    return os;
}
template <class T>
ostream& operator<<(ostream& os, deque<T> A) {
    os << " deque : ";
    for (auto x : A) {
        os << x << " ";
    }
    return os;
}
template <class T1, class T2>
ostream& operator<<(ostream& os, map<T1, T2> A) {
    os << " map : ";
    for (auto x : A) {
        os << x << " ";
    }
    return os;
}
template <class T1, class T2>
ostream& operator<<(ostream& os, multimap<T1, T2> A) {
    os << " multimap : ";
    for (auto x : A) {
        os << x << " ";
    }
    return os;
}
template <class T1, class T2>
ostream& operator<<(ostream& os, unordered_map<T1, T2> A) {
    os << " unordered_map : ";
    for (auto x : A) {
        os << x << " ";
    }
    return os;
}
template <class T>
ostream& operator<<(ostream& os, priority_queue<T> A) {
    os << " priority_queue : ";
    for (auto x : A) {
        os << x << " ";
    }
    return os;
}

int MOD = 1e9 + 7;
using p = pair<int, ll>;
p get(int m, int h, bool verbose = false) {
    int A[m];
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }
    sort(A, A + m, less<int>());
    int time_use = 0;
    ll pen = 0L;
    int point = 0L;
    for (int i = 0; i < m; i++) {
        if (time_use + A[i] > h) {
            return {point, pen};
        }
        time_use += A[i];
        pen = pen + time_use;
        point++;
    }
    return {point, pen};
}

void solve(bool verbose = false) {
    long n, m, h;
    cin >> n >> m >> h;

    p u = get(m, h, verbose);
    if (verbose) {
        cout << "player " << u << endl;
    }
    int pos = 1;
    for (int i = 1; i < n; i++) {
        p res = get(m, h, verbose);
        if (verbose) {
            cout << "enemy " << res << endl;
        }
        if (u.first < res.first || (u.first == res.first && u.second > res.second))
            pos++;
    }
    cout << pos << endl;
}

void reset() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
#ifndef ONLINE_JUDGE
        cout << "case " << i << ": ";
#endif
        solve();
        reset();
    }

    return 0;
}
