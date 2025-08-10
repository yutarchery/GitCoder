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
ll x[2005], y[2005];

vector<Pll> slopes, centers;

ll my_gcd(ll a, ll b) {
  if (a < b) {
    return my_gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  if (a % b == 0) {
    return b;
  }
  return my_gcd(b, a % b);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    x[i] *= 2;
    y[i] *= 2;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ll a = x[j] - x[i], b = y[j] - y[i];
      ll g = my_gcd(abs(a), abs(b));
      ll ga = a / g, gb = b / g;

      if (ga < 0) {
        ga *= -1;
        gb *= -1;
      }
      if (ga == 0 || gb == 0) {
        ga = abs(ga);
        gb = abs(gb);
      }

      slopes.push_back({ga, gb});
      centers.push_back({(x[i] + x[j]) / 2, (y[i] + y[j]) / 2});
    }
  }
  sort(slopes.begin(), slopes.end());
  sort(centers.begin(), centers.end());

  ll ans = 0, cnt = 1;
  for (int i = 1; i < slopes.size(); i++) {
    if (slopes[i] == slopes[i - 1]) {
      cnt++;
    } else {
      ans += cnt * (cnt - 1) / 2;
      cnt = 1;
    }
  }
  ans += cnt * (cnt - 1) / 2;

  cnt = 1;
  for (int i = 1; i < centers.size(); i++) {
    if (centers[i] == centers[i - 1]) {
      cnt++;
    } else {
      ans -= cnt * (cnt - 1) / 2;
      cnt = 1;
    }
  }
  ans -= cnt * (cnt - 1) / 2;

  cout << ans << endl;

  return 0;
}
