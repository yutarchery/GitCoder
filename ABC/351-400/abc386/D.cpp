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

int n, m, x[int(2e5 + 5)], y[int(2e5 + 5)];
char c[int(2e5 + 5)];

map<int, bool> visited;
map<int, int> idx;
vector<int> locs;
vector<pair<int, char>> pair_r[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x[i] >> y[i] >> c[i];
    if (!visited[x[i]]) {
      visited[x[i]] = true;
      locs.push_back(x[i]);
    }
  }
  sort(locs.begin(), locs.end());
  for (int i = 0; i < locs.size(); i++) {
    idx[locs[i]] = i;
  }

  for (int i = 1; i <= m; i++) {
    pair_r[idx[x[i]]].push_back({y[i], c[i]});
  }
  for (int i = 0; i < locs.size(); i++) {
    pair_r[i].push_back({0, 'B'});
    pair_r[i].push_back({n + 1, 'W'});
    sort(pair_r[i].begin(), pair_r[i].end());
  }

  int now_max = n;
  for (int i = 0; i < locs.size(); i++) {
    int now_l, now_r;
    bool white = false;
    for (int j = 0; j < pair_r[i].size(); j++) {
      if (pair_r[i][j].second == 'B') {
        if (white) {
          No();
          return 0;
        } else {
          now_l = pair_r[i][j].first;
        }
      } else {
        if (!white) {
          now_r = pair_r[i][j].first - 1;
          white = true;
        }
      }
    }

    if (now_max < now_l) {
      No();
      return 0;
    } else if (now_r <= now_max) {
      now_max = now_r;
    }
  }

  Yes();
  return 0;
}
