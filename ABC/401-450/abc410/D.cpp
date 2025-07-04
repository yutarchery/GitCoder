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

int n, m, a[1005], b[1005], w[1005];
vector<Pii> graph[1005][1024];

bool visited[1005][1024];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> w[i];

    for (int j = 0; j < 1024; j++) {
      graph[a[i]][j].push_back({b[i], j ^ w[i]});
    }
  }

  queue<Pii> que;
  que.push({1, 0});
  visited[1][0] = true;

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    for (Pii next : graph[q.first][q.second]) {
      if (!visited[next.first][next.second]) {
        visited[next.first][next.second] = true;
        que.push(next);
      }
    }
  }

  for (int j = 0; j < 1024; j++) {
    if (visited[n][j]) {
      cout << j << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}
