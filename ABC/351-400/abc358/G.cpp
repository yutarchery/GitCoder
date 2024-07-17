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

int h, w, si, sj;
ll k, a[55][55];

bool visited[55][55][2505];
ll dp[55][55][2505];

priority_queue<array<ll, 4>> que;
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

int main() {
  cin >> h >> w >> k;
  cin >> si >> sj;

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }

  ll ans = 0;
  visited[si][sj][0] = true;
  for (ll t = 0; t <= min(k, ll(h * w)); t++) {
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        if (!visited[i][j][t]) {
          continue;
        }

        ans = max(ans, dp[i][j][t] + a[i][j] * (k - t));

        visited[i][j][t + 1] = true;
        dp[i][j][t + 1] = max(dp[i][j][t + 1], dp[i][j][t] + a[i][j]);
        for (int l = 0; l < 4; l++) {
          visited[i + di[l]][j + dj[l]][t + 1] = true;
          dp[i + di[l]][j + dj[l]][t + 1] =
              max(dp[i + di[l]][j + dj[l]][t + 1],
                  dp[i][j][t] + a[i + di[l]][j + dj[l]]);
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
