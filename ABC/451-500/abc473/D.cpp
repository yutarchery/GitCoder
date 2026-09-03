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

vector<vector<int>> dp[15][int(2e5 + 5)];
bool visited[15][int(2e5 + 5)];

vector<vector<int>> solve(int i, int j) {
  if (visited[i][j]) {
    return dp[i][j];
  }

  visited[i][j] = true;
  if (i == 1) {
    return dp[i][j] = {{j}};
  }

  vector<vector<int>> now;
  for (int k = 0; i * k <= j; k++) {
    vector<vector<int>> tmp = solve(i - 1, j - i * k);

    for (vector<int> t : tmp) {
      t.emplace_back(k);
      now.emplace_back(t);
    }
  }
  sort(now.begin(), now.end());
  return dp[i][j] = now;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  solve(n, k);

  for (vector<int> v : dp[n][k]) {
    for (int i = 0; i < n; i++) {
      cout << v[i] << (i == n - 1 ? '\n' : ' ');
    }
  }

  return 0;
}
