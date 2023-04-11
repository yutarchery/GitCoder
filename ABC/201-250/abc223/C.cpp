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

int n;
double a[int(1e5 + 5)], b[int(1e5 + 5)];
double total = 0;

bool calc_time(double left_length) {
  double left_time = 0, right_time = 0;

  double left_rest = left_length;
  for (int i = 0; i < n; i++) {
    if (left_rest >= a[i]) {
      left_time += a[i] / b[i];
      left_rest -= a[i];
    } else if (left_rest <= 0) {
      right_time += a[i] / b[i];
    } else {
      left_time += left_rest / b[i];
      right_time += (a[i] - left_rest) / b[i];
      left_rest = 0;
    }
  }

  return left_time <= right_time;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    total += a[i];
  }

  double l = 0, r = total;
  while (r - l > 1e-6) {
    double mid = (l + r) / 2;

    if (calc_time(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << std::setprecision(16) << l << endl;
  return 0;
}