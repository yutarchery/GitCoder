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

int n, a[305], cnt[4];

double dp[305][305][305];
bool visited[305][305][305];

double solve(int i, int j, int k) {
  if (i < 0 || j < 0 || k < 0) {
    return 0;
  }
  if (i == 0 && j == 0 && k == 0) {
    return 0;
  }
  if (visited[i][j][k]) {
    return dp[i][j][k];
  }

  visited[i][j][k] = true;

  double ans = (double)(n) / (double)(i + j + k);
  ans += (double)(i) / (double)(i + j + k) * solve(i - 1, j, k);
  ans += (double)(j) / (double)(i + j + k) * solve(i + 1, j - 1, k);
  ans += (double)(k) / (double)(i + j + k) * solve(i, j + 1, k - 1);

  return dp[i][j][k] = ans;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  cout << fixed << setprecision(32) << solve(cnt[1], cnt[2], cnt[3]) << endl;

  return 0;
}
