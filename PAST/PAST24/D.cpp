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

int h, w;
char s[205][205], ans[55][55];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> h >> w;
  for (int i = 1; i <= 3 * h; i++) {
    for (int j = 1; j <= 3 * w; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      int cnt_0 = 0, cnt_1 = 0;
      for (int k = 1; k <= 3; k++) {
        for (int l = 1; l <= 3; l++) {
          if (s[3 * (i - 1) + k][3 * (j - 1) + l] == '#') {
            cnt_0++;
          } else {
            cnt_1++;
          }
        }
      }

      if (cnt_0 > cnt_1) {
        ans[i][j] = '#';
      } else {
        ans[i][j] = '.';
      }
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }

  return 0;
}
