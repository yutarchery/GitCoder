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

int n, m, a, b;
vector<int> graph[int(2e5 + 5)];

int dist[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
  }

  queue<int> que;
  que.push(1);

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int next : graph[q]) {
      if (dist[next] == 0) {
        dist[next] = dist[q] + 1;
        que.push(next);
      }
    }
  }

  if (dist[1] == 0) {
    cout << -1 << endl;
  } else {
    cout << dist[1] << endl;
  }

  return 0;
}
