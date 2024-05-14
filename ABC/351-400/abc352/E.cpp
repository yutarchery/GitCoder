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

int n, m, k, a;
ll c;
vector<Pli> graph[int(4e5 + 5)];

priority_queue<Pli, vector<Pli>, greater<Pli>> que;
ll ans = 0;
bool visited[int(4e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> k >> c;
    for (int j = 1; j <= k; j++) {
      cin >> a;
      graph[a].push_back({0, n + i});
      graph[n + i].push_back({c, a});
    }
  }

  que.push({0, 1});
  while (!que.empty()) {
    Pli now = que.top();
    que.pop();

    if (visited[now.second]) {
      continue;
    }

    visited[now.second] = true;
    ans += now.first;

    for (Pli next : graph[now.second]) {
      if (visited[next.second]) {
        continue;
      }
      que.push(next);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;

  return 0;
}
