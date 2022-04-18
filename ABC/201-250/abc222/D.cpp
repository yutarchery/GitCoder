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

int n, a[3005], b[3005];
ll dp[3005][3005], sum[3005][3005];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  dp[0][0] = 1;
  fill(sum[0], sum[0] + 3001, 1);

  for (int i = 1; i <= n; i++) {
    for (int j = a[i]; j <= b[i]; j++) {
      dp[i][j] += sum[i - 1][j];
    }

    sum[i][0] = dp[i][0];
    for (int j = 1; j <= 3000; j++) {
      sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod2;
    }
  }

  cout << sum[n][3000] << endl;

  return 0;
}