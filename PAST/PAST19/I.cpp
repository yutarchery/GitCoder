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

int n, m, a[int(2e5 + 5)], b[int(2e5 + 5)], d[int(2e5 + 5)];
priority_queue<pair<int, Pii>> que;

int group[int(2e5 + 5)], cnt[int(2e5 + 5)];

int find_parent(int u) {
  if (group[u] == u) {
    return u;
  }

  int pu = find_parent(group[u]);
  return group[u] = pu;
}

void unite(int u, int v) {
  int pu = find_parent(u), pv = find_parent(v);
  if (pu == pv) {
    return;
  }
  int p = min(pu, pv);
  cnt[p] = cnt[pu] + cnt[pv];
  group[pu] = p;
  group[pv] = p;
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> d[i];
    que.push({d[i], {a[i], b[i]}});
  }

  for (int i = 1; i <= n; i++) {
    group[i] = i;
    cnt[i] = 1;
  }

  while (!que.empty()) {
    pair<int, Pii> q = que.top();
    que.pop();

    unite(q.second.first, q.second.second);
    if (cnt[1] == n) {
      cout << q.first << endl;
      return 0;
    }
  }

  return 0;
}
