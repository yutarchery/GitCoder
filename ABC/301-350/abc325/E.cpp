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

int n;
ll a, b, c, d[1005][1005];

vector<Pli> graph[2005];

ll ans[2005];
bool visited[2005];
priority_queue<Pli, vector<Pli>, greater<Pli>> que;

int main() {
  cin >> n >> a >> b >> c;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> d[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      graph[i].push_back({d[i][j] * a, j});
      graph[i].push_back({d[i][j] * b + c, j + n});
      graph[i + n].push_back({d[i][j] * b + c, j + n});
    }
  }

  que.push({0, 1});
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();

    if (visited[q.second]) {
      continue;
    }
    visited[q.second] = true;
    ans[q.second] = q.first;

    for (Pli next : graph[q.second]) {
      if (!visited[next.second]) {
        que.push({q.first + next.first, next.second});
      }
    }
  }

  cout << min(ans[n], ans[n * 2]) << endl;

  return 0;
}
