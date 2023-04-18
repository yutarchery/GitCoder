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
ll sx, sy, tx, ty;
ll x[3005], y[3005], r[3005];

int s, t;

vector<int> graph[3005];
bool visited[3005];

void dfs(int node) {
  visited[node] = true;

  for (int next : graph[node]) {
    if (!visited[next]) {
      dfs(next);
    }
  }
  return;
}

bool is_cross(int a, int b) {
  ll dx = x[a] - x[b], dy = y[a] - y[b];

  ll center_dist = dx * dx + dy * dy;
  ll r_diff = r[a] - r[b], r_sum = r[a] + r[b];

  return r_diff * r_diff <= center_dist && center_dist <= r_sum * r_sum;
}

void make_graph() {
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (is_cross(i, j)) {
        graph[i].push_back(j);
        graph[j].push_back(i);
      }
    }
  }
}

int main() {
  cin >> n >> sx >> sy >> tx >> ty;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> r[i];

    ll dsx = sx - x[i], dsy = sy - y[i];
    if (dsx * dsx + dsy * dsy == r[i] * r[i]) {
      s = i;
    }

    ll dtx = tx - x[i], dty = ty - y[i];
    if (dtx * dtx + dty * dty == r[i] * r[i]) {
      t = i;
    }
  }

  make_graph();
  dfs(s);

  if (visited[t]) {
    Yes();
  } else {
    No();
  }

  return 0;
}