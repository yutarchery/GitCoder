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

int n, m;
vector<int> graph[int(3e5 + 5)];

int ans[int(3e5 + 5)];
vector<int> now;
priority_queue<int, vector<int>, greater<int>> que;
bool visited[int(3e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].emplace_back(v);
  }

  que.push(1);
  visited[1] = true;
  for (int i = 1; i <= n; i++) {
    while (!que.empty()) {
      int q = que.top();
      if (q > i) {
        break;
      }
      que.pop();
      now.emplace_back(q);
      for (int next : graph[q]) {
        if (!visited[next]) {
          visited[next] = true;
          que.push(next);
        }
      }
    }

    if (now.size() == i) {
      ans[i] = que.size();
    } else {
      ans[i] = -1;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}
