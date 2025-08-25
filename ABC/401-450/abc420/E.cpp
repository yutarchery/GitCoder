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

int n, q, op, u, v;
int par[int(2e5 + 5)], cnt[int(2e5 + 5)];
bool is_black[int(2e5 + 5)];

int get_par(int u) {
  if (u == par[u]) {
    return u;
  } else {
    int gu = get_par(par[u]);
    return par[u] = gu;
  }
}

void unite(int u, int v) {
  int gu = get_par(u), gv = get_par(v);
  if (gu == gv) {
    return;
  }

  par[u] = min(gu, gv);
  par[v] = min(gu, gv);
  par[max(gu, gv)] = min(gu, gv);
  cnt[min(gu, gv)] = cnt[gu] + cnt[gv];

  return;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }

  for (int i = 1; i <= q; i++) {
    cin >> op;

    if (op == 1) {
      cin >> u >> v;
      unite(u, v);
    } else if (op == 2) {
      cin >> v;
      int gv = get_par(v);
      if (is_black[v]) {
        cnt[gv]--;
        is_black[v] = false;
      } else {
        cnt[gv]++;
        is_black[v] = true;
      }
    } else {
      cin >> v;
      int gv = get_par(v);
      cnt[gv] > 0 ? Yes() : No();
    }
  }

  return 0;
}
