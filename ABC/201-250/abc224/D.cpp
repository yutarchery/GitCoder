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

int m, u, v, p[10];
bool graph[10][10];

map<string, bool> visited;
map<string, int> ans;

int main() {
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u][v] = true;
    graph[v][u] = true;
  }

  p[0] = 45;
  for (int i = 1; i <= 8; i++) {
    cin >> p[i];
    p[0] -= p[i];
  }

  string start = "";
  for (int i = 0; i <= 8; i++) {
    start += char('0' + p[i]);
  }

  visited[start] = true;
  queue<string> que;
  que.push(start);

  while (!que.empty()) {
    string q = que.front();
    que.pop();

    int now = q[0] - '0';
    for (int i = 1; i <= 8; i++) {
      int next = q[i] - '0';

      if (!graph[now][next]) {
        continue;
      }

      string r = q;
      swap(r[0], r[i]);
      if (!visited[r]) {
        que.push(r);
        visited[r] = true;
        ans[r] = ans[q] + 1;
      }
    }
  }

  const string q = "912345678";
  if (visited[q]) {
    cout << ans[q] << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
