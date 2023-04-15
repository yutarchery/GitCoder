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

int n, k, a[105];

int dp[2][int(1e4 + 5)];
bool visited[2][int(1e4 + 5)];

int solve(int turn, int rest) {
  if (visited[turn][rest]) {
    return dp[turn][rest];
  }

  visited[turn][rest] = true;
  if (rest == 0) {
    return 0;
  }

  int ans = 0;
  for (int i = 0; i < k; i++) {
    if (rest < a[i]) {
      continue;
    }

    ans = max(ans, rest - solve(1 - turn, rest - a[i]));
  }

  return dp[turn][rest] = ans;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  cout << solve(0, n) << endl;

  return 0;
}