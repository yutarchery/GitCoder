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

int n, x, y, a[int(1e3 + 5)];

int x_idx, y_idx;
set<int> st_x[int(1e3 + 5)], st_y[int(1e3 + 5)];

int main() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st_y[0].insert(0);
  st_x[1].insert(a[1]);

  for (int i = 2; i <= n; i++) {
    if (i % 2 == 0) {
      for (int s : st_y[i - 2]) {
        st_y[i].insert(s + a[i]);
        st_y[i].insert(s - a[i]);
      }
    } else {
      for (int s : st_x[i - 2]) {
        st_x[i].insert(s + a[i]);
        st_x[i].insert(s - a[i]);
      }
    }
  }

  bool flag_x = false, flag_y = false;
  if (n % 2 == 0) {
    for (int s : st_x[n - 1]) {
      if (s == x) {
        flag_x = true;
      }
    }
    for (int s : st_y[n]) {
      if (s == y) {
        flag_y = true;
      }
    }
  } else {
    for (int s : st_x[n]) {
      if (s == x) {
        flag_x = true;
      }
    }
    for (int s : st_y[n - 1]) {
      if (s == y) {
        flag_y = true;
      }
    }
  }

  if (flag_x && flag_y) {
    Yes();
  } else {
    No();
  }

  return 0;
}
