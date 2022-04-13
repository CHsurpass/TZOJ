#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N1 = 1e1 + 5;
const int N2 = 1e2 + 5;
const int N3 = 1e3 + 5;
const int N4 = 1e4 + 5;
const int N5 = 1e5 + 5;
const int N6 = 1e6 + 5;
const int N7 = 1e7 + 5;
int n,m;

#define mod 1000000007
int f[N3][N2][N2];
void Input() {
	cin >> n >> m;
	return;
}
int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}
void Solve() {
	f[0][0][2] = 1;
	for (int i = 1; i <= n + m; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= m+1; k++) {
				if (f[i - 1][j][k]) {
					if(i-j <= n)
						f[i][j][min(k << 1, m + 1)] = add(f[i][j][min(k << 1, m + 1)], f[i - 1][j][k]);
					if (k)
						f[i][j + 1][k - 1] = add(f[i][j + 1][k - 1], f[i - 1][j][k]);
				}
			}
		}
	}
	cout << f[n + m - 1][m - 1][1] << endl;
	return;
}
void Print() {
	return;
}
int main() {
	Input();
	Solve();
	Print();
	return 0;
}