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

struct SegmentTree {
  int n;
  vector<double> node;

private:
  double INF = 1e18;

public:
  void prepare() {
    int res = 1;
    while (res < n) {
      res *= 2;
    }
    n = res;
    node.resize(2 * res - 1);
    fill(node.begin(), node.end(), INF);
    return;
  }

  void insert(int x, double d) {
    x += n - 1;
    node[x] = min(node[x], d);

    while (x > 0) {
      x = (x - 1) / 2;
      node[x] = min(node[2 * x + 1], node[2 * x + 2]);
    }
    return;
  }

  double getmin(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    if (r <= a || b <= l) {
      return INF;
    }
    if (a <= l && r <= b) {
      return node[k];
    }
    return min(getmin(a, b, 2 * k + 1, l, (l + r) / 2),
               getmin(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

int n, k;
ll sx, sy, x[int(2e5 + 5)], y[int(2e5 + 5)];
double ans = 0;

double dist(ll x0, ll y0, ll x1, ll y1) {
  return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

int main() {
  cin >> n >> k;
  cin >> sx >> sy;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }

  SegmentTree tree;
  tree.n = n + 1;
  tree.prepare();

  ans += dist(sx, sy, x[1], y[1]);
  for (int i = 2; i <= n; i++) {
    ans += dist(x[i - 1], y[i - 1], x[i], y[i]);
  }
  ans += dist(x[n], y[n], sx, sy);

  tree.insert(1, 0);
  for (int i = 2; i <= n; i++) {
    double direct = dist(x[i - 1], y[i - 1], x[i], y[i]);
    double via_home =
        dist(x[i - 1], y[i - 1], sx, sy) + dist(sx, sy, x[i], y[i]);

    double min_dist = tree.getmin(max(1, i - k), i);
    tree.insert(i, min_dist + via_home - direct);
  }

  ans += tree.getmin(max(1, n - k + 1), n + 1);
  cout << fixed << setprecision(32) << ans << endl;

  return 0;
}
