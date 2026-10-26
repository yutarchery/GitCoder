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

int n, m, s, t, a[int(2e5 + 5)], b[int(2e5 + 5)];

vector<int> graph[int(2e5 + 5)];
vector<Pii> re_graph[int(2e5 + 5)];

bool visited[int(2e5 + 5)];
int ans[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> s >> t;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
    graph[a[i]].emplace_back(b[i]);
  }
  for (int i = 1; i <= n; i++) {
    sort(graph[i].begin(), graph[i].end());
    for (int j = 0; j < graph[i].size(); j++) {
      if (j == 0) {
        re_graph[i].push_back({0, graph[i][j]});
      } else {
        re_graph[i].push_back({1, graph[i][j]});
      }
    }
  }

  priority_queue<Pii, vector<Pii>, greater<Pii>> que;
  que.push({0, s});

  while (!que.empty()) {
    Pii q = que.top();
    que.pop();

    if (visited[q.second]) {
      continue;
    }
    visited[q.second] = true;
    ans[q.second] = q.first;

    for (Pii next : re_graph[q.second]) {
      que.push({q.first + next.first, next.second});
    }
  }

  cout << (visited[t] ? ans[t] : -1) << '\n';

  return 0;
}
