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
ll a[int(2e5 + 5)];
vector<int> graph[int(2e5 + 5)];

ll sum[int(2e5 + 5)];
bool visited[int(2e5 + 5)];
bool solve(ll num) {
  fill(sum, sum + n + 1, 0);
  fill(visited, visited + n + 1, false);

  queue<int> que;
  for (int i = 1; i <= n; i++) {
    for (int j : graph[i]) {
      sum[i] += a[j];
    }

    if (sum[i] <= num) {
      que.push(i);
      visited[i] = true;
    }
  }

  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int next : graph[q]) {
      sum[next] -= a[q];
      if (!visited[next] && sum[next] <= num) {
        visited[next] = true;
        que.push(next);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      return false;
    }
  }

  return true;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  ll l = -1, r = 1e18;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (solve(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << endl;

  return 0;
}