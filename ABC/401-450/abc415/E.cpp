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
vector<ll> a[int(2e5 + 5)];
ll p[int(3e5 + 5)];

vector<bool> visited[int(2e5 + 5)];

bool solve(ll start) {
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      visited[i][j] = false;
    }
  }

  priority_queue<array<ll, 4>, vector<array<ll, 4>>, greater<array<ll, 4>>> que;
  que.push({2, -1 * start, 1, 1});
  while (!que.empty()) {
    array<ll, 4> q = que.top();
    que.pop();
    int idx = q[0], i = q[2], j = q[3];
    ll rest = -1 * q[1];
    if (visited[i][j]) {
      continue;
    }
    if (rest + a[i][j] < p[idx]) {
      continue;
    }

    visited[i][j] = true;
    rest = rest + a[i][j] - p[idx];
    if (i + 1 <= h) {
      que.push({idx + 1, -1 * rest, i + 1, j});
    }
    if (j + 1 <= w) {
      que.push({idx + 1, -1 * rest, i, j + 1});
    }
  }

  return visited[h][w];
}

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    a[i].resize(w + 2);
    visited[i].resize(w + 2);
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 2; i <= h + w; i++) {
    cin >> p[i];
  }

  if (solve(0)) {
    cout << 0 << endl;
    return 0;
  }

  ll ng = 0, ok = 1e16;
  while (ok - ng > 1) {
    ll now = (ng + ok) / 2;
    if (solve(now)) {
      ok = now;
    } else {
      ng = now;
    }
  }
  cout << ok << endl;

  return 0;
}
