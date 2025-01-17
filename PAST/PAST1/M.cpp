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

int n, m;
double a[1005], b[1005], c[105], d[105];

bool solve(double num) {
  vector<double> now;
  for (int i = 1; i <= n; i++) {
    now.push_back(b[i] - a[i] * num);
  }
  double m_max = -1e16;
  for (int i = 1; i <= m; i++) {
    m_max = max(m_max, d[i] - c[i] * num);
  }
  now.push_back(m_max);

  sort(now.begin(), now.end(), greater<double>());
  double sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += now[i];
  }

  return sum >= 0;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> c[i] >> d[i];
  }

  double l = 0, r = 1e9;
  while (r - l > 1e-10) {
    double mid = (l + r) / 2;
    if (solve(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << fixed << setprecision(10) << l << endl;

  return 0;
}
