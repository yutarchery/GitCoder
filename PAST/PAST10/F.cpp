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

int h, w, n, a[205][205], c[105];
int di[4] = {0, -1, 0, 1};
int dj[4] = {-1, 0, 1, 0};

int main() {
  cin >> h >> w >> n;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      for (int k = 0; k < 4; k++) {
        int ii = i + di[k], jj = j + dj[k];

        if (a[i][j] != a[ii][jj] && c[a[i][j]] == c[a[ii][jj]]) {
          No();
          return 0;
        }
      }
    }
  }

  Yes();

  return 0;
}