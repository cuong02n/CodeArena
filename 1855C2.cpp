/*
    author : cuong2905say
    created : 29-07-2023  22:15:38  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T1, class T2>
ostream& operator<<(ostream& os, pair   <T1, T2> A) {
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

using p = pair<int, int>;
void add_build(vector<p>& ans, int i, int j) {
    ans.push_back({i, j});
}
void _add(int A[], vector<p>& res, int i, int j) {
    A[i] += A[j];
    res.push_back({i, j});
}
void _print(int n, int A[], int line) {
    cout << "line : " << line << endl;
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
vector<p> number_to_build_positive(int x0, int ind_x0, int target) {
    vector<p> ans;
    int k = x0;
    while (k < -target) {
        add_build(ans, ind_x0, ind_x0);
        k *= 2;
    }
    return ans;
}

vector<p> number_to_build_negative(int x0, int ind_x0, int target) {
    vector<p> ans;
    int k = x0;
    while (-k < target) {
        add_build(ans, ind_x0, ind_x0);
        k += k;
    }
    return ans;
}

void solve_full_nega(int n, int A[], vector<p>& res) {
    // cout << "solve nega" << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;
    for (int i = n - 1; i >= 1; i--) {
        _add(A, res, i, i + 1);
    }
}

void solve_full_posi(int n, int A[], vector<p>& res) {
    // cout << "solve posi " << endl;
    // for (int i = 1; i <= n; i++) {
    // cout << A[i] << " ";
    // }
    // cout << endl;
    for (int i = 2; i <= n; i++) {
        _add(A, res, i, i - 1);
    }
}

int MOD = 1e9 + 7;
int verbose = -1;

void process(int A[], vector<p>& target, vector<p>& res) {
    for (int i = 0; i < target.size(); i++) {
        _add(A, res, target[i].first, target[i].second);
    }
}

void solve(bool v = false, int all_case = -1) {
    int n;
    cin >> n;
    int A[n + 1];
    int num0 = 0;
    int positive = 0;
    int negative = 0;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] == 0) {
            num0++;
        } else if (A[i] > 0) {
            positive++;
        } else {
            negative++;
        }
    }

    int is_sorted = 1;
    for (int i = 1; i <= n - 1; i++) {
        if (A[i] > A[i + 1]) {
            is_sorted = 0;
        }
    }
    if (is_sorted) {
        cout << 0 << endl;
        return;
    }
    vector<p> res;
    if (positive == 0) {
        solve_full_nega(n, A, res);
    } else if (negative == 0) {
        solve_full_posi(n, A, res);
    } else {
        int most_nega = 1;
        int second_nega = 1;
        for (int i = 1; i <= n; i++) {
            if (A[i] < A[most_nega]) {
                most_nega = i;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (A[i] < A[second_nega] && i != most_nega) {
                second_nega = i;
            }
        }
        int most_posi = 1;
        for (int i = 1; i <= n; i++) {
            if (A[most_posi] < A[i]) {
                most_posi = i;
            }
        }
        int second_posi = 1;
        for (int i = 1; i <= n; i++) {
            if (A[second_posi] < A[i] && i != most_posi) {
                second_posi = i;
            }
        }
        vector<p> res_build_nega = number_to_build_negative(A[most_nega], most_nega, A[most_posi]);
        vector<p> res_build_posi = number_to_build_positive(A[most_posi], most_posi, A[most_nega]);
        if (res_build_nega.size() + positive <= 12) {
            process(A, res_build_nega, res);
            int most_nega_new = 1;
            for (int i = 1; i <= n; i++) {
                if (A[most_nega_new] > A[i]) {
                    most_nega_new = i;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (A[i] > 0) {
                    _add(A, res, i, most_nega_new);
                }
            }
            solve_full_nega(n, A, res);
        } else {
            process(A, res_build_posi, res);

            int most_posi_new = 1;
            for (int i = 1; i <= n; i++) {
                if (A[most_posi_new] < A[i]) {
                    most_posi_new = i;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (A[i] < 0) {
                    _add(A, res, i, most_posi_new);
                }
            }
            solve_full_posi(n, A, res);
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