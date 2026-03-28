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
  } else if (n % 2 == 0) {
    return my_pow(a * a % MOD2, n / 2);
  } else {
    return a * my_pow(a, n - 1) % MOD2;
  }
}

int n, m;
int u[int(2e5 + 5)], v[int(2e5 + 5)];

int cnt;
int group[int(2e5 + 5)];

int find(int u) {
  int gu = group[u];
  if (u == gu) {
    return gu;
  } else {
    int ans = find(gu);
    return group[u] = ans;
  }
}

void unite(int u, int v) {
  int gu = find(u), gv = find(v);

  group[max(gu, gv)] = min(gu, gv);
  group[u] = min(gu, gv);
  group[v] = min(gu, gv);

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i];
  }

  cnt = n;
  for (int i = 1; i <= n; i++) {
    group[i] = i;
  }

  ll ans = 0;
  for (int i = m; i >= 1; i--) {
    int gu = find(u[i]), gv = find(v[i]);

    if (gu == gv) {
      continue;
    }
    if (cnt >= 3) {
      unite(gu, gv);
      cnt--;
    } else {
      ans += my_pow(2, i);
      ans %= MOD2;
    }
  }

  cout << ans << endl;

  return 0;
}
