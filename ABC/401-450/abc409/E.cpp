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

int n, x[int(1e5 + 5)], u[int(1e5 + 5)], v[int(1e5 + 5)], w[int(1e5 + 5)];
vector<Pli> graph[int(1e5 + 5)];

int rest[int(1e5 + 5)];
bool visited[int(1e5 + 5)];

int calc_rest(int now, int par = -1) {
  int ans = x[now];
  for (Pli next : graph[now]) {
    if (next.second == par) {
      continue;
    } else {
      ans += calc_rest(next.second, now);
    }
  }
  return rest[now] = ans;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    cin >> u[i] >> v[i] >> w[i];
    graph[u[i]].push_back({w[i], v[i]});
    graph[v[i]].push_back({w[i], u[i]});
  }
  calc_rest(1);

  queue<int> que;
  que.push(1);
  visited[1] = true;

  ll ans = 0;
  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (Pli next : graph[now]) {
      if (visited[next.second]) {
        continue;
      } else {
        visited[next.second] = true;
        ans += next.first * abs(rest[next.second]);
        que.push(next.second);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
