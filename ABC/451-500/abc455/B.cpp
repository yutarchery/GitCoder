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
char s[15][15];

bool solve(int h1, int h2, int w1, int w2) {
  for (int i = h1; i <= h2; i++) {
    for (int j = w1; j <= w2; j++) {
      if (s[i][j] != s[h1 + h2 - i][w1 + w2 - j]) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
    }
  }

  int ans = 0;
  for (int i1 = 1; i1 <= h; i1++) {
    for (int i2 = i1; i2 <= h; i2++) {
      for (int j1 = 1; j1 <= w; j1++) {
        for (int j2 = j1; j2 <= w; j2++) {
          if (solve(i1, i2, j1, j2)) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
