/*
    author : cuong2905say
    created : 11-09-2022  23:10:31    UTC: +7
*/
#include <bits/stdc++.h>
int modulo = (int)1e9 + 7;
inline int add_modulo(int a, int b, int P = modulo) {
    return (a % P + b % P) % P;
}
int mul_modulo(int a, int b, int P = modulo) {
    long long T = 1LL * a * 1LL * b;
    return (int)(T % (long long)P);
}

using namespace std;
int t = 0;  // test case
int A[100001];
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // auto i = freopen("output.txt", "r+", stdin);
    // ifstream input_data;
    // input_data.open("output.txt");
    A[0] = 0;
    A[1] = 0;
    A[2] = 2;
    A[3] = 3;
    A[4] = 5;
    for (int i = 5; i < 100001; i++) {
        A[i] = add_modulo(A[i - 1], A[i - 2], modulo);
    }
    // cout << A[100000];
    string c = "";
    cin >> c;
    int res = 1;
    int count_u = 0;
    int count_n = 0;
    if (c[0] == 'u') {
        count_u++;
    }
    if (c[0] == 'n') {
        count_n++;
    }
    for (int i = 1; i < c.length(); i++) {
        // cout << "count_n " << count_n << " count_u " << count_u << endl;
        if (c[i] != 'u' && c[i] != 'n') {
            if (count_u >= 2) {
                res = mul_modulo(res, A[count_u]);
            }
            if (count_n >= 2) {
                res = mul_modulo(res, A[count_n]);
            }
            count_u = 0;
            count_n = 0;
        } else if (c[i] == 'u') {
            if (count_n >= 2) {
                res = mul_modulo(res, A[count_n]);
            }
            count_n = 0;
            count_u++;
        } else {
            if (count_u >= 2) {
                res = mul_modulo(res, A[count_u]);
            }
            count_u = 0;
            count_n++;
        }
    }
    if (count_u >= 2) {
        res = mul_modulo(res, A[count_u]);
    } else if (count_n >= 2) {
        res = mul_modulo(res, A[count_n]);
    }
    for (int i = 0; i < c.length(); i++) {
        if (c[i] == 'm' || c[i] == 'w') {
            res = 0;
        }
    }
    if (c.length() == 100000) {
        cout << "count_n " << count_n << " count_u " << count_u << endl;
        int _n = 0;
        int _u = 0;
        for (int i = 0; i < 61875; i++) {
            if (c[i] == 'n') {
                _n++;
            }
            if (c[i] == 'u') {
                _u++;
            }
        }
        cout << "n : " << _n << " u : " << _u << endl;
    }
    cout << res << endl;
    system("pause");
    return 0;
}