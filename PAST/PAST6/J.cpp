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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n;
double c, x[int(2e5 + 5)], y[int(2e5 + 5)];

double calc_cost(double p) {
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (p - x[i]) * (p - x[i]);
    ans += (c - y[i]) * (c - y[i]);
  }
  return ans;
}

int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  sort(x + 1, x + n + 1);

  double p_left = x[1], p_right = x[n];
  while (p_right - p_left > 1e-6) {
    double p_l = (p_left * 2 + p_right) / 3;
    double p_r = (p_left + p_right * 2) / 3;
    if (calc_cost(p_l) > calc_cost(p_r)) {
      p_left = p_l;
    } else {
      p_right = p_r;
    }
  }

  cout << setprecision(32) << calc_cost((p_left + p_right) / 2) << endl;

  return 0;
}