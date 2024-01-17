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

int h, w;
char a[1005][1005];

ll dp[1005][1005];
bool visited[1005][1005];

ll solve(int i, int j) {
  if (!(1 <= i && i <= h && 1 <= j && j <= w)) {
    return 0;
  }

  if (visited[i][j]) {
    return dp[i][j];
  }

  visited[i][j] = true;
  if (a[i][j] != '.') {
    return dp[i][j] = 0;
  }

  ll ans = solve(i - 1, j) + solve(i, j - 1);
  return dp[i][j] = ans % MOD;
}

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }

  dp[1][1] = 1;
  visited[1][1] = true;
  cout << solve(h, w) << endl;

  return 0;
}
