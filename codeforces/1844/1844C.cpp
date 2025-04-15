/*
    author : cuong2905say
    created : 25-07-2023  20:08:07  UTC: +7
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

template <class T>
T kadane(T A[], int size) {
    T max_ending_here = 0;
    T MAX = 0;
    for (int i = 0; i < size; i++) {
        max_ending_here += A[i];
        if (max_ending_here < 0) {
            max_ending_here = 0;
        } else if (max_ending_here > MAX) {
            MAX = max_ending_here;
        }
    }
    if (MAX == 0) {
        MAX = LLONG_MIN;
        for (int i = 0; i < size; i++) {
            MAX = max(MAX, A[i]);
        }
    }
    return MAX;
}

void solve(bool verbose = false) {
    int n;
    cin >> n;
    ll A[n / 2 + n % 2];
    ll B[n / 2 + n % 2];
    int a = n / 2 + n % 2;
    int b = n / 2;
    for (int i = 0; i < n / 2; i++) {
        cin >> A[i];
        cin >> B[i];
    }
    if (n % 2) {
        cin >> A[n / 2 + n % 2 - 1];
    }
    ll resA = kadane(A, n / 2 + n % 2);
    ll resB = (n == 1) ? LLONG_MIN : kadane(B, n / 2);

    cout << max(resA, resB) << endl;
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
        cout << "case " << i + 1 << ": ";
#endif
        solve();
        reset();
    }

    return 0;
}
