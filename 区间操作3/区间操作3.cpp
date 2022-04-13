#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define ll long long
#define Mod 998244353
#define ls id<<1
#define rs id<<1|1
#define mid (l+r)/2
#define inf 1000000005
#define scanf scanf_s

ll add[N << 2];
ll sum[N << 2];
ll mi[N << 2], mx[N << 2];
void Push_up(ll id) {
    sum[id] = sum[ls] + sum[rs];
    mi[id] = min(mi[ls], mi[rs]);
    mx[id] = max(mx[ls], mx[rs]);
}
void update(ll id, ll lazyadd, ll len) {
    sum[id] = sum[id] + lazyadd * len;
    add[id] = add[id] + lazyadd;
    mi[id] = mi[id] + lazyadd;
    mx[id] = mx[id] + lazyadd;
    return;
}
void Push_down(ll ln, ll rn, ll id) {
    update(ls, add[id], ln);
    update(rs, add[id], rn);
    add[id] = 0;
}
void Build(ll l, ll r, ll id) {
    if (l == r) {
        scanf("%I64d", &sum[id]);
        mi[id] = mx[id] = sum[id];
        return;
    }
    Build(l, mid, ls);
    Build(mid + 1, r, rs);
    Push_up(id);
}
void Add(ll id, ll l, ll r, ll L, ll R, ll val) {
    if (L <= l && R >= r) {
        sum[id] = sum[id] + val * (r - l + 1);
        add[id] = add[id] + val;
        mi[id] = mi[id] + val;
        mx[id] = mx[id] + val;
        return;
    }
    if (add[id] != 0)
        Push_down(mid - l + 1, r - mid, id);
    if (L <= mid) Add(ls, l, mid, L, R, val);
    if (mid < R) Add(rs, mid + 1, r, L, R, val);
    Push_up(id);
}
ll ans, mii, mxx;
void Query(ll l, ll r, ll id, ll L, ll R, char c) {
    if (L <= l && R >= r) {
        if (c == 'N') {
            mii = min(mii, mi[id]);
        }
        else if (c == 'X') {
            mxx = max(mxx, mx[id]);
        }
        else {
            ans += sum[id];
        }
        return;
    }
    if (add[id] != 0)
        Push_down(mid - l + 1, r - mid, id);
    if (L <= mid) Query(l, mid, ls, L, R, c);
    if (mid < R) Query(mid + 1, r, rs, L, R, c);
}
int main() {
    ll n, m;
    scanf("%I64d %I64d", &n, &m);
    Build(1, n, 1);
    ll R, L, date;
    char c[2];
    while (m--) {
        ans = 0;
        mii = inf;
        mxx = -1;
        scanf("%s %I64d %I64d", c, &L, &R);
        if (c[0] == 'C') {
            scanf("%I64d", &date);
            Add(1, 1, n, L, R, date);
        }
        else {
            Query(1, n, 1, L, R, c[0]);
            if (c[0] == 'N') printf("%I64d\n", mii);
            else if (c[0] == 'X') printf("%I64d\n", mxx);
            else printf("%I64d\n", ans);
        }
    }
    return 0;
}

