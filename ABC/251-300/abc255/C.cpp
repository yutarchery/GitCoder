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

ll x, a, d, n;

int main() {
  cin >> x >> a >> d >> n;

  if (d == 0) {
    cout << abs(x - a) << endl;
    return 0;
  } else if (d < 0) {
    if (a <= x) {
      cout << abs(x - a) << endl;
      return 0;
    } else if (x <= a + (n - 1) * d) {
      cout << abs(x - (a + (n - 1) * d)) << endl;
      return 0;
    } else {
      ll x_p = x, x_m = x;
      while ((x_p - a) % d != 0) {
        x_p++;
      }
      while ((x_m - a) % d != 0) {
        x_m--;
      }

      cout << min(abs(x_p - x), abs(x_m - x)) << endl;
      return 0;
    }
  } else {
    if (x <= a) {
      cout << abs(x - a) << endl;
      return 0;
    } else if (a + (n - 1) * d <= x) {
      cout << abs(x - (a + (n - 1) * d)) << endl;
      return 0;
    } else {
      ll x_p = x, x_m = x;
      while ((x_p - a) % d != 0) {
        x_p++;
      }
      while ((x_m - a) % d != 0) {
        x_m--;
      }

      cout << min(abs(x_p - x), abs(x_m - x)) << endl;
      return 0;
    }
  }

  return 0;
}
