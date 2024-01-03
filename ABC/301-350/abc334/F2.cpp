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

int n, k;
ll sx, sy, x[int(2e5 + 5)], y[int(2e5 + 5)];
double ans = 0;
double dp[int(2e5 + 5)];

double dist(ll x0, ll y0, ll x1, ll y1) {
  return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

priority_queue<pair<double, int>, vector<pair<double, int>>,
               greater<pair<double, int>>>
    que;

double search_min(int idx) {
  while (que.top().second < idx - k) {
    que.pop();
  }
  return que.top().first;
}

int main() {
  cin >> n >> k;
  cin >> sx >> sy;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }

  ans += dist(sx, sy, x[1], y[1]);
  for (int i = 2; i <= n; i++) {
    ans += dist(x[i - 1], y[i - 1], x[i], y[i]);
  }
  ans += dist(x[n], y[n], sx, sy);

  que.push({0, 1});
  for (int i = 2; i <= n; i++) {
    double direct = dist(x[i - 1], y[i - 1], x[i], y[i]);
    double via_home =
        dist(x[i - 1], y[i - 1], sx, sy) + dist(sx, sy, x[i], y[i]);

    double min_dist = search_min(i);
    dp[i] = min_dist + via_home - direct;
    que.push({dp[i], i});
  }

  double min_penalty = 1e18;
  for (int i = max(1, n - k + 1); i <= n; i++) {
    min_penalty = min(min_penalty, dp[i]);
  }
  ans += min_penalty;
  cout << fixed << setprecision(32) << ans << endl;

  return 0;
}
