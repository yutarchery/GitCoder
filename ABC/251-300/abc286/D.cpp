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

int n, x, a[55], b[55];
bool dp[55][10005], visited[55][10005];

bool solve(int now, int rest) {
  if (rest == 0) {
    return dp[now][rest] = true;
  }
  if (now == 0) {
    return dp[now][rest] = false;
  }
  if (visited[now][rest]) {
    return dp[now][rest];
  }

  visited[now][rest] = true;

  ll ans = false;
  for (int i = 0; i <= b[now] && rest - a[now] * i >= 0; i++) {
    ans = ans | solve(now - 1, rest - a[now] * i);
    if (ans) {
      break;
    }
  }

  return dp[now][rest] = ans;
}

int main() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  if (solve(n, x)) {
    Yes();
  } else {
    No();
  }

  return 0;
}
