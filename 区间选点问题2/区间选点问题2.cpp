#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define mod 1000000000+7
#define inf 0x3f3f3f3f
#define ll long long
#define scanf scanf_s

struct node {
    ll x, y;
    bool operator<(const node a) const{
        return x < a.x;
    }
}a[N];
ll TwoPoint(ll l, ll r, int m, int n) {
    ///二分距离，枚举该距离下区间能选的点大于等于n即可
    ll ans;
    while (l <= r) {
        int cnt = 1;
        ll mid = (l + r) >> 1;
        ll temp = a[0].x;//这是第一个点，cnt初始化故为1
        for (int i = 0; i < m;) {
            if (temp + mid >= a[i].x && temp + mid <= a[i].y) {
                temp = temp + mid;
                cnt++;
            }
            else if (temp + mid > a[i].y && temp + mid < a[i + 1].x && i + 1 < m) {
                temp = a[i + 1].x;
                cnt++;
                i++;
            }
            else i++;
        }
        if (cnt >= n) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    ll mi = 2e18 + 99, mx = 0;
    for (int i = 0; i < m; i++) {
        scanf("%I64d %I64d", &a[i].x, &a[i].y);
        mi = min(a[i].x, mi);
        mx = max(mx, a[i].y);
    }
    sort(a, a + m);
    ll ret = TwoPoint(0, mx - mi, m, n);
    printf("%I64d\n", ret);
    return 0;
}
