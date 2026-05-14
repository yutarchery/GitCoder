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

int n, q, c[int(3e5 + 5)], p[int(3e5 + 5)];

int bef[int(6e5 + 5)], nex[int(6e5 + 5)];
int ans[int(3e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    bef[i + n] = i;
    nex[i] = i + n;
  }

  for (int i = 1; i <= q; i++) {
    cin >> c[i] >> p[i];

    int new_top = nex[c[i]];
    bef[new_top] = 0;

    nex[c[i]] = p[i];
    bef[p[i]] = c[i];
  }

  for (int i = 1; i <= n; i++) {
    int now = bef[n + i];

    while (now != 0) {
      ans[i]++;
      now = bef[now];
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
