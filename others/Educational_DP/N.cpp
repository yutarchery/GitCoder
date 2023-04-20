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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n;
ll a[405], sum[405], dp[405][405];
bool visited[405][405];

ll solve(int i, int j) {
  if (visited[i][j]) {
    return dp[i][j];
  }

  visited[i][j] = true;
  if (i == j) {
    return 0;
  }

  ll ans = min(solve(i + 1, j), solve(i, j - 1)) + (sum[j] - sum[i - 1]);
  for (int k = i + 1; k + 1 <= j - 1; k++) {
    ans = min(ans, solve(i, k) + solve(k + 1, j) + (sum[j] - sum[i - 1]));
  }

  return dp[i][j] = ans;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }

  cout << solve(1, n) << endl;

  return 0;
}