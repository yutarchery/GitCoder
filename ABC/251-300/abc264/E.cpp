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

int n, m, e, q;
int u[int(5e5 + 5)], v[int(5e5 + 5)], x[int(5e5 + 5)];

bool is_exist[int(5e5 + 5)];
int par[int(5e5 + 5)], children[int(5e5 + 5)], ans[int(5e5 + 5)];

int find_parent(int a) {
  if (par[a] == a) {
    return a;
  }
  int res = find_parent(par[a]);
  return par[a] = res;
}

void unite(int a, int b) {
  int pa = find_parent(a), pb = find_parent(b);
  if (pa == pb) {
    return;
  }

  int pm = max(pa, pb);

  par[a] = pm;
  par[b] = pm;
  par[min(pa, pb)] = pm;
  children[pm] += children[min(pa, pb)];
  return;
}

int main() {
  cin >> n >> m >> e;
  for (int i = 1; i <= n + m + 1; i++) {
    par[i] = i;
    children[i] = 1;
  }

  for (int i = n + 1; i <= n + m; i++) {
    unite(i, n + m + 1);
  }

  for (int i = 1; i <= e; i++) {
    cin >> u[i] >> v[i];
  }
  fill(is_exist + 1, is_exist + e + 1, true);

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x[i];
    is_exist[x[i]] = false;
  }
  for (int i = 1; i <= e; i++) {
    if (is_exist[i]) {
      unite(u[i], v[i]);
    }
  }

  ans[q] = children[n + m + 1];
  for (int i = q; i >= 1; i--) {
    unite(u[x[i]], v[x[i]]);
    ans[i - 1] = children[n + m + 1];
  }

  for (int i = 1; i <= q; i++) {
    cout << ans[i] - (m + 1) << endl;
  }

  return 0;
}
