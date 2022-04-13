#include<bits/stdc++.h>
using namespace std;
#define scanf scanf_s
const int N = 1e5 + 5;
struct p {
    int x, y;
}a[N];
bool cmp(p a, p b) {
    return a.x < b.x;
}
int main() {
    int n, ans;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i].x);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i].y);
        sort(a, a + n, cmp);
        ans = 1;
        int mowr = a[0].y;
        for (int i = 1; i < n; i++) {
            if (a[i].x > mowr) {
                ans++;
                mowr = a[i].y;
            }
            else {
                mowr = min(mowr, a[i].y);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}



