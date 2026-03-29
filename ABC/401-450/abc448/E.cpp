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

ll mypow(ll a, ll n, ll mod) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return mypow(a * a % mod, n / 2, mod);
  } else {
    return a * mypow(a, n - 1, mod) % mod;
  }
}

const ll MYMOD = 10007;
int k;
ll m, c[int(1e5 + 5)], l[int(1e5 + 5)], t[int(1e5 + 5)];

map<ll, ll> val_r;
map<ll, bool> visited;

ll pows[50];
ll calc_r(ll idx, ll mod) {
  if (idx == 0) {
    return 0;
  }
  if (idx == 1) {
    return 1;
  }

  if (visited[idx]) {
    return val_r[idx];
  }

  visited[idx] = true;

  for (int i = 49; i >= 1; i--) {
    if (idx > pows[i]) {
      ll sum = calc_r(pows[i], mod);
      sum *= mypow(10, idx - pows[i], mod);
      sum %= mod;
      sum += calc_r(idx - pows[i], mod);
      sum %= mod;
      return val_r[idx] = sum;
    } else if (idx == pows[i]) {
      ll sum = calc_r(idx / 2, mod);
      sum *= mypow(10, pows[i - 1], mod) + 1;
      sum %= mod;
      return val_r[idx] = sum;
    }
  }

  return 0;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> k >> m;
  for (int i = 1; i <= k; i++) {
    cin >> c[i] >> l[i];
  }

  for (int i = k - 1; i >= 1; i--) {
    t[i] = t[i + 1] + l[i + 1];
  }

  pows[0] = 1;
  for (int i = 1; i < 50; i++) {
    pows[i] = pows[i - 1] * 2;
  }

  ll sum = 0;
  for (int i = 1; i <= k; i++) {
    if (c[i] == 0) {
      continue;
    }

    ll r = calc_r(l[i], MYMOD * m);
    ll v = (c[i] * r) % (MYMOD * m);
    v *= mypow(10, t[i], MYMOD * m);
    v %= MYMOD * m;

    sum += v;
    sum %= MYMOD * m;
  }

  cout << sum / m << '\n';

  return 0;
}
