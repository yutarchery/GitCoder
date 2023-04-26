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

int n, q, a, b, t, c[int(2e5 + 5)], group[int(2e5 + 5)];
map<int, int> group2class[int(2e5 + 5)];

int parent(int node) {
  if (group[node] == node) {
    return node;
  } else {
    int tmp = group[node];
    return group[node] = parent(tmp);
  }
}

void unite(int u, int v) {
  int gu = parent(u), gv = parent(v);
  if (gu > gv) {
    swap(gu, gv);
  }

  group[gv] = gu;
  for (auto [key, value] : group2class[gv]) {
    group2class[gu][key] += value;
  }
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    group[i] = i;
    group2class[i][c[i]]++;
  }

  for (int i = 0; i < q; i++) {
    cin >> t >> a >> b;
    if (t == 1) {
      if (parent(a) != parent(b)) {
        unite(a, b);
      }
    } else {
      cout << group2class[parent(a)][b] << endl;
    }
  }

  return 0;
}