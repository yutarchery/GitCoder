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

int m, a, b;

int group[1005][1005];
bool visited[1005][1005], ans[1005][1005];

bool solve(int x, int y) {
  if (visited[x][y]) {
    return ans[x][y];
  }

  visited[x][y] = true;
  if (x == 0 || y == 0) {
    return ans[x][y] = true;
  }

  int z = (a * y + b * x) % m;
  if (z == 0) {
    return ans[x][y] = true;
  }
  bool flag = solve(y, z);
  return ans[x][y] = flag;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> m >> a >> b;
  int res = 0;
  for (int i = 0; i <= m - 1; i++) {
    for (int j = 0; j <= m - 1; j++) {
      if (!solve(i, j)) {
        res++;
      }
    }
  }
  cout << res << '\n';

  return 0;
}
