#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, q;
ll a[int(3e5 + 5)], l[int(3e5 + 5)], r[int(3e5 + 5)];

ll sum[int(3e5 + 5)][3];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (ll i = 1; i <= n; i++) {
    sum[i][0] = sum[i - 1][0] + a[i];
    sum[i][1] = sum[i - 1][1] + i * a[i];
    sum[i][2] = sum[i - 1][2] + i * i * a[i];
  }

  for (int i = 1; i <= q; i++) {
    cin >> l[i] >> r[i];
  }

  for (int i = 1; i <= q; i++) {
    ll ans = -1 * (sum[r[i]][2] - sum[l[i] - 1][2]);
    ans += (l[i] + r[i]) * (sum[r[i]][1] - sum[l[i] - 1][1]);
    ans += (-1 * l[i] + 1) * (r[i] + 1) * (sum[r[i]][0] - sum[l[i] - 1][0]);
    cout << ans << endl;
  }

  return 0;
}
