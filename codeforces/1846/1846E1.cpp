/*
    author : cuong2905say
    created : 20-07-2023  08:10:57  UTC: +7
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

__int128_t expd(__int128_t base, int e) {
    if (e == 0) {
        return 1;
    }
    if (e == 1) {
        return base;
    }
    __int128_t u = expd(base, e / 2);
    return u * u * expd(base, e % 2);
}

int check(ll target, int base, int e) {
    __int128_t res = expd(base, e);  // loge
    __int128_t cal = (res - 1) / (base - 1);
    if (target == cal) {
        return 0;
    }
    if (cal > target) {
        return -1;
    }
    return 1;
}

bool search(ll target, int e, int first, int last) {
    if (first < last) {
        int f = check(target, first, e);
        int l = check(target, last, e);
        if (f * l == 0) {
            return true;
        }
        int mid = (first + last) / 2;
        int m = check(target, mid, e);
        if (m == 0) {
            return true;
        }
        if (m < 0) {
            return search(target, e, first, mid - 1);
        }
        return search(target, e, mid + 1, last);
    }
    return false;
}

void solve(bool verbose = false) {
    ll v;
    cin >> v;
    for (int i = 3; i <= 60; i++) {
        double max = pow((double)v, 1.0 / (i - 1)) + 1;
        if (search(v, i, 2, max)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

void reset() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
#ifndef ONLINE_JUDGE
        cout << "case " << i + 1 << ": ";
#endif
        solve();
        reset();
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

#ifndef ONLINE_JUDGE
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    cout << "time use: " << time_span.count() << endl;
#endif  // !

    return 0;
}
