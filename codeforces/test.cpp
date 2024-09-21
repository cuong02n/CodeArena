#include <bits/stdc++.h>
using namespace std;
int main() {
    int a = 45, b = 63;
    while (a > 10) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    cout << b;
    system("pause");
}