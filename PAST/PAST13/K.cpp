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

ll solve(ll digit_sum, ll max_value) {
  ll ans = 0, digit = ll(1e9);

  while (digit > 0) {
    for (ll i = 9; i >= 0; i--) {
      if (i <= digit_sum && ans + i * digit <= max_value) {
        digit_sum -= i;
        ans += i * digit;
        break;
      }
    }
    digit /= 10;
  }

  return ans;
}

int main() {
  ll a, b, x;
  cin >> a >> b >> x;

  ll ans = 0;
  for (ll i = 1; i <= 81; i++) {
    ll rest = (x - b * i) / a;
    if (rest <= 0) {
      continue;
    }
    ans = max(ans, solve(i, min(rest, ll(1e9))));
  }
  cout << ans << endl;

  return 0;
}
