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
Pll s[int(2e5 + 5)], t[int(2e5 + 5)];

ll sum = 0;
bool sum_used = false;
map<ll, vector<ll>> sx, sy, tx, ty;
map<ll, bool> used_x, used_y;

bool check_x() {
  for (int i = 1; i <= n; i++) {
    if (used_x[s[i].first]) {
      continue;
    }

    used_x[s[i].first] = true;
    if (sx[s[i].first].size() != tx[s[i].first].size()) {
      return false;
    }
    sort(sx[s[i].first].begin(), sx[s[i].first].end());
    sort(tx[s[i].first].begin(), tx[s[i].first].end(), greater<int>());

    if (!sum_used) {
      sum_used = true;
      sum = sx[s[i].first][0] + tx[s[i].first][0];
    }
    for (int j = 0; j < sx[s[i].first].size(); j++) {
      if (sum != sx[s[i].first][j] + tx[s[i].first][j]) {
        return false;
      }
    }
  }
  return true;
}

bool check_y() {
  sum_used = false;

  for (int i = 1; i <= n; i++) {
    if (used_y[s[i].second]) {
      continue;
    }

    used_y[s[i].second] = true;
    if (sy[s[i].second].size() != ty[s[i].second].size()) {
      return false;
    }
    sort(sy[s[i].second].begin(), sy[s[i].second].end());
    sort(ty[s[i].second].begin(), ty[s[i].second].end(), greater<int>());

    if (!sum_used) {
      sum_used = true;
      sum = sy[s[i].second][0] + ty[s[i].second][0];
    }

    for (int j = 0; j < sy[s[i].second].size(); j++) {
      if (sum != sy[s[i].second][j] + ty[s[i].second][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i].first >> s[i].second;
    sx[s[i].first].push_back(s[i].second);
    sy[s[i].second].push_back(s[i].first);
  }
  for (int i = 1; i <= n; i++) {
    cin >> t[i].first >> t[i].second;
    tx[t[i].first].push_back(t[i].second);
    ty[t[i].second].push_back(t[i].first);
  }

  if (check_x() || check_y()) {
    Yes();
  } else {
    sort(s + 1, s + n + 1);
    sort(t + 1, t + n + 1);

    for (int i = 1; i <= n; i++) {
      if (s[i] != t[i]) {
        No();
        return 0;
      }
    }
    Yes();
  }

  return 0;
}