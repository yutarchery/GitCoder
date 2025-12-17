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

int n;
int ans[105][105];

int main() {
  cin >> n;
  int i = 0, j = (n - 1) / 2;

  for (int k = 1; k <= n * n; k++) {
    ans[i][j] = k;
    int next_i = (i - 1) % n, next_j = (j + 1) % n;
    if (next_i < 0) {
      next_i += n;
    }
    if (ans[next_i][next_j] == 0) {
      i = next_i;
      j = next_j;
    } else {
      i = (i + 1) % n;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << (j == n - 1 ? '\n' : ' ');
    }
  }

  return 0;
}
