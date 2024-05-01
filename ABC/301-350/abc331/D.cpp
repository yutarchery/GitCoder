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

int n, q;
ll a, b, c, d;
char p[1005][1005];
ll sum[1005][1005];

void prepare() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> p[i][j];
    }
  }

  if (p[0][0] == 'B') {
    sum[0][0] = 1;
  }
  for (int i = 1; i < n; i++) {
    sum[i][0] = sum[i - 1][0];
    if (p[i][0] == 'B') {
      sum[i][0]++;
    }
  }
  for (int j = 1; j < n; j++) {
    sum[0][j] = sum[0][j - 1];
    if (p[0][j] == 'B') {
      sum[0][j]++;
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      if (p[i][j] == 'B') {
        sum[i][j]++;
      }
    }
  }

  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= 1; j--) {
      sum[i][j] = sum[i - 1][j - 1];
    }
  }
  for (int i = 0; i <= n; i++) {
    sum[i][0] = 0;
    sum[0][i] = 0;
  }

  return;
}

ll calc(ll a, ll b) {
  ll ans = sum[n][n] * (a / n) * (b / n);
  ans += sum[a % n][n] * (b / n);
  ans += sum[n][b % n] * (a / n);
  ans += sum[a % n][b % n];

  return ans;
}

ll solve(ll a, ll b, ll c, ll d) {
  return calc(c + 1, d + 1) - calc(c + 1, b) - calc(a, d + 1) + calc(a, b);
}

int main() {
  cin >> n >> q;
  prepare();

  for (int i = 0; i < q; i++) {
    cin >> a >> b >> c >> d;
    cout << solve(a, b, c, d) << endl;
  }

  return 0;
}
