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

ll n, ans;

ll solve(ll b, ll rest) {
  ll res = 0;
  for (ll j = b; j * j <= rest; j++) {
    res += rest / j - j + 1;
  }

  return res;
}

int main() {
  cin >> n;

  for (ll i = 1; i * i * i <= n; i++) {
    ll rest = n / i;
    ans += solve(i, rest);
  }
  cout << ans << endl;

  return 0;
}