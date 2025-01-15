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

int h, w;
ll a[55][55];

const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

priority_queue<pair<int, Pii>, vector<pair<int, Pii>>, greater<pair<int, Pii>>>
    que;
bool visited[55][55][3];
ll dist[55][55][3];

void calc_dist(int idx) {
  while (!que.empty()) {
    pair<int, Pii> q = que.top();
    que.pop();
    int i = q.second.first, j = q.second.second;
    if (visited[i][j][idx]) {
      continue;
    }
    visited[i][j][idx] = true;
    dist[i][j][idx] = q.first;

    for (int k = 0; k < 4; k++) {
      int next_i = i + di[k], next_j = j + dj[k];
      if (1 <= next_i && next_i <= h && 1 <= next_j && next_j <= w) {
        que.push({q.first + a[next_i][next_j], {next_i, next_j}});
      }
    }
  }

  return;
}

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }

  que.push({0, {h, 1}});
  calc_dist(0);
  que.push({0, {h, w}});
  calc_dist(1);
  que.push({0, {1, w}});
  calc_dist(2);

  ll ans = 1e16;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      ans =
          min(ans, dist[i][j][0] + dist[i][j][1] + dist[i][j][2] - a[i][j] * 2);
    }
  }
  cout << ans << endl;

  return 0;
}
