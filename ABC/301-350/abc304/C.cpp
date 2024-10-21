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

int n, d, x[2005], y[2005];
vector<int> graph[2005];
bool visited[2005];

int main() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <=
          d * d) {
        graph[i].push_back(j);
        graph[j].push_back(i);
      }
    }
  }

  queue<int> que;
  que.push(1);
  visited[1] = true;
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int nxt : graph[q]) {
      if (!visited[nxt]) {
        visited[nxt] = true;
        que.push(nxt);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    visited[i] ? Yes() : No();
  }

  return 0;
}
