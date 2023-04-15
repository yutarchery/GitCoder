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

int n, x, y;
vector<int> graph[int(2e5 + 5)];
bool visited[int(2e5 + 5)];
vector<int> ans;

bool solve(int node) {
  visited[node] = true;

  if (node == y) {
    ans.push_back(y);
    return true;
  }

  bool flag = false;
  for (int next : graph[node]) {
    if (!visited[next]) {
      flag = flag | solve(next);
    }
  }

  if (flag) {
    ans.push_back(node);
  }

  return flag;
}

int main() {
  cin >> n >> x >> y;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  solve(x);

  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i];
    if (i == 0) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
  return 0;
}