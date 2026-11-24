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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, m, a, b;
bool graph[20][20];

bool visited[(1 << 18)];
int dp[(1 << 18)];

int count_node(int idx) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if ((idx & (1 << i)) != 0) {
      cnt++;
    }
  }

  return cnt;
}

bool unite_check(int idx) {
  for (int i = 0; i < n; i++) {
    if ((idx & (1 << i)) == 0) {
      continue;
    }

    idx -= (1 << i);
    for (int j = i + 1; j < n; j++) {
      if ((idx & (1 << j)) == 0) {
        continue;
      }

      if (!graph[i][j]) {
        return false;
      }
    }
  }

  return true;
}

int solve(int idx) {
  if (visited[idx]) {
    return dp[idx];
  }

  visited[idx] = true;

  if (unite_check(idx)) {
    return dp[idx] = 1;
  }

  dp[idx] = count_node(idx);
  int ans = dp[idx];
  for (int sub = idx; sub >= 1; sub = (sub - 1) & idx) {
    int other = idx ^ sub;
    ans = min(ans, solve(sub) + solve(other));
  }

  return dp[idx] = ans;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    a--;
    b--;
    graph[a][b] = true;
    graph[b][a] = true;
  }

  visited[0] = true;
  cout << solve((1 << n) - 1) << '\n';

  return 0;
}
