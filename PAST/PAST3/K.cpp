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

int n, q, f, t, x;
// 机ごとでの値
int heads[int(2e5 + 5)], bottoms[int(2e5 + 5)];
// コンテナごとでの値
int befores[int(4e5 + 5)], afters[int(4e5 + 5)];

int ans[int(4e5 + 5)];

void solve() {
  for (int i = 1; i <= n; i++) {
    if (heads[i] == 0) {
      continue;
    }

    int now = heads[i];
    while (now != 0) {
      ans[now] = i;
      now = afters[now];
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
  return;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    heads[i] = i + n;
    bottoms[i] = i;
    befores[i] = i + n;
    afters[i + n] = i;
  }

  while (q--) {
    cin >> f >> t >> x;

    int bf = bottoms[f], bt = bottoms[t], bx = befores[x];

    befores[x] = bt;
    bottoms[t] = bf;
    bottoms[f] = bx;
    afters[bt] = x;

    afters[bottoms[f]] = 0;
    afters[bottoms[t]] = 0;
  }

  solve();

  return 0;
}
