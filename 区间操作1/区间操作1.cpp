#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define ll long long
#define inf 0x3f3f3f3f
#define scanf scanf_s

int a[N];
ll sum1[N];
ll sum2[N];
int n, m;
int lowbit(int x) {
    return x & -x;
}
void updata(int i, ll k) {
    int x = i;
    while (i <= n) {
        sum1[i] += k;
        sum2[i] += k * (x - 1);
        i += lowbit(i);
    }
}
ll getsum(int i) {
    ll res = 0, x = i;
    while (i > 0) {
        res += x * sum1[i] - sum2[i];
        i -= lowbit(i);
    }
    return res;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        updata(i, a[i] - a[i - 1]);
    }
    char s[2];
    int x, l, r, d;
    while (m--) {
        scanf("%s", s);
        if (strcmp(s, "Q") == 0) {
            scanf("%d", &x);
            printf("%I64d\n", getsum(x) - getsum(x - 1));
        }
        else if (strcmp(s, "C") == 0) {
            scanf("%d %d %d", &l, &r, &d);
            updata(l, d);
            updata(r + 1, -d);
        }
    }
    return 0;
}
