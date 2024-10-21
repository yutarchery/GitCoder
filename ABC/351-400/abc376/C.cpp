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

int n, a[int(2e5 + 5)], b[int(2e5 + 5)], c[int(2e5 + 5)];

bool solve(int num) {
  for (int i = 1; i <= n - 1; i++) {
    c[i] = b[i];
  }
  c[n] = num;
  sort(c + 1, c + n + 1);

  for (int i = 1; i <= n; i++) {
    if (a[i] > c[i]) {
      return false;
    }
  }

  return true;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n - 1; i++) {
    cin >> b[i];
  }

  if (!solve(int(1e9 + 5))) {
    cout << -1 << endl;
    return 0;
  }

  int l = 0, r = int(1e9 + 5);
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (solve(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << endl;

  return 0;
}
