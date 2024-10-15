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

int n, order[10];
double s, t, a[10], b[10], c[10], d[10], ans = 1e16;

double calc_dist(double x1, double y1, double x2, double y2) {
  double dist2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  return sqrt(dist2);
}

double solve() {
  double now = 0;
  for (int i = 1; i <= n; i++) {
    now +=
        calc_dist(c[order[i - 1]], d[order[i - 1]], a[order[i]], b[order[i]]) /
        s;
    now += calc_dist(a[order[i]], b[order[i]], c[order[i]], d[order[i]]) / t;
  }
  return now;
}

int main() {
  cin >> n >> s >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    order[i] = i;
  }

  do {
    for (int i = 0; i < (1 << n); i++) {
      int rest = i;
      for (int j = 1; j <= n; j++) {
        if (rest % 2 == 1) {
          swap(a[j], c[j]);
          swap(b[j], d[j]);
        }
        rest /= 2;
      }

      ans = min(ans, solve());

      rest = i;
      for (int j = 1; j <= n; j++) {
        if (rest % 2 == 1) {
          swap(a[j], c[j]);
          swap(b[j], d[j]);
        }
        rest /= 2;
      }
    }
  } while (next_permutation(order + 1, order + n + 1));

  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}
