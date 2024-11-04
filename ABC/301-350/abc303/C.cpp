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

int n, m, h, k, x[int(2e5 + 5)], y[int(2e5 + 5)];
string s;
map<Pii, bool> item;

int now_x = 0, now_y = 0;
const char dir[4] = {'R', 'L', 'U', 'D'};
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main() {
  cin >> n >> m >> h >> k;
  cin >> s;
  for (int i = 1; i <= m; i++) {
    cin >> x[i] >> y[i];
    item[{x[i], y[i]}] = true;
  }

  for (int i = 0; i < n; i++) {
    h--;
    for (int j = 0; j < 4; j++) {
      if (s[i] == dir[j]) {
        now_x += dx[j];
        now_y += dy[j];
      }
    }

    if (h < 0) {
      No();
      return 0;
    }

    if (item[{now_x, now_y}] && h < k) {
      item[{now_x, now_y}] = false;
      h = k;
    }
  }

  Yes();
  return 0;
}
