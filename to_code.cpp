#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("output.txt", "w", stdout);
    cout << "\"";
    while (1) {
        char c;
        scanf("%c", &c);
        if (c == '@') {
            break;
        } else if (c == '\n') {
            cout << "\",\n\"";
        } else if (c == '\"') {
            cout << "\\\"";
        } else {
            cout << c;
        }
    }

    cout << "\"";
    return 1;
}
