#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
#define ll long long
#define scanf scanf_s
int T;
int vew[N];
int n, m;
int maxr = 0;
int lazy[N << 2];
struct node {
    int l, r;
    int c;
    bool operator<(const node a) const {
        if (a.r != r)
            return r < a.r;
        return 0;
    }
}a[N];
int c[N << 2];
void push_up(int id) {
    c[id] = c[id << 1] + c[id << 1 | 1];
}
void push_down(int id, int ln, int rn) {
    if (lazy[id]) {
        lazy[id << 1] = lazy[id << 1 | 1] = 1;
        c[id << 1] = ln;
        c[id << 1 | 1] = rn;
        lazy[id] = 0;
    }
}
void updata(int id, int l, int r, int L, int R) {
    if (l <= L && r >= R) {
        c[id] = R - L + 1;
        lazy[id] = 1;
        return;
    }
    int mid = L + R >> 1;
    push_down(id, mid - L + 1, R - mid);
    if (l <= mid)
        updata(id << 1, l, r, L, mid);
    if (r > mid)
        updata(id << 1 | 1, l, r, mid + 1, R);
    push_up(id);
}
int ans;
void query(int id, int l, int r, int L, int R) {
    if (l <= L && r >= R) {
        ans += c[id];
        return;
    }
    int mid = L + R >> 1;
    push_down(id, mid - L + 1, R - mid);
    if (l <= mid)
        query(id << 1, l, r, L, mid);
    if (r > mid)
        query(id << 1 | 1, l, r, mid + 1, R);
}
bool Check(int mid, int id) {
    ans = 0;
    query(1, mid, a[id].r, 1, maxr);
    if (a[id].r - mid + 1 - ans >= a[id].c)
        return true;
    return false;
}
int main() {
    ///freopen("C:\\Users\\xhua1\\Desktop\\6546\\z_big_input.in","r",stdin);
    scanf("%d", &n);
    for (int i = 0, x, y, z; i < n; i++) {
        scanf("%d %d %d", &x, &y, &z);
        maxr = max(y, maxr);
        a[i] = { x,y,z };
    }
    sort(a, a + n);
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ans = 0;
        int len = a[i].c;
        query(1, a[i].l, a[i].r, 1, maxr);
        a[i].c = max(0, a[i].c - ans);
        int l = a[i].l;
        int r = a[i].r;
        while (l <= r) {
            int mid = l + r >> 1;
            if (Check(mid, i)) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (a[i].c) {
            ans = 0;
            query(1, r, a[i].r, 1, maxr);

            ret += a[i].r - r + 1 - ans;
            updata(1, r, a[i].r, 1, maxr);
        }
    }
    printf("%d\n", ret);
    return 0;
}