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
char s[305][305];

int dots[305][305], sharps[305][305];

bool solve(int l, int i, int j) {
  if (i + l + 1 > n || j + l + 1 > n) {
    return false;
  }

  if (dots[i + l + 1][j + l + 1] - dots[i - 1][j + l + 1] -
          dots[i + l + 1][j - 1] + dots[i - 1][j - 1] !=
      l * (l + 1)) {
    return false;
  }
  if (sharps[i + l + 1][j] - sharps[i + l + 1][j - 1] - sharps[i - 1][j] +
          sharps[i - 1][j - 1] !=
      l + 2) {
    return false;
  }
  if (sharps[i][j + l + 1] - sharps[i - 1][j + l + 1] - sharps[i][j - 1] +
          sharps[i - 1][j - 1] !=
      l + 2) {
    return false;
  }
  if (sharps[i + l + 1][j + l + 1] - sharps[i + l][j + l + 1] -
          sharps[i + l + 1][j - 1] + sharps[i + l][j - 1] !=
      l + 2) {
    return false;
  }

  return true;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dots[i][j] = dots[i - 1][j] + dots[i][j - 1] - dots[i - 1][j - 1];
      sharps[i][j] = sharps[i - 1][j] + sharps[i][j - 1] - sharps[i - 1][j - 1];

      if (s[i][j] == '.') {
        dots[i][j]++;
      } else {
        sharps[i][j]++;
      }
    }
  }

  int ans = 0;
  for (int l = 1; l <= n; l++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (solve(l, i, j)) {
          ans = max(ans, l);
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
