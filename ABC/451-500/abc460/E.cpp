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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

ll my_gcd(ll a, ll b) {
  if (a < b) {
    return my_gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  } else {
    return my_gcd(b, a % b);
  }
}

ll nines[19];
ll n, m;

ll solve() {
  cin >> n >> m;

  for (int i = 1; i <= 18; i++) {
    nines[i] = nines[i - 1] * 10 + 9;
  }

  ll ans = 0;
  for (int i = 1; i <= 18; i++) {
    if (n < nines[i - 1] + 1) {
      break;
    }

    ll now = (min(n, nines[i]) - nines[i - 1]) % MOD2;

    ll g = my_gcd(nines[i], m);
    now = (now * ((n / (m / g)) % MOD2)) % MOD2;
    ans = (ans + now) % MOD2;
  }

  if (n == nines[18] + 1) {
    ll r = 0;
    for (int i = 1; i <= 19; i++) {
      r = (r * 10 + 9) % m;
    }

    if (r == 0) {
      ans = (ans + n % MOD2) % MOD2;
    } else {
      ll g = my_gcd(r, m);
      ans = (ans + (n / (m / g)) % MOD2) % MOD2;
    }
  }

  return ans;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }

  return 0;
}
