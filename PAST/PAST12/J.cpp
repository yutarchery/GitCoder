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

double h, w, d, s, delta;

double calc_width(double y) {
  double x_ng = 0, x_ok = w / 2;

  while (x_ok - x_ng > 1e-10) {
    double x_mid = (x_ng + x_ok) / 2;

    if ((x_mid - w / 2) * (x_mid - w / 2) + (y - h / 2) * (y - h / 2) <=
        d * d) {
      x_ok = x_mid;
    } else {
      x_ng = x_mid;
    }
  }

  return (w / 2 - x_ok) * 2;
}

int main() {
  cin >> h >> w >> d;
  delta = min(0.1, h / 1e6);

  for (double y = 0; y < h; y += delta) {
    s += calc_width(y) * delta;
  }

  cout << fixed << setprecision(10) << s / (h * w) << endl;

  return 0;
}
