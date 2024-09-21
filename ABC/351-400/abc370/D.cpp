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

int h, w, q, r, c;
set<int> tate[int(4e5 + 5)], yoko[int(4e5 + 5)];

int main() {
  cin >> h >> w >> q;
  for (int i = 0; i <= h + 1; i++) {
    for (int j = 0; j <= w + 1; j++) {
      tate[j].insert(i);
      yoko[i].insert(j);
    }
  }

  while (q--) {
    cin >> r >> c;

    auto tate_iter = tate[c].find(r);
    if (tate_iter != tate[c].end()) {
      tate[c].erase(r);
      yoko[r].erase(c);
      continue;
    }

    tate_iter = tate[c].lower_bound(r);
    if (*tate_iter != h + 1) {
      int r_ = *tate_iter;
      tate[c].erase(r_);
      yoko[r_].erase(c);
    }
    tate_iter = tate[c].lower_bound(r);
    tate_iter--;
    if (*tate_iter != 0) {
      int r_ = *tate_iter;
      tate[c].erase(r_);
      yoko[r_].erase(c);
    }

    auto yoko_iter = yoko[r].lower_bound(c);
    if (*yoko_iter != w + 1) {
      int c_ = *yoko_iter;
      tate[c_].erase(r);
      yoko[r].erase(c_);
    }
    yoko_iter = yoko[r].lower_bound(c);
    yoko_iter--;
    if (*yoko_iter != 0) {
      int c_ = *yoko_iter;
      tate[c_].erase(r);
      yoko[r].erase(c_);
    }
  }

  int ans = 0;
  for (int i = 1; i <= h; i++) {
    ans += yoko[i].size() - 2;
  }
  cout << ans << endl;

  return 0;
}
