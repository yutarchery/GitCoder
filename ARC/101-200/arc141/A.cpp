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

ll solve(ll num) {
  ll rest = num;
  vector<ll> now;
  while (rest > 0) {
    now.push_back(rest % 10);
    rest /= 10;
  }
  reverse(now.begin(), now.end());

  ll ans = 1, k = now.size();
  for (int i = 1; i < k; i++) {
    ans *= 10;
  }
  ans--;

  for (ll i = 1; i <= k; i++) {
    if (k % i != 0 || k / i == 1) {
      continue;
    }

    ll tmp = 0, p = 1;
    for (ll j = 0; j < i; j++) {
      tmp *= 10;
      tmp += now[j];
      p *= 10;
    }

    ll tt = tmp - 1, res1 = 0, res2 = 0;

    for (ll j = 0; j < k / i; j++) {
      res1 *= p;
      res1 += tmp;

      res2 *= p;
      res2 += tt;
    }

    if (res1 <= num) {
      ans = max(ans, res1);
    }
    if (res2 <= num) {
      ans = max(ans, res2);
    }
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
  }

  return 0;
}
