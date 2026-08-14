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

ll n, m, a[505][505];

vector<ll> cnt[505 * 505];
ll pows[505];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
    sort(a[i] + 1, a[i] + m + 1);

    int now = 1;
    for (int j = 2; j <= m; j++) {
      if (a[i][j] == a[i][j - 1]) {
        now++;
      } else {
        cnt[a[i][j - 1]].emplace_back(now);
        now = 1;
      }
    }
    cnt[a[i][m]].emplace_back(now);
  }

  pows[0] = 1;
  for (int i = 1; i <= n; i++) {
    pows[i] = (pows[i - 1] * m) % MOD2;
  }

  ll ans = 0;
  for (int i = 1; i <= n * m; i++) {
    ll now = 1;
    for (ll j : cnt[i]) {
      now *= m - j;
      now %= MOD2;
    }
    now *= pows[n - cnt[i].size()];
    now %= MOD2;

    ans += pows[n] - now;
    ans %= MOD2;

    if (ans < 0) {
      ans += MOD2;
    }
  }
  cout << ans << '\n';

  return 0;
}
