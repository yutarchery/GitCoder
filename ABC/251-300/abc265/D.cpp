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
ll p, q, r, a[int(2e5 + 5)], sum[int(2e5 + 5)];

int x, y, z;

bool solve(int idx) {
  int ng = idx;
  x = 0;
  while (ng - x > 1) {
    int mid = (x + ng) / 2;

    if (sum[idx] - sum[mid] < p + q + r) {
      ng = mid;
    } else {
      x = mid;
    }
  }
  if (sum[idx] - sum[x] != p + q + r) {
    return false;
  }

  y = x, ng = idx;
  while (ng - y > 1) {
    int mid = (y + ng) / 2;

    if (sum[idx] - sum[mid] < q + r) {
      ng = mid;
    } else {
      y = mid;
    }
  }
  if (sum[idx] - sum[y] != q + r) {
    return false;
  }

  z = y, ng = idx;
  while (ng - z > 1) {
    int mid = (z + ng) / 2;
    if (sum[idx] - sum[mid] < r) {
      ng = mid;
    } else {
      z = mid;
    }
  }

  if (sum[idx] - sum[z] != r) {
    return false;
  } else {
    return true;
  }
}

int main() {
  cin >> n >> p >> q >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }

  for (int i = 1; i <= n; i++) {
    if (sum[i] < p + q + r) {
      continue;
    }

    if (solve(i)) {
      Yes();
      return 0;
    }
  }
  No();

  return 0;
}
