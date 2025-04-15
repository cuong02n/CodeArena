/*
    author : cuong2905say
    created : 11-09-2022  00:04:34    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case
vector<int> A;
long long B[300001];
int main() {
    char c = 'z';
    A.clear();

    while (1) {
        scanf("%c", &c);
        if (c != '\n' && c != ' ') {
            A.push_back(c - '0');
        } else {
            break;
        }
    }
    for (int i = 0; i < 300001; i++) {
        B[i] = 0;
    }
    if (A[0] % 4) {
        B[0] = 0;
    } else {
        B[0] = 1;
    }
    for (int i = 1; i < A.size(); i++) {
        if (A[i] % 4 == 0) {
            if (A[i - 1] % 2) {
                B[i] = B[i - 1] + 1;
            } else {
                B[i] = B[i - 1] + i + 1;
            }
        } else {
            if ((A[i] + A[i - 1] * 10) % 4) {
                B[i] = B[i - 1];
            } else {
                B[i] = B[i - 1] + i;
            }
        }
    }
    cout << B[A.size() - 1] << endl;
    system("pause");
    return 0;
}