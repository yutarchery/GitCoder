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

int n, m, a[int(2e5 + 5)], b[int(2e5 + 5)];

bool solve(int num) {
  int cnt_a = 0, cnt_b = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] <= num) {
      cnt_a++;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (num <= b[i]) {
      cnt_b++;
    }
  }

  return cnt_a >= cnt_b;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
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
