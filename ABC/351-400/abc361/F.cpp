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

ll my_pow(ll a, ll n) {
  double now = 1;
  for (int i = 0; i < n; i++) {
    now *= a;
    if (now >= 2e18) {
      return ll(2e18);
    }
  }

  ll res = 1;
  for (int i = 0; i < n; i++) {
    res *= a;
  }
  return res;
}

int divide(int num) {
  vector<int> res;
  int now = 2;
  while (num > 1) {
    if (num % now == 0) {
      res.push_back(now);
      num /= now;
    } else {
      now++;
    }
  }

  for (int i = 1; i < res.size(); i++) {
    if (res[i] == res[i - 1]) {
      return 0;
    }
  }
  return res.size();
}

ll n, ans = 1;

int main() {
  cin >> n;

  for (ll i = 2; i <= 60; i++) {
    int d = divide(i);
    if (d == 0) {
      continue;
    }

    ll l = 1, r = 2e9;
    while (r - l > 1) {
      ll mid = (l + r) / 2;
      if (my_pow(mid, i) <= n) {
        l = mid;
      } else {
        r = mid;
      }
    }

    if (d % 2 == 1) {
      ans += l - 1;
    } else {
      ans -= l - 1;
    }
  }

  cout << ans << endl;

  return 0;
}
