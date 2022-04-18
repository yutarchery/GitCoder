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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

const int start = 1;
int n, child[int(2e5 + 5)];
vector<int> graph[int(2e5 + 5)];
bool visited[int(2e5 + 5)];
ll dist[int(2e5 + 5)], sum[int(2e5 + 5)];

int countChild(int node) {
  int ans = 0;
  for (int next : graph[node]) {
    if (!visited[next]) {
      visited[next] = true;
      ans += countChild(next) + 1;
    }
  }
  return child[node] = ans;
}

void calcDist() {
  queue<int> que;
  que.push(start);
  fill(visited, visited + n + 1, false);
  visited[start] = true;

  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int next : graph[q]) {
      if (!visited[next]) {
        visited[next] = true;
        que.push(next);
        dist[next] = dist[q] + 1;
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  fill(visited, visited + n + 1, false);
  visited[start] = true;
  countChild(start);

  calcDist();

  for (int i = 1; i <= n; i++) {
    sum[start] += dist[i];
  }

  queue<int> que;
  que.push(start);
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int next : graph[q]) {
      if (sum[next] == 0) {
        que.push(next);
        sum[next] = sum[q] + (n - 2 * (child[next] + 1));
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << sum[i] << endl;
  }

  return 0;
}