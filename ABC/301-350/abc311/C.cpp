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

int n, a[int(2e5 + 5)];
vector<int> graph[int(2e5 + 5)];

int before_node[int(2e5 + 5)];
bool visited[int(2e5 + 5)];
vector<int> ans;

int solve(int start) {
  fill(visited + 1, visited + n + 1, false);

  queue<int> que;
  que.push(start);
  visited[start] = true;

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int next : graph[now]) {
      before_node[next] = now;
      if (visited[next]) {
        return next;
      }
      visited[next] = true;
      que.push(next);
    }
  }

  return 0;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    graph[i].push_back(a[i]);
  }

  for (int i = 1; i <= n; i++) {
    int start = solve(i);
    if (start != 0) {
      ans.push_back(start);
      break;
    }
  }

  int start = ans[0], now = ans[0];
  while (before_node[now] != start) {
    now = before_node[now];
    ans.push_back(now);
  }

  int m = ans.size();
  cout << m << endl;
  for (int i = m - 1; i >= 0; i--) {
    cout << ans[i];
    if (i == 0) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}