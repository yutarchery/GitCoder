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

int n, q, lx, rx, ly, ry, lz, rz;
ll a[105][105][105], sum[105][105][105];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        cin >> a[i][j][k];
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        sum[i][j][k] =
            (sum[i][j][k - 1] + sum[i][j - 1][k] + sum[i - 1][j][k]) -
            (sum[i - 1][j - 1][k] + sum[i - 1][j][k - 1] +
             sum[i][j - 1][k - 1]) +
            sum[i - 1][j - 1][k - 1] + a[i][j][k];
      }
    }
  }

  cin >> q;
  while (q > 0) {
    q--;
    cin >> lx >> rx >> ly >> ry >> lz >> rz;

    int ans =
        sum[rx][ry][rz] -
        (sum[lx - 1][ry][rz] + sum[rx][ly - 1][rz] + sum[rx][ry][lz - 1]) +
        (sum[lx - 1][ly - 1][rz] + sum[lx - 1][ry][lz - 1] +
         sum[rx][ly - 1][lz - 1]) -
        (sum[lx - 1][ly - 1][lz - 1]);
    cout << ans << endl;
  }

  return 0;
}
