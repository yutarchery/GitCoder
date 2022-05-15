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

ll gcd(ll a, ll b) {
  if (a < b) {
    return gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

ll l, r, ans = 0;

ll initialDiff() {
  ll k = 0;
  while (true) {
    if (gcd(l, r - k) == 1) {
      return k;
    }
    k++;
  }
}

int main() {
  cin >> l >> r;

  ll diff = initialDiff();

  for (ll i = 0; i <= diff; i++) {
    for (ll j = 0; j <= diff; j++) {
      ll x = l + i, y = r - j;
      if (x >= y) {
        break;
      }
      if (gcd(x, y) == 1) {
        ans = max(ans, y - x);
      }
    }
  }
  cout << ans << endl;

  return 0;
}