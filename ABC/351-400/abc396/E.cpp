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

int n, m, x[int(2e5 + 5)], y[int(2e5 + 5)];
ll z[int(2e5 + 5)];

vector<Pli> graph[int(2e5 + 5)];
bool ans[int(2e5 + 5)][60], visited[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x[i] >> y[i] >> z[i];
    graph[x[i]].push_back({z[i], y[i]});
    graph[y[i]].push_back({z[i], x[i]});
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i]) {
      continue;
    }

    visited[i] = true;
    vector<int> tmp;
    queue<int> que;
    que.push(i);

    while (!que.empty()) {
      int q = que.front();
      tmp.push_back(q);
      que.pop();

      for (Pli next : graph[q]) {
        if (visited[next.second]) {
          for (int j = 0; j < 60; j++) {
            if (((next.first & (1ll << j)) > 0) !=
                (ans[q][j] ^ ans[next.second][j])) {
              cout << -1 << endl;
              return 0;
            }
          }
        } else {
          visited[next.second] = true;
          que.push(next.second);
          for (int j = 0; j < 60; j++) {
            ans[next.second][j] = ((next.first & (1ll << j)) > 0) ^ ans[q][j];
          }
        }
      }
    }

    for (int j = 0; j < 60; j++) {
      int cnt = 0;
      for (int k : tmp) {
        if (ans[k][j]) {
          cnt++;
        }
      }

      if (cnt * 2 > tmp.size()) {
        for (int k : tmp) {
          ans[k][j] = !(ans[k][j]);
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    ll sum = 0;
    for (int j = 0; j < 60; j++) {
      sum += (ans[i][j] ? (1ll << j) : 0);
    }

    cout << sum << (i == n ? '\n' : ' ');
  }

  return 0;
}
