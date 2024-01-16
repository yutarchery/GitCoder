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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, m, cnt[int(1e5 + 5)], ans;
vector<int> graph[int(1e5 + 5)];

bool visited[int(1e5 + 5)];

int solve(int node) {
  if (visited[node]) {
    return cnt[node];
  }

  visited[node] = true;
  int res = 0;
  for (int next : graph[node]) {
    res = max(res, solve(next) + 1);
  }
  return cnt[node] = res;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
  }

  for (int i = 1; i <= n; i++) {
    ans = max(ans, solve(i));
  }
  cout << ans << endl;

  return 0;
}
