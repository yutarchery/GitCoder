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
vector<int> graph[105];

bool have_loop(int start) {
  bool visited[105] = {};
  queue<int> que;
  que.push(start);
  visited[start] = true;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int next : graph[now]) {
      if (next == start) {
        return true;
      } else if (!visited[next]) {
        que.push(next);
        visited[next] = true;
      }
    }
  }

  return false;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }

  for (int i = 1; i <= n; i++) {
    if (have_loop(i)) {
      No();
      return 0;
    }
  }
  Yes();

  return 0;
}
