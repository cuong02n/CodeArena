/*
    author : cuong2905say
    created : 21-07-2023  23:09:53  UTC: +7
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
void solve(bool verbose = false) {
    int n;
    cin >> n;
    int A[n + 1] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > n) {
            continue;
        }
        A[x]++;
    }
   
    int B[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            B[j] += A[i];
        }
    }
  
    int MAX = INT_MIN;
    for (int i = 0; i < n + 1; i++) {
        MAX = max(MAX, B[i]);
    }
    cout << MAX << endl;
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

    int t = 1;
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
