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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

ll n, l, t, x, a[105], b[105];

int main() {
  cin >> n >> l >> t >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  ll ans = 0, now = 0, idx = 1;
  while (idx <= n) {
    if (b[idx] < l) {
      ans += a[idx];
      now = 0;
      idx++;
      continue;
    }

    if (a[idx] > t) {
      cout << "forever" << endl;
      return 0;
    }

    if (now + a[idx] > t) {
      ans += t - now + x;
      now = 0;
    } else {
      ans += a[idx];
      now += a[idx];
      idx++;
      if (now == t) {
        ans += x;
        now = 0;
      }
    }
  }

  cout << ans << endl;

  return 0;
}