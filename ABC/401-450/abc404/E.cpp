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

int n, c[2005], a[2005];

vector<int> graph[2005], v;

int solve(int from, int to) {
  int dist[2005] = {};
  bool visited[2005] = {};

  queue<int> que;
  que.push(from);
  visited[from] = true;

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int next : graph[q]) {
      if (!visited[next]) {
        dist[next] = dist[q] + 1;
        visited[next] = true;
        que.push(next);

        if (next == to) {
          return dist[to];
        }
      }
    }
  }

  return dist[to];
}

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> c[i];

    for (int j = i - c[i]; j <= i - 1; j++) {
      graph[i].push_back(j);
    }
  }

  v.push_back(0);
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      v.push_back(i);
    }
  }
  reverse(v.begin(), v.end());

  int ans = 0;
  for (int i = 0; i < v.size() - 1; i++) {
    ans += solve(v[i], v[i + 1]);
  }
  cout << ans << endl;

  return 0;
}
