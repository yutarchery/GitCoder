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

int ans = 0;
bool visited[int(2e5 + 5)];
set<Pii> used;

void solve(int start) {
  queue<int> que;
  que.push(start);
  visited[start] = true;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int next : graph[now]) {
      if (!visited[next]) {
        used.insert({min(now, next), max(now, next)});
        visited[next] = true;
        que.push(next);
      } else {
        auto iter = used.find({min(now, next), max(now, next)});
        if (iter != used.end()) {
          continue;
        } else {
          used.insert({min(now, next), max(now, next)});
          ans++;
        }
      }
    }
  }

  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      solve(i);
    }
  }
  cout << ans << endl;

  return 0;
}
