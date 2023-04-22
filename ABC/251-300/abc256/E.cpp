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

int n, a[int(2e5 + 5)];
Pli cost[int(2e5 + 5)];

int group[int(2e5 + 5)];

int findGroup(int u) {
  if (u == group[u]) {
    return group[u];
  } else {
    int tmp = group[u];
    return group[u] = findGroup(tmp);
  }
}

void unite(int u, int v) {
  int gu = findGroup(u), gv = findGroup(v);
  group[max(gu, gv)] = min(gu, gv);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    group[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> cost[i].first;
    cost[i].second = i;
  }
  sort(cost + 1, cost + n + 1, greater<Pli>());

  ll ans = 0;
  for (int j = 1; j <= n; j++) {
    int u = cost[j].second;
    int v = a[u];

    if (findGroup(u) == findGroup(v)) {
      ans += cost[j].first;
    }

    unite(u, v);
  }
  cout << ans << endl;

  return 0;
}