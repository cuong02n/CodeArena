/*
    author : cuong2905say
    created : 29-07-2023  21:57:47  UTC: +7
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
int verbose = -1;
using p = pair<int, int>;
void add(int A[], vector<p>& res, int i, int j) {
    A[i] += A[j];
    res.push_back({i, j});
}
void solve(bool v = false) {
    int n;
    cin >> n;
    int A[n + 1];
    int _min = INT_MAX;
    int _ind_min = -1;
    int _max = INT_MIN;
    int _ind_max = -1;
    for (int i = 1; i < n + 1; i++) {
        cin >> A[i];
        if (A[i] < _min) {
            _min = A[i];
            _ind_min = i;
        }
        if (A[i] > _max) {
            _max = A[i];
            _ind_max = i;
        }
    }
    vector<p> res;
    if (_max >= -_min) {
        // add to all A[i] with max
        for (int i = 1; i <= n; i++) {
            add(A, res, i, _ind_max);
        }
        for (int i = 2; i <= n; i++) {
            add(A, res, i, i - 1);
        }
    } else {
        // add to all A[i] with min
        for (int i = 1; i <= n; i++) {
            add(A, res, i, _ind_min);
        }
        for (int i = n - 1; i >= 1; i--) {
            add(A, res, i, i + 1);
        }
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << " " << res[i].second << endl;
    }
    if (v) {
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
            solve(true);
        } else {
            solve();
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
