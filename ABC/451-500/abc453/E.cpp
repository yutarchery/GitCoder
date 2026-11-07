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

ll my_pow(ll a, ll n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return my_pow(a * a % MOD2, n / 2);
  } else {
    return a * my_pow(a, n - 1) % MOD2;
  }
}

int n, l[int(2e5 + 5)], r[int(2e5 + 5)];
ll fac[int(2e5 + 5)], rev[int(2e5 + 5)];

set<int> cand[int(2e5 + 5)];
ll cnt[4];

int check_idx(int i, int a_num) {
  int res = 0;
  if (l[i] <= a_num && a_num <= r[i]) {
    res += 1;
  }
  if (l[i] <= n - a_num && n - a_num <= r[i]) {
    res += 2;
  }

  return res;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];

    cand[l[i]].insert(i);
    cand[n - l[i] + 1].insert(i);

    cand[r[i] + 1].insert(i);
    cand[n - r[i]].insert(i);
  }

  fac[0] = 1;
  rev[0] = 1;
  for (ll i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % MOD2;
    rev[i] = my_pow(fac[i], MOD2 - 2);
  }

  cnt[0] = n;
  ll ans = 0;
  for (int a = 1; a <= n; a++) {
    for (int i : cand[a]) {
      cnt[check_idx(i, a - 1)]--;
      cnt[check_idx(i, a)]++;
    }

    if (cnt[0] > 0 || a - cnt[1] < 0 || cnt[3] - (a - cnt[1]) < 0) {
      continue;
    }

    ll now = fac[cnt[3]] * rev[a - cnt[1]] % MOD2;
    now = now * rev[cnt[3] - (a - cnt[1])] % MOD2;

    ans += now;
    ans %= MOD2;
  }
  cout << ans << '\n';

  return 0;
}
