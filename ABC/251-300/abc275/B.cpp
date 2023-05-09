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

ll a, b, c, d, e, f, ans1, ans2;

int main() {
  cin >> a >> b >> c >> d >> e >> f;

  ans1 = (a % MOD2) * (b % MOD2) % MOD2;
  ans1 = ans1 * (c % MOD2) % MOD2;

  ans2 = (d % MOD2) * (e % MOD2) % MOD2;
  ans2 = ans2 * (f % MOD2) % MOD2;

  ll ans = (ans1 - ans2) % MOD2;
  if (ans < 0) {
    ans += MOD2;
  }
  cout << ans << endl;

  return 0;
}