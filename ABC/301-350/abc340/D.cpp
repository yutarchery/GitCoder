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
ll a[int(2e5 + 5)], b[int(2e5 + 5)];
int x[int(2e5 + 5)];

vector<Pli> graph[int(2e5 + 5)];
bool visited[int(2e5 + 5)];
ll dist[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> a[i] >> b[i] >> x[i];
    graph[i].push_back({a[i], i + 1});
    graph[i].push_back({b[i], x[i]});
  }

  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  que.push({0, 1});
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();
    if (visited[q.second]) {
      continue;
    }

    visited[q.second] = true;
    dist[q.second] = q.first;
    for (Pli next : graph[q.second]) {
      que.push({q.first + next.first, next.second});
    }
  }
  cout << dist[n] << endl;

  return 0;
}
