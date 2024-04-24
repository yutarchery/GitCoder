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

int n, m;
ll k, graph[10][10];
bool used[10][10];
set<ll> dp[300];

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;

    graph[u - 1][v - 1] = w;
    graph[v - 1][u - 1] = w;
    used[u - 1][v - 1] = true;
    used[v - 1][u - 1] = true;
  }

  for (int i = 0; i < n; i++) {
    dp[(1 << i)].insert(0);
  }

  for (int i = 0; i < (1 << n); i++) {
    if (dp[i].size() == 0) {
      continue;
    }

    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0) {
        continue;
      }
      for (int kk = 0; kk < n; kk++) {
        if ((i & (1 << kk)) != 0) {
          continue;
        }
        if (!used[j][kk]) {
          continue;
        }

        int nxt = i + (1 << kk);
        for (ll l : dp[i]) {
          dp[nxt].insert((l + graph[j][kk]) % k);
        }
      }
    }
  }

  cout << *(dp[(1 << n) - 1].begin()) << endl;

  return 0;
}
