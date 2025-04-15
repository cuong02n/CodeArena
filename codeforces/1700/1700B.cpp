/*
        author : cuong2905say
        created : 22-09-2022  14:20:23  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

struct bigint {
    string c;
};
bigint operator+(bigint i1, bigint i2) {
    string res = "";
    int carry = 0;
    for (int i = i1.c.length() - 1; i >= 0; --i) {
        int x = (i1.c)[i] - '0' + (i2.c)[i] - '0';
        x += carry;
        res = to_string(x % 10).append(res);
        carry = x / 10;
    }
    if (carry) {
        res = to_string(1).append(res);
    }
    bigint v;
    v.c = res;
    return v;
}
bigint
operator-(bigint i1, bigint i2) {
    // i1.length = i2.length
    string res = "";
    int carry = 0;
    for (int i = i2.c.length() - 1; i >= 0; i--) {
        // i1 -i2;
        int x;
        if (i2.c.length() < i1.c.length()) {
            x = (i1.c)[i + 1] - (i2.c)[i];
        } else {
            x = (i1.c)[i] - (i2.c)[i];
        }
        x -= carry;
        if (x < 0) {
            x += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res = to_string(x).append(res);
    }
    bigint v = {res};
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        string c;
        int n;
        cin >> n;
        cin >> c;
        if (c[0] == '9') {
            string a = "";
            a.append(c.length() + 1, '1');
            bigint i1 = {a};
            bigint i2 = {c};
            cout << (i1 - i2).c << endl;
        } else {
            string a = "";
            a.append(c.length(), '9');
            bigint i1 = {a};
            bigint i2 = {c};
            cout << (i1 - i2).c << endl;
        }
    }
    system("pause");
    return 0;
}
