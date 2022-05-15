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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, m, b[int(1e4 + 5)][7], res[int(1e4 + 5)][7];
bool ans = true;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];

      res[i][j] = b[i][j] % 7;
      if (res[i][j] == 0) {
        res[i][j] = 7;
      }
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i][j] - b[i - 1][j] != 7) {
        ans = false;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (b[i][j] - b[i][j - 1] != 1) {
        ans = false;
      }

      if (res[i][j] - res[i][j - 1] != 1) {
        ans = false;
      }
    }
  }

  if (ans) {
    Yes();
  } else {
    No();
  }

  return 0;
}