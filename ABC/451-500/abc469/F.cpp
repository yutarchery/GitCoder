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

int n;
ll a[int(2e5 + 5)];

int group[int(2e5 + 5)];
vector<int> val[int(1e6 + 5)];

void prepare(int i) {
  for (ll j = 1; j * j <= a[i]; j++) {
    if (a[i] % j == 0) {
      val[j].emplace_back(i);

      if (j * j != a[i]) {
        val[a[i] / j].emplace_back(i);
      }
    }
  }
  return;
}

int find_group(int u) {
  if (u == group[u]) {
    return u;
  }

  int gu = group[u];
  return group[u] = find_group(gu);
}

void unite(int u, int v) {
  int gu = find_group(u), gv = find_group(v);

  group[u] = min(gu, gv);
  group[v] = min(gu, gv);
  group[max(gu, gv)] = min(gu, gv);

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    prepare(i);
  }
  for (int i = 1; i <= int(1e6); i++) {
    sort(val[i].begin(), val[i].end());
  }

  for (int i = 1; i <= n; i++) {
    group[i] = i;
  }

  ll ans = 0;
  for (ll i = int(1e6); i >= 1; i--) {
    if (val[i].size() <= 1) {
      continue;
    }

    int min_group = n;
    for (int j : val[i]) {
      min_group = min(min_group, find_group(j));
    }
    for (int j : val[i]) {
      if (find_group(j) != min_group) {
        ans += i;
        unite(j, min_group);
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
