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

int n, a[305][305];
int zero_i, zero_j;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        zero_i = i;
        zero_j = j;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 0) {
        continue;
      }
      for (int k = 1; k <= n; k++) {
        if (a[j][k] == 0) {
          continue;
        }

        if (a[i][a[j][k]] != a[a[i][j]][k] && a[i][a[j][k]] != 0 &&
            a[a[i][j]][k] != 0) {
          cout << 0 << endl;
          return 0;
        }
      }
    }
  }

  int ans = 0;
  for (int v = 1; v <= n; v++) {
    a[zero_i][zero_j] = v;
    bool flag = true;

    for (int k = 1; k <= n; k++) {
      if (a[zero_i][a[zero_j][k]] != a[a[zero_i][zero_j]][k]) {
        flag = false;
      }
      if (a[k][a[zero_i][zero_j]] != a[a[k][zero_i]][zero_j]) {
        flag = false;
      }
    }

    if (flag) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
