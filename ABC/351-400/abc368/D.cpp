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

int n, k, a, b;
vector<int> graph[int(2e5 + 5)];
int v[int(2e5 + 5)];

bool idx[int(2e5 + 5)], visited[int(2e5 + 5)], dp[int(2e5 + 5)];

bool solve(int node) {
  if (visited[node]) {
    return dp[node];
  }

  visited[node] = true;
  bool res = idx[node];
  for (int next : graph[node]) {
    if (visited[next]) {
      continue;
    }
    res = res | solve(next);
  }

  return dp[node] = res;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n - 1; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 1; i <= k; i++) {
    cin >> v[i];
    idx[v[i]] = true;
  }
  solve(v[1]);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (dp[i]) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
