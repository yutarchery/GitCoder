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
int u, v;
ll b;

vector<Pli> graph[int(2e5 + 5)];
ll ans[int(2e5 + 5)];

priority_queue<Pli, vector<Pli>, greater<Pli>> que;
bool visited[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> u >> v >> b;
    graph[u].push_back({b, v});
    graph[v].push_back({b, u});
  }

  que.push({a[1], 1});
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();

    if (visited[q.second]) {
      continue;
    }
    visited[q.second] = true;
    ans[q.second] = q.first;

    for (Pli next : graph[q.second]) {
      if (visited[next.second]) {
        continue;
      }

      que.push({q.first + next.first + a[next.second], next.second});
    }
  }

  for (int i = 2; i <= n; i++) {
    cout << ans[i];
    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
