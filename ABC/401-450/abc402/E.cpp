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

int n, x, c[8];
double s[8], p[8];

bool visited[(1 << 8)][5005];
double dp[(1 << 8)][5005];

double solve(int state, int rest) {
  if (visited[state][rest]) {
    return dp[state][rest];
  }

  visited[state][rest] = true;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    if ((state & (1 << i)) != 0) {
      continue;
    }
    if (rest - c[i] < 0) {
      continue;
    }

    ans = max(solve(state, rest - c[i]) * (double(100) - p[i]) / double(100) +
                  (solve((state | (1 << i)), rest - c[i]) + s[i]) * p[i] /
                      double(100),
              ans);
  }

  return dp[state][rest] = ans;
}

int main() {
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> c[i] >> p[i];
  }
  cout << fixed << setprecision(10) << solve(0, x) << endl;

  return 0;
}
