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

ll my_pow(ll a, ll b) {
  if (b == 0) {
    return 1;
  }

  if (b % 2 == 0) {
    return my_pow(a * a % MOD2, b / 2);
  } else {
    return a * my_pow(a, b - 1) % MOD2;
  }
}

int n, p;
ll frac[int(2e5 + 5)], rev[int(2e5 + 5)];
ll prob, rev_prob;

ll calc_conbi(ll a, ll b) {
  ll ans = 0;
  if ((a - 1) + b * 2 < n && a - 1 >= 0) {
    ll tmp = frac[a + b - 1] * rev[a - 1] % MOD2;
    tmp *= rev[b];
    tmp %= MOD2;
    ans += tmp;
  }
  if (a + (b - 1) * 2 < n && b - 1 >= 0) {
    ll tmp = frac[a + b - 1] * rev[a] % MOD2;
    tmp *= rev[b - 1];
    tmp %= MOD2;
    ans += tmp;
  }
  return ans % MOD2;
}

ll calc_prob(ll a, ll b) {
  ll conbi = calc_conbi(a, b);
  ll per = (my_pow(rev_prob, a) * my_pow(prob, b)) % MOD2;
  return conbi * per % MOD2;
}

int main() {
  cin >> n >> p;

  frac[0] = 1, rev[0] = 1;
  for (ll i = 1; i <= n; i++) {
    frac[i] = i * frac[i - 1] % MOD2;
    rev[i] = my_pow(frac[i], MOD2 - 2);
  }
  prob = p * my_pow(100, MOD2 - 2) % MOD2;
  rev_prob = (100 - p) * my_pow(100, MOD2 - 2) % MOD2;

  ll ans = 0;
  for (ll a = 0; a <= n; a++) {
    ll b = (n - a) / 2;
    if ((n - a) % 2 != 0) {
      b++;
    }

    ll exp = (a + b) * calc_prob(a, b) % MOD2;

    ans += exp;
    ans %= MOD2;
  }

  cout << ans << endl;

  return 0;
}