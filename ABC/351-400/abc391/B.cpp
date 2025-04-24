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

int n, m;
char s[55][55], t[55][55];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> t[i][j];
    }
  }

  for (int i = 1; i + m - 1 <= n; i++) {
    for (int j = 1; j + m - 1 <= n; j++) {
      bool flag = true;
      for (int k = 1; k <= m; k++) {
        for (int l = 1; l <= m; l++) {
          if (s[i + k - 1][j + l - 1] != t[k][l]) {
            flag = false;
          }
        }
      }

      if (flag) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }

  return 0;
}
