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

int h, w;
ll a[55][55];

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }

  for (int i1 = 1; i1 <= h; i1++) {
    for (int i2 = i1 + 1; i2 <= h; i2++) {
      for (int j1 = 1; j1 <= w; j1++) {
        for (int j2 = j1 + 1; j2 <= w; j2++) {
          if (a[i1][j1] + a[i2][j2] <= a[i2][j1] + a[i1][j2]) {
            continue;
          } else {
            No();
            return 0;
          }
        }
      }
    }
  }
  Yes();

  return 0;
}
