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

int n, m, q, a[int(4e5 + 5)], b[int(4e5 + 5)];
ll c[int(4e5 + 5)];

priority_queue<Pli, vector<Pli>, greater<Pli>> que;
int group[int(2e5 + 5)];
bool ans[int(4e5 + 5)];

int calc_group(int u) {
  if (group[u] == u) {
    return u;
  }
  int gu = group[u];
  return group[u] = calc_group(gu);
}

void unite(int u, int v) {
  int gu = calc_group(u), gv = calc_group(v);

  group[u] = min(gu, gv);
  group[v] = min(gu, gv);
  group[max(gu, gv)] = min(gu, gv);

  return;
}

int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    group[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    que.push({c[i], i});
  }
  for (int i = m + 1; i <= m + q; i++) {
    cin >> a[i] >> b[i] >> c[i];
    que.push({c[i], i});
  }

  while (!que.empty()) {
    Pli q = que.top();
    que.pop();

    if (q.second >= m + 1) {
      int ga = calc_group(a[q.second]), gb = calc_group(b[q.second]);
      if (ga == gb) {
        ans[q.second] = false;
      } else {
        ans[q.second] = true;
      }
    } else {
      unite(a[q.second], b[q.second]);
    }
  }

  for (int i = m + 1; i <= m + q; i++) {
    ans[i] ? Yes() : No();
  }

  return 0;
}
