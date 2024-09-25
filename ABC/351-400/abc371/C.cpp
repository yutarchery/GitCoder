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

int n, mg, mh, u, v, order[10], a[10][10];
bool g[10][10], h[10][10];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    order[i] = i;
  }

  cin >> mg;
  for (int i = 1; i <= mg; i++) {
    cin >> u >> v;
    g[u][v] = true;
    g[v][u] = true;
  }
  cin >> mh;
  for (int i = 1; i <= mh; i++) {
    cin >> u >> v;
    h[u][v] = true;
    h[v][u] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
  }

  int ans = 1e9;
  do {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        int hu = order[i], hv = order[j];

        if (g[i][j] != h[hu][hv]) {
          sum += a[hu][hv];
        }
      }
    }
    ans = min(ans, sum);
  } while (next_permutation(order + 1, order + n + 1));

  cout << ans << endl;

  return 0;
}
