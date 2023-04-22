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

int h[3], w[3], ans = 0;

int a[3][3];

int main() {
  for (int i = 0; i < 3; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < 3; i++) {
    cin >> w[i];
  }

  for (int i = 1; i <= h[0] - 2; i++) {
    a[0][0] = i;

    for (int j = 1; i + j <= h[0] - 1; j++) {
      a[0][1] = j;
      a[0][2] = h[0] - (i + j);
      for (int k = 1; k <= h[1] - 2; k++) {
        a[1][0] = k;
        for (int l = 1; k + l <= h[1] - 1; l++) {
          a[1][1] = l;
          a[1][2] = h[1] - (k + l);

          bool flag = true;
          for (int idx = 0; idx < 3; idx++) {
            a[2][idx] = w[idx] - (a[0][idx] + a[1][idx]);
            if (a[2][idx] <= 0) {
              flag = false;
            }
          }

          if (h[2] != a[2][0] + a[2][1] + a[2][2]) {
            flag = false;
          }

          if (flag) {
            ans++;
          }
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}