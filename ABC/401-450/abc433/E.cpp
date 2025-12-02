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

int n, m;
int x[int(2e5 + 5)], y[int(2e5 + 5)];

int x_idx[int(2e5 + 5)], y_idx[int(2e5 + 5)];
bool visited_x[int(2e5 + 5)], visited_y[int(2e5 + 5)];

vector<int> ans[int(2e5 + 5)];
set<Pii> rest_i[int(2e5 + 5)], rest_j[int(2e5 + 5)], rest;
int x_max[int(2e5 + 5)], y_max[int(2e5 + 5)];

void prepare() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    x_idx[x[i]] = i;
    visited_x[x[i]] = true;
  }
  for (int j = 0; j < m; j++) {
    cin >> y[j];
    y_idx[y[j]] = j;
    visited_y[y[j]] = true;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      rest_i[i].insert({y[j], j});
      rest_j[j].insert({x[i], i});
    }
  }

  for (int i = 0; i < n; i++) {
    ans[i].resize(m, 0);
  }

  return;
}

void solve() {
  for (int k = n * m; k >= 1; k--) {
    if (visited_x[k] && visited_y[k]) {
      int i = x_idx[k], j = y_idx[k];

      auto iter_i = rest_i[i].lower_bound({k, j});
      while (iter_i != rest_i[i].end()) {
        int now_j = (*iter_i).second;
        rest.insert({i, now_j});
        iter_i++;
        rest_i[i].erase({y[now_j], now_j});
      }

      auto iter_j = rest_j[j].lower_bound({k, i});
      while (iter_j != rest_j[j].end()) {
        int now_i = (*iter_j).second;
        rest.insert({now_i, j});
        iter_j++;
        rest_j[j].erase({x[now_i], now_i});
      }

      ans[i][j] = k;
      rest.erase({i, j});
    } else if (visited_x[k]) {
      int i = x_idx[k];
      auto iter_i = rest_i[i].lower_bound({k, 0});

      if (iter_i == rest_i[i].end()) {
        No();
        return;
      }

      int j = (*iter_i).second;
      while (iter_i != rest_i[i].end()) {
        int now_j = (*iter_i).second;
        rest.insert({i, now_j});
        iter_i++;
        rest_i[i].erase({y[now_j], now_j});
      }

      ans[i][j] = k;
      rest.erase({i, j});
    } else if (visited_y[k]) {
      int j = y_idx[k];
      auto iter_j = rest_j[j].lower_bound({k, 0});

      if (iter_j == rest_j[j].end()) {
        No();
        return;
      }

      int i = (*iter_j).second;
      while (iter_j != rest_j[j].end()) {
        int now_i = (*iter_j).second;
        rest.insert({now_i, j});
        iter_j++;
        rest_j[j].erase({x[now_i], now_i});
      }

      ans[i][j] = k;
      rest.erase({i, j});
    } else {
      if (rest.empty()) {
        No();
        return;
      } else {
        auto iter = rest.begin();
        int i = (*iter).first, j = (*iter).second;
        ans[i][j] = k;
        rest.erase({i, j});
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      x_max[i] = max(x_max[i], ans[i][j]);
      y_max[j] = max(y_max[j], ans[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    if (x_max[i] != x[i]) {
      No();
      return;
    }
  }
  for (int j = 0; j < m; j++) {
    if (y_max[j] != y[j]) {
      No();
      return;
    }
  }

  Yes();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j] << ((j == m - 1) ? '\n' : ' ');
    }
  }

  return;
}

void reset() {
  fill(x, x + n, 0);
  fill(y, y + m, 0);
  fill(x_idx + 1, x_idx + n * m + 1, 0);
  fill(y_idx + 1, y_idx + n * m + 1, 0);
  fill(visited_x + 1, visited_x + n * m + 1, false);
  fill(visited_y + 1, visited_y + n * m + 1, false);
  fill(x_max, x_max + n, 0);
  fill(y_max, y_max + m, 0);

  for (int i = 0; i < n; i++) {
    auto iter = rest_i[i].begin();
    while (iter != rest_i[i].end()) {
      Pii now = *iter;
      iter++;
      rest_i[i].erase(now);
    }
  }
  for (int j = 0; j < m; j++) {
    auto iter = rest_j[j].begin();
    while (iter != rest_j[j].end()) {
      Pii now = *iter;
      iter++;
      rest_j[j].erase(now);
    }
  }

  auto iter = rest.begin();
  while (iter != rest.end()) {
    Pii now = *iter;
    iter++;
    rest.erase(now);
  }

  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    prepare();
    solve();
    reset();
  }

  return 0;
}
