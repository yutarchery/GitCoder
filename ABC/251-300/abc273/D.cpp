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

int h, w, rs, cs;
int n, r[int(2e5 + 5)], c[int(2e5 + 5)];
int q, l[int(2e5 + 5)];
char d[int(2e5 + 5)];

map<int, vector<int>> wall_r, wall_c;
map<int, bool> visited_r, visited_c;

Pii wall_r_search() {
  int now_l = 0, now_r = wall_r[rs].size();
  while (now_r - now_l > 1) {
    int mid = (now_l + now_r) / 2;
    if (wall_r[rs][mid] < cs) {
      now_l = mid;
    } else {
      now_r = mid;
    }
  }
  return {now_l, now_r};
}

Pii wall_c_search() {
  int now_l = 0, now_r = wall_c[cs].size() - 1;

  while (now_r - now_l > 1) {
    int mid = (now_l + now_r) / 2;
    if (wall_c[cs][mid] < rs) {
      now_l = mid;
    } else {
      now_r = mid;
    }
  }
  return {now_l, now_r};
}

int main() {
  cin >> h >> w >> rs >> cs;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> r[i] >> c[i];
    wall_r[r[i]].push_back(c[i]);
    wall_c[c[i]].push_back(r[i]);
  }

  for (int i = 1; i <= n; i++) {
    if (!visited_r[r[i]]) {
      wall_r[r[i]].push_back(0);
      wall_r[r[i]].push_back(w + 1);
      sort(wall_r[r[i]].begin(), wall_r[r[i]].end());
      visited_r[r[i]] = true;
    }

    if (!visited_c[c[i]]) {
      wall_c[c[i]].push_back(0);
      wall_c[c[i]].push_back(h + 1);
      sort(wall_c[c[i]].begin(), wall_c[c[i]].end());
      visited_c[c[i]] = true;
    }
  }

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> d[i] >> l[i];
  }

  for (int i = 1; i <= q; i++) {
    if (!visited_r[rs]) {
      wall_r[rs] = {0, w + 1};
      visited_r[rs] = true;
    }
    if (!visited_c[cs]) {
      wall_c[cs] = {0, h + 1};
      visited_c[cs] = true;
    }

    if (d[i] == 'L' || d[i] == 'R') {
      Pii p = wall_r_search();
      if (d[i] == 'L') {
        cs = max(wall_r[rs][p.first] + 1, cs - l[i]);
      } else {
        cs = min(wall_r[rs][p.second] - 1, cs + l[i]);
      }
    } else {
      Pii p = wall_c_search();
      if (d[i] == 'U') {
        rs = max(wall_c[cs][p.first] + 1, rs - l[i]);
      } else {
        rs = min(wall_c[cs][p.second] - 1, rs + l[i]);
      }
    }

    cout << rs << " " << cs << endl;
  }

  return 0;
}
