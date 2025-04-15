/*
    author : cuong2905say
    created : 31-08-2023  21:53:20  UTC: +7
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()

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
void precalc() {
}
void solve(bool v = false, int all_case = -1) {
    string x;
    cin >> x;
    set<int> ind0;
    int min_sorted = 0;
    int tmp_sorted = 0;
    bool res = true;
    for (int i = 0, cur_size = 0, last_cmp = -1, lst_sorted = 0; i < x.length(); i++) {
        if (x[i] == '+') {
            cur_size++;
        }
        if (x[i] == '-') {
            ind0.erase(cur_size);
            cur_size--;
        }
        if (last_cmp == 1) {
            // lst_sorted
            if (x[i] == '+') {
                tmp_sorted++;
            } else if (x[i] == '-') {
                tmp_sorted--;
            }
            min_sorted = min(min_sorted, tmp_sorted);
        }

        if (x[i] == '1') {
            lst_sorted = cur_size;
            min_sorted = cur_size;
            tmp_sorted = cur_size;
            last_cmp = 1;
            if (ind0.empty()) continue;
            if (*(ind0.begin()) <= cur_size) res = false;
        } else if (x[i] == '0') {
            last_cmp = 0;
            if (cur_size < 2) res = false;
            ind0.insert(cur_size);
            // cout << "current size = " << cur_size << " min_st" << min_sorted << endl;
            if (cur_size <= min_sorted) res = false;
        }
        // cout << "after index " << i << ", 2 sets are: " << endl;
        // _print(ind0.begin(), ind0.end());
        // cout << endl;
        // _print(ind1.begin(), ind1.end());
        // cout << endl;
    }
    cout << (res ? "YES" : "NO") << endl;
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

    precalc();
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
