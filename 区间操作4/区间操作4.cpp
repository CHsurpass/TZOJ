#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define ll long long
#define Mod 998244353
#define ls id<<1
#define rs id<<1|1
#define mid (l+r)/2
#define scanf scanf_s

ll add[N << 2];
ll sum[N << 2];
void Push_up(ll id) { sum[id] = sum[ls] + sum[rs]; }
void update(ll id, ll lazyadd, ll len) {
    sum[id] = sum[id] + lazyadd * len;
    add[id] = add[id] + lazyadd;
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
        return;
    }
    Build(l, mid, ls);
    Build(mid + 1, r, rs);
    Push_up(id);
}
void Update(ll id, ll l, ll r, ll L, ll val, char c) {
    if (L == l && L == r) {
        if (c == 'M') {
            sum[id] = sum[id] * val;
            add[id] = add[id] * val;
        }
        else {
            sum[id] = sum[id] + val * (r - l + 1);
            add[id] = add[id] + val;
        }
        return;
    }
    if (add[id] != 0)
        Push_down(mid - l + 1, r - mid, id);
    if (L <= mid) Update(ls, l, mid, L, val, c);
    if (mid < L) Update(rs, mid + 1, r, L, val, c);
    Push_up(id);
}
ll ans;
void Query(ll l, ll r, ll id, ll L, ll R) {
    if (L <= l && R >= r) {
        ans += sum[id];
        return;
    }
    if (add[id] != 0)
        Push_down(mid - l + 1, r - mid, id);
    if (L <= mid) Query(l, mid, ls, L, R);
    if (mid < R) Query(mid + 1, r, rs, L, R);
}
int main() {
    ll n, m;
    scanf("%I64d %I64d", &n, &m);
    Build(1, n, 1);
    ll R, L, date;
    char c[2];
    while (m--) {
        ans = 0;
        scanf("%s %I64d %I64d", c, &L, &R);
        if (c[0] == '2') Query(1, n, 1, L, R), printf("%I64d\n", ans);
        else {
            Update(1, 1, n, L, R, c[0]);
        }
    }
    return 0;
}
