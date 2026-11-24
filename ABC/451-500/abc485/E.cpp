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
int u[int(2e5 + 5)], v[int(2e5 + 5)], c[int(2e5 + 5)];

set<Pii> graph[int(2e5 + 5)];

int ans[int(2e5 + 5)];
bool visited[int(2e5 + 5)];

map<Pii, int> dist;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i] >> c[i];
    graph[u[i]].insert({v[i], c[i]});
  }

  queue<Pii> que;
  que.push({1, 0});
  visited[1] = true;

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    auto iter = graph[q.first].begin();
    while (iter != graph[q.first].end()) {
      Pii next = *iter;
      iter++;

      if (next.second == q.second) {
        continue;
      }
      if (!visited[next.first]) {
        visited[next.first] = true;
        ans[next.first] = dist[q] + 1;
      }

      dist[next] = dist[q] + 1;
      que.push(next);
      graph[q.first].erase(next);
    }
  }

  cout << (visited[n] ? ans[n] : -1) << '\n';

  return 0;
}
