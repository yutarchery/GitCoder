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

int main() {
  int n;
  double x1, x2, y1, y2, r, a[int(2e5 + 5)], b[int(2e5 + 5)];

  cin >> n;
  cin >> x1 >> y1 >> x2 >> y2;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  double theta = atan2(y1 - y2, x2 - x1);

  if (y1 - y2 == 0) {
    r = (x2 - x1) / (2 * cos(theta));
  } else {
    r = (y1 - y2) / (2 * sin(theta));
  }

  double cos_theta = cos(theta), sin_theta = sin(theta);
  double x_dash = x1 + r * cos_theta, y_dash = y1 - r * sin_theta;

  for (int i = 0; i < n; i++) {
    double c = (a[i] - x_dash) * cos_theta - (b[i] - y_dash) * sin_theta;
    double d = (a[i] - x_dash) * sin_theta + (b[i] - y_dash) * cos_theta;
    cout << setprecision(32) << c << " " << d << endl;
  }

  return 0;
}