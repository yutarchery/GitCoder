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

ll gcd(ll a, ll b) {
  if (a < b) {
    return gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
}

ll lcd(ll a, ll b) {
  ll g = gcd(a, b);
  return (a / g) * b;
}

ll n, m, k;

int main() {
  cin >> n >> m >> k;
  ll lc = lcd(n, m);

  ll l = 0, r = 1e18;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    ll cnt = (mid / n) + (mid / m) - (mid / lc) * 2;

    if (cnt < k) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << r << endl;

  return 0;
}
