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
char s[int(2e5 + 5)];

struct node_info {
  int now, from, dist;
};
queue<node_info> que;
vector<node_info> ans[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];

    if (s[i] == 'S') {
      que.push({i, i, 0});
      ans[i].push_back({i, i, 0});
    }
  }

  while (!que.empty()) {
    node_info q = que.front();
    que.pop();

    for (int next : graph[q.now]) {
      if (ans[next].size() == 0) {
        ans[next].push_back({next, q.from, q.dist + 1});
        que.push({next, q.from, q.dist + 1});
      } else if (ans[next].size() == 1) {
        if (ans[next][0].from != q.from) {
          ans[next].push_back({next, q.from, q.dist + 1});
          que.push({next, q.from, q.dist + 1});
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (s[i] == 'D') {
      cout << ans[i][0].dist + ans[i][1].dist << endl;
    }
  }

  return 0;
}
