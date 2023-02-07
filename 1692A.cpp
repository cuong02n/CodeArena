#include <stdio.h>
int x = 1;
int main() {
    int a[4];
    int t;  // test case
    scanf("%d", &t);
    while (t--) {
        int res = 0;
        scanf("%d", &a[0]);
        for (int i = 1; i < 4; i++) {
            scanf("%d", &a[i]);
            if (a[i] > a[0]) {
                res++;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
