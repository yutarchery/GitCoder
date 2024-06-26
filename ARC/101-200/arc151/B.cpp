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

ll n, m;
int p[int(2e5 + 5)], group[int(2e5 + 5)];

ll group_cnt = 0, ans = 0;

int find_group(int u) {
  if (u == group[u]) {
    return group[u];
  }
  return group[u] = find_group(group[u]);
}

void unite(int u, int v) {
  int gu = find_group(u), gv = find_group(v);

  if (gu != gv) {
    ll now = m * (m - 1) / 2;
    now %= MOD2;
    now *= my_pow(m, group_cnt - 2);
    ans += now % MOD2;
    ans %= MOD2;
    group_cnt--;
  }

  group[u] = min(gu, gv);
  group[v] = min(gu, gv);
  group[max(gu, gv)] = min(gu, gv);

  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    group[i] = i;
  }
  group_cnt = n;
  for (int i = 1; i <= n; i++) {
    unite(i, p[i]);
  }
  cout << ans << endl;

  return 0;
}
