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
char s[105][105], t[105][105], u[105][105];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> t[i][j];
    }
  }

  int ans = 1e9;
  for (int k = 0; k < 4; k++) {
    int cnt = k;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        u[i][j] = s[i][j];
        if (u[i][j] != t[i][j]) {
          cnt++;
        }
      }
    }
    ans = min(ans, cnt);

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        s[j][n + 1 - i] = u[i][j];
      }
    }
  }
  cout << ans << endl;

  return 0;
}
