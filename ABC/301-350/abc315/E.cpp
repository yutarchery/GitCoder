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

int n, c[int(2e5 + 5)];
vector<int> p[int(2e5 + 5)];

bool visited[int(2e5 + 5)];
vector<int> ans, graph[int(2e5 + 5)];
queue<int> que;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    p[i].resize(c[i]);
    for (int j = 0; j < c[i]; j++) {
      cin >> p[i][j];
      graph[p[i][j]].push_back(i);
    }
  }

  que.push(1);
  visited[1] = true;
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int next : p[q]) {
      if (!visited[next]) {
        visited[next] = true;
        que.push(next);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i] && c[i] == 0) {
      que.push(i);
    }
  }
  while (!que.empty()) {
    int q = que.front();
    que.pop();

    if (q == 1) {
      break;
    }
    ans.push_back(q);

    for (int next : graph[q]) {
      c[next]--;
      if (c[next] == 0 && visited[next]) {
        que.push(next);
      }
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i == ans.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
