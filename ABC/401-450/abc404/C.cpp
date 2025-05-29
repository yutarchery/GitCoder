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

int n, m, a, b;
int group[int(2e5 + 5)], cnt[int(2e5 + 5)];

int find_parent(int idx) {
  if (group[idx] == idx) {
    return idx;
  }

  int p = find_parent(group[idx]);
  return group[idx] = p;
}

void unite(int u, int v) {
  int pu = find_parent(u), pv = find_parent(v);

  group[max(pu, pv)] = min(pu, pv);
  group[u] = min(pu, pv);
  group[v] = min(pu, pv);

  return;
}

int main() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    group[i] = i;
  }

  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    cnt[a]++;
    cnt[b]++;
    unite(a, b);
  }

  for (int i = 1; i <= n; i++) {
    if (cnt[i] != 2) {
      No();
      return 0;
    }
  }

  if (n != m) {
    No();
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    if (find_parent(i) != 1) {
      No();
      return 0;
    }
  }

  Yes();

  return 0;
}
