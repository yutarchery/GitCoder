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
ll a[3005], sum[3005], dp[3005][3005][2];
bool visited[3005][3005][2];

ll solve(int i, int j, int turn) {
  if (visited[i][j][turn]) {
    return dp[i][j][turn];
  }

  visited[i][j][turn] = true;
  if (i > j) {
    return 0;
  }

  ll ans = max((sum[j] - sum[i]) - solve(i + 1, j, 1 - turn) + a[i],
               (sum[j - 1] - sum[i - 1]) - solve(i, j - 1, 1 - turn) + a[j]);

  return dp[i][j][turn] = ans;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }

  ll x = solve(1, n, 0), y = sum[n] - x;
  cout << x - y << endl;

  return 0;
}
