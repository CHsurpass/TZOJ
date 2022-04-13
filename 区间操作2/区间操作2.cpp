#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define ll long long
#define Mod 998244353
#define ls id<<1
#define rs id<<1|1
#define mid (l+r)/2
#define scanf scanf_s

ll add[N << 2];
ll mul[N << 2];
ll sum[N << 2];
void Push_up(ll id) { sum[id] = sum[ls] + sum[rs]; }
void update(ll id, ll lazyadd, ll lazymul, ll len) {
    sum[id] = sum[id] * lazymul + lazyadd * len;
    mul[id] = mul[id] * lazymul;
    add[id] = add[id] * lazymul + lazyadd;
    return;
}
void Push_down(ll ln, ll rn, ll id) {
    update(ls, add[id], mul[id], ln);
    update(rs, add[id], mul[id], rn);
    add[id] = 0;
    mul[id] = 1;
}
void Build(ll l, ll r, ll id) {
    mul[id] = 1;
    if (l == r) {
        scanf("%I64d", &sum[id]);
        return;
    }
    Build(l, mid, ls);
    Build(mid + 1, r, rs);
    Push_up(id);
}
void Ch(ll id, ll l, ll r, ll L, ll R, ll val, char c) {
    if (L <= l && R >= r) {
        if (c == 'M') {
            sum[id] = sum[id] * val;
            mul[id] = mul[id] * val;
            add[id] = add[id] * val;

        }
        else {
            sum[id] = sum[id] + val * (r - l + 1);
            add[id] = add[id] + val;
        }
        return;
    }
    if (add[id] != 0 || mul[id] != 1)
        Push_down(mid - l + 1, r - mid, id);
    if (L <= mid) Ch(ls, l, mid, L, R, val, c);
    if (mid < R) Ch(rs, mid + 1, r, L, R, val, c);
    Push_up(id);
}
ll ans;
void Query(ll l, ll r, ll id, ll L, ll R) {
    if (L <= l && R >= r) {
        ans += sum[id];
        return;
    }
    if (add[id] != 0 || mul[id] != 1)
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
        if (c[0] == 'Q') Query(1, n, 1, L, R), printf("%I64d\n", ans);
        else {
            scanf("%I64d", &date);
            Ch(1, 1, n, L, R, date, c[0]);
        }
    }
    return 0;
}