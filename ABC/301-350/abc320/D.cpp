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

int n, m, a, b, x, y;
vector<pair<int, Pll>> graph[int(2e5 + 5)];
Pll place[int(2e5 + 5)];
bool visited[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b >> x >> y;
    graph[a].push_back({b, {x, y}});
    graph[b].push_back({a, {-1 * x, -1 * y}});
  }

  queue<int> que;
  que.push(1);
  visited[1] = true;

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (pair<int, Pll> next : graph[q]) {
      if (visited[next.first]) {
        continue;
      }

      visited[next.first] = true;
      que.push(next.first);

      place[next.first].first = place[q].first + next.second.first;
      place[next.first].second = place[q].second + next.second.second;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i]) {
      cout << place[i].first << " " << place[i].second << endl;
    } else {
      cout << "undecidable" << endl;
    }
  }

  return 0;
}