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
ll t, a[25], b[25], ans = 0;
ll before[(1 << 21)];

void prepareBefore(int idx) {
  int rest = idx;
  for (int i = 0; i < (n / 2); i++) {
    if (rest % 2 == 1) {
      before[idx] += a[i];
    }
    rest /= 2;
  }
}

void solve(int idx) {
  ll sum = 0;
  for (int i = (n / 2); i < n; i++) {
    if (idx % 2 == 1) {
      sum += b[i - (n / 2)];
    }
    idx /= 2;
  }

  if (sum > t) {
    return;
  }

  int l = 0, r = (1 << (n / 2));
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (sum + before[mid] <= t) {
      l = mid;
    } else {
      r = mid;
    }
  }
  ans = max(ans, sum + before[l]);
  return;
}

int main() {
  cin >> n >> t;
  for (int i = 0; i < (n / 2); i++) {
    cin >> a[i];
  }
  for (int i = 0; i < (1 << (n / 2)); i++) {
    prepareBefore(i);
  }
  sort(before, before + (1 << (n / 2)));

  for (int i = (n / 2); i < n; i++) {
    cin >> b[i - n / 2];
  }
  for (int i = 0; i < (1 << (n - n / 2)); i++) {
    solve(i);
  }
  cout << ans << endl;

  return 0;
}