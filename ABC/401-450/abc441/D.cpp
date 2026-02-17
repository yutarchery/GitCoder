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

int n, m, l, u, v;
ll c, s, t;
vector<Pil> graph[int(2e5 + 5)];

set<ll> st[15][int(2e5 + 5)];
bool visited[15][int(2e5 + 5)];
priority_queue<Pii, vector<Pii>, greater<Pii>> que;
vector<int> ans;

int main() {
  cin >> n >> m >> l >> s >> t;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v >> c;
    graph[u].push_back({v, c});
  }

  que.push({0, 1});
  visited[0][1] = true;
  st[0][1].insert(0);
  while (!que.empty()) {
    Pli now = que.top();
    que.pop();

    if (now.first == l) {
      for (ll now_c : st[l][now.second]) {
        if (s <= now_c && now_c <= t) {
          ans.push_back(now.second);
          break;
        }
      }
      continue;
    }

    for (Pil next : graph[now.second]) {
      int node = next.first;
      ll cost = next.second;

      if (!visited[now.first + 1][node]) {
        visited[now.first + 1][node] = true;
        que.push({now.first + 1, node});
      }

      for (ll now_c : st[now.first][now.second]) {
        if (cost + now_c > t) {
          break;
        }
        st[now.first + 1][node].insert(cost + now_c);
      }
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }

  return 0;
}
