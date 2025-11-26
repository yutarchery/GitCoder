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

int n, m, k, r[1005], p[1005];

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
  }
  sort(r + 1, r + n + 1, greater<int>());
  for (int i = 1; i <= m; i++) {
    cin >> p[i];
  }
  sort(p + 1, p + m + 1, greater<int>());

  ll ans = -1, sum1 = 0, sum2 = 0;
  bool flag1 = true, flag2 = true;

  for (int i = 1; i <= k; i++) {
    if (i % 2 == 1) {
      sum1 += r[(i + 1) / 2];
      sum2 += p[(i + 1) / 2];

      if ((i + 1) / 2 > n) {
        flag1 = false;
      }
      if ((i + 1) / 2 > m) {
        flag2 = false;
      }
    } else {
      sum1 += p[(i + 1) / 2];
      sum2 += r[(i + 1) / 2];

      if ((i + 1) / 2 > m) {
        flag1 = false;
      }
      if ((i + 1) / 2 > n) {
        flag2 = false;
      }
    }
  }
  if (flag1) {
    ans = max(ans, sum1);
  }
  if (flag2) {
    ans = max(ans, sum2);
  }
  cout << ans << endl;

  return 0;
}
