/*
    author : cuong2905say
    problem: Codeforces 2254B
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

int MOD = 998244353;

bool is_completed(string s1, string s2) {
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '?' || s2[i] == '?') {
            continue;
        }
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;

    string s_arr[] = {"00", "01", "10", "11"};

    for (int i = 0; i < 4; i++) {
        for (int j = 2; j < n; j++) {
            if(s_arr[i][j-1] == '0' && s_arr[i][j-2] == '0'){
                s_arr[i] += '1';
            }else if (s_arr[i][j-1] == '1' && s_arr[i][j-2] == '1'){
                s_arr[i] += '0';
            }else if(s_arr[i][j-1] == '0' && s_arr[i][j-2] == '1'){
                s_arr[i] += '0';
            }else if(s_arr[i][j-1] == '1' && s_arr[i][j-2] == '0'){
                s_arr[i] += '1';
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        if (is_completed(s, s_arr[i])) {
            cnt++;
        }
    }
    cout << cnt << endl;
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
