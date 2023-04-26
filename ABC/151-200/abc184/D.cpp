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

int a, b, c;
double dp[105][105][105];
bool visited[105][105][105];

double solve(int i, int j, int k) {
  if (visited[i][j][k]) {
    return dp[i][j][k];
  }

  visited[i][j][k] = true;
  if (i < a || j < b || k < c) {
    return dp[i][j][k] = 0;
  }

  double di = i, dj = j, dk = k, dn = i + j + k;
  double ans = 0;
  if (i >= 1) {
    ans += ((di - 1) / (dn - 1)) * solve(i - 1, j, k);
  }
  if (j >= 1) {
    ans += ((dj - 1) / (dn - 1)) * solve(i, j - 1, k);
  }
  if (k >= 1) {
    ans += ((dk - 1) / (dn - 1)) * solve(i, j, k - 1);
  }
  return dp[i][j][k] = ans;
}

int main() {
  cin >> a >> b >> c;
  double da = a, db = b, dc = c;
  visited[a][b][c] = true;
  dp[a][b][c] = 1;
  double ans = 0;

  for (int j = 0; j <= 99; j++) {
    for (int k = 0; k <= 99; k++) {
      double di = 99, dj = j, dk = k;
      ans += di / (di + dj + dk) * solve(99, j, k) *
             (di + dj + dk + 1 - (da + db + dc));
    }
  }
  for (int i = 0; i <= 99; i++) {
    for (int k = 0; k <= 99; k++) {
      double di = i, dj = 99, dk = k;
      ans += dj / (di + dj + dk) * solve(i, 99, k) *
             (di + dj + dk + 1 - (da + db + dc));
    }
  }
  for (int i = 0; i <= 99; i++) {
    for (int j = 0; j <= 99; j++) {
      double di = i, dj = j, dk = 99;
      ans += dk / (di + dj + dk) * solve(i, j, 99) *
             (di + dj + dk + 1 - (da + db + dc));
    }
  }
  cout << setprecision(32) << ans << endl;

  return 0;
}