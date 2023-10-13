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

int n, m, k;
vector<int> graph[int(2e5 + 5)];
priority_queue<Pii> que;

bool visited[int(2e5 + 5)];
vector<int> ans;

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 0; i < k; i++) {
    int p, h;
    cin >> p >> h;
    que.push({h, p});
  }

  while (!que.empty()) {
    Pii now = que.top();
    que.pop();

    if (visited[now.second]) {
      continue;
    }

    visited[now.second] = true;
    ans.push_back(now.second);
    if (now.first == 0) {
      continue;
    }

    for (int next : graph[now.second]) {
      if (!visited[next]) {
        que.push({now.first - 1, next});
      }
    }
  }

  int g = ans.size();
  sort(ans.begin(), ans.end());

  cout << g << endl;
  for (int i = 0; i < g; i++) {
    cout << ans[i];
    if (i == g - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}