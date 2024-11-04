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

int n, u[int(2e5 + 5)], v[int(2e5 + 5)], cnt[int(2e5 + 5)];
vector<int> graph[int(2e5 + 5)];

queue<int> que;
bool visited[int(2e5 + 5)];
int dist[int(2e5 + 5)];
vector<int> ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u[i] >> v[i];
    graph[u[i]].push_back(v[i]);
    graph[v[i]].push_back(u[i]);
    cnt[u[i]]++;
    cnt[v[i]]++;
  }

  int start;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 1) {
      start = graph[i][0];
    }
  }
  que.push(start);
  visited[start] = true;
  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int next : graph[q]) {
      if (!visited[next]) {
        visited[next] = true;
        dist[next] = dist[q] + 1;
        que.push(next);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (dist[i] % 3 == 0) {
      ans.push_back(graph[i].size());
    }
  }
  sort(ans.begin(), ans.end());

  cout << ans[0];
  for (int i = 1; i < ans.size(); i++) {
    cout << " " << ans[i];
  }
  cout << endl;

  return 0;
}
