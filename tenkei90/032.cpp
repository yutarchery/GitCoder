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

int n, m, x, y, a[15][15], runner[15];
bool available[15][15];
ll ans = 1e16;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      available[i][j] = true;
    }
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    x--;
    y--;
    available[x][y] = false;
    available[y][x] = false;
  }

  for (int i = 0; i < n; i++) {
    runner[i] = i;
  }
  do {
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      if (!available[runner[i]][runner[i + 1]]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[runner[i]][i];
    }
    ans = min(ans, sum);
  } while (next_permutation(runner, runner + n));

  if (ans == 1e16) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}