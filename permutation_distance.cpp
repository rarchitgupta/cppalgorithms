#include<bits/stdc++.h>
using namespace std;
typedef long double db;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<db, db> pdd;
#define fi first
#define se second
#define empb emplace_back
#define all(x) (x).begin(),(x).end()
const int N = 1e5 + 10;
const int LOGN = 18;
int nxt[N][LOGN];
int pre[N], gsu[N], p[N], a[N];
int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _; cin >> _;
	while(_--) {
		int n, q; cin >> n >> q;
		for(int i = 1; i <= n; i++) cin >> a[i], p[a[i]] = i;
		for(int i = 1; i <= n; i++) {
			pre[i] = i;
			if(i > 1 && a[pre[i - 1]] < a[i]) pre[i] = pre[i - 1];
		}
		for(int i = n; i; i--) {
			gsu[i] = p[i];
			if(i < n) gsu[i] = max(p[i], gsu[i + 1]);
		}
		for(int i = 1; i <= n; i++) nxt[i][0] = gsu[a[pre[i]]];
		int lgn = __lg(n) + 1;
		for(int j = 1; j <= lgn; j++)
			for(int i = 1; i <= n; i++)
				nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
		auto solve = [&](int l, int r) {
			if(l == r) return 0;
			if(l > r) swap(l, r);
			if(a[l] < a[r]) return 1;
			int ret = 0;
			for(int i = lgn; i >= 0; i--) {
				if(nxt[l][i] < r) {
					l = nxt[l][i];
					ret += 2 << i;
				}
			}
			if(nxt[l][0] < r) return -1;
			l = pre[l]; ret += 2;
			if(a[l] > a[r]) ret++;
			return ret;
		};
		while(q--) {
			int l, r; cin >> l >> r;
			if(l > r) swap(l, r);
			int ans = solve(l, r);
			if(ans != -1) ans = min(ans, solve(gsu[a[l]], r) + 1);
			cout << ans << '\n';
		}
	}
	return 0;
}
/*
1
4 1
1 4 2 3
2 3
*/