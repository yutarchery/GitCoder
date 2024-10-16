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
ll w;
vector<Pli> graph[int(2e5 + 5)];

ll ans[int(2e5 + 5)];
int min_node = 1;
bool visited[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    graph[u].push_back({w, v});
    graph[v].push_back({-1 * w, u});
  }

  queue<int> que;
  que.push(1);
  visited[1] = true;

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (Pli nxt : graph[q]) {
      if (!visited[nxt.second]) {
        visited[nxt.second] = true;
        ans[nxt.second] = ans[q] + nxt.first;
        que.push(nxt.second);
      }
    }

    if (que.empty()) {
      for (int i = min_node; i <= n; i++) {
        if (!visited[i]) {
          que.push(i);
          visited[i] = true;
          min_node = i;
          break;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i];
    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
