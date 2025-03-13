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

int n, l, x[int(1e5 + 5)];
ll t1, t2, t3;

bool hurdle[int(1e5 + 5)];
ll ans[int(1e5 + 5)];

int main() {
  cin >> n >> l;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    hurdle[x[i]] = true;
  }
  cin >> t1 >> t2 >> t3;

  fill(ans + 1, ans + l + 1, 1e16);

  for (int i = 0; i < l; i++) {
    if (hurdle[i]) {
      ans[i + 1] = min(ans[i + 1], ans[i] + t1 + t3);
      ans[i + 2] = min(ans[i + 2], ans[i] + t1 + t2 + t3);
      ans[i + 4] = min(ans[i + 4], ans[i] + t1 + t2 * 3 + t3);
    } else {
      ans[i + 1] = min(ans[i + 1], ans[i] + t1);
      ans[i + 2] = min(ans[i + 2], ans[i] + t1 + t2);
      ans[i + 4] = min(ans[i + 4], ans[i] + t1 + t2 * 3);
    }
  }

  ll res = ans[l];
  for (int k = 1; k <= 3; k++) {
    if (hurdle[l - k]) {
      res = min(res, ans[l - k] + t1 / 2 + t2 * (k * 2 - 1) / 2 + t3);
    } else {
      res = min(res, ans[l - k] + t1 / 2 + t2 * (k * 2 - 1) / 2);
    }
  }

  cout << res << endl;

  return 0;
}
