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

int h1, w1, h2, w2, a[15][15], b[15][15];
bool now_h[15], now_w[15];
int h_idx[15], w_idx[15];

int main() {
  cin >> h1 >> w1;
  for (int i = 1; i <= h1; i++) {
    for (int j = 1; j <= w1; j++) {
      cin >> a[i][j];
    }
  }
  cin >> h2 >> w2;
  for (int i = 1; i <= h2; i++) {
    for (int j = 1; j <= w2; j++) {
      cin >> b[i][j];
    }
  }

  for (int k = 0; k < (1 << (h1 + w1)); k++) {
    int rest = k, h = 0, w = 0;

    for (int i = 1; i <= h1; i++) {
      if (rest % 2 != 0) {
        now_h[i] = true;
        h++;
        h_idx[h] = i;
      }
      rest /= 2;
    }
    for (int j = 1; j <= w1; j++) {
      if (rest % 2 != 0) {
        now_w[j] = true;
        w++;
        w_idx[w] = j;
      }
      rest /= 2;
    }

    if (h == h2 && w == w2) {
      bool flag = true;
      for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
          if (a[h_idx[i]][w_idx[j]] != b[i][j]) {
            flag = false;
          }
        }
      }

      if (flag) {
        Yes();
        return 0;
      }
    } else {
      continue;
    }
  }

  No();
  return 0;
}
