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

int n, m, u, v;
vector<int> graph[int(2e5 + 5)];
int ans = 0;

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    if (u == v) {
      ans++;
      continue;
    }
    if (u > v) {
      swap(u, v);
    }
    graph[u].push_back(v);
  }

  for (int i = 1; i <= n; i++) {
    sort(graph[i].begin(), graph[i].end());

    for (int j = 1; j < graph[i].size(); j++) {
      if (graph[i][j - 1] == graph[i][j]) {
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
