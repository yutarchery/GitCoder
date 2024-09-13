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

int n;
ll k;
int x[int(2e5 + 5)], a[int(2e5 + 5)];

int dp[int(2e5 + 5)][61];
bool visited[int(2e5 + 5)][61];
ll dist[61];

int solve(int i, int j) {
  if (visited[i][j]) {
    return dp[i][j];
  }

  visited[i][j] = true;
  int next = solve(i, j - 1);
  return dp[i][j] = solve(next, j - 1);
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    dp[i][0] = x[i];
    visited[i][0] = true;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dist[0] = 1;
  for (int i = 1; i <= 60; i++) {
    dist[i] = dist[i - 1] * 2;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 60; j++) {
      solve(i, j);
    }
  }

  for (int i = 1; i <= n; i++) {
    int now = i;
    ll rest = k;
    while (rest > 0) {
      for (int j = 1; j <= 60; j++) {
        if (rest < dist[j]) {
          rest -= dist[j - 1];
          now = dp[now][j - 1];
          break;
        }
      }
    }

    cout << a[now];
    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
