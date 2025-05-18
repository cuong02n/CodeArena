/*
    author : cuong2905say
    created : 19-07-2023  16:16:57  UTC: +7
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
int n = 0;

char A[3][3];

bool valid(int i, int j) {
    return i >= 0 && i < 3 && j >= 0 && j < 3;
}

bool hor_dir_check(int i, int j) {
    char target = A[i][j];
    for (int k = 1; k < 3; k++) {
        if (!valid(i, k + j)) {
            return false;
        }
        if (A[i][k + j] != target) {
            return false;
        }
    }
    return true;
}
bool ver_dir_check(int i, int j) {
    char target = A[i][j];
    for (int k = 1; k < 3; k++) {
        if (!valid(i + k, j)) {
            return false;
        }
        if (A[i + k][j] != target) {
            return false;
        }
    }
    return true;
}
bool diagonal_dir_check(int i, int j) {
    char target = A[i][j];
    for (int k = 1; k < 3; k++) {
        if (!valid(k + i, k + j)) {
            return false;
        }
        if (A[k + i][k + j] != target) {
            return false;
        }
    }
    return true;
}

bool subdiagonal_dir_check(int i, int j) {
    char target = A[i][j];
    for (int k = 1; k < 3; k++) {
        if (!valid(k + i, -k + j)) {
            return false;
        }
        if (A[k + i][-k + j] != target) {
            return false;
        }
    }
    return true;
}

bool single_check(int i, int j) {
    char t = A[i][j];
    if (t == 'X' || t == 'O' || t == '+')
        return subdiagonal_dir_check(i, j) || diagonal_dir_check(i, j) || ver_dir_check(i, j) || hor_dir_check(i, j);
    return false;
}

void check() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (single_check(i, j)) {
                cout << A[i][j] << endl;
                return;
            }
        }
    }
    cout << "DRAW" << endl;
}
void solve(bool verbose = false) {
    cout << flush;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }
    if (verbose) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << A[i][j];
            }
        }
    }
    check();
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
    }

    return 0;
}
