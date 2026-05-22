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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int h, w, ans[55][55];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {

      if (h == 1 && w == 1) {
        ans[i][j] = 2;
      } else if (h == 1 || w == 1) {
        ans[i][j] = 3;
      } else {
        ans[i][j] = 4;
      }

      if (i == 1 || i == h) {
        ans[i][j]--;
      }
      if (j == 1 || j == w) {
        ans[i][j]--;
      }

      cout << ans[i][j] << (j == w ? '\n' : ' ');
    }
  }

  return 0;
}
