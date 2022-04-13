#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
#define inf 0x3f3f3f3f
struct Node {
    int x, y;
    bool operator < (const Node a) {
        return x < a.x;
    }
}a[N];
int main() {
    int n, s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n);
    int nowr = s;
    int mxr = -inf;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (nowr >= t) break;
        if (a[i].x <= nowr) {
            mxr = max(a[i].y, mxr);
        }
        else if (a[i].x <= mxr) {
            nowr = mxr;
            mxr = max(a[i].y, mxr);
            cnt++;
        }
        else break;
    }
    if (nowr >= t) cout << cnt << endl;
    else if (mxr >= t) cout << cnt + 1 << endl;
    else cout << "No Solution" << endl;
    return 0;
}