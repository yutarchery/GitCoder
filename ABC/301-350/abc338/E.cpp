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

int n, a[int(2e5 + 5)], b[int(2e5 + 5)];
Pii p[int(2e5 + 5)], level[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    if (a[i] > b[i]) {
      swap(a[i], b[i]);
    }

    p[i] = {a[i], b[i]};
  }
  sort(p + 1, p + n + 1);
  level[0].second = 1e9;

  for (int i = 1; i <= n; i++) {
    int l = 0, r = n + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (p[i].first < level[mid].second) {
        l = mid;
      } else {
        r = mid;
      }
    }

    if (level[l].second < p[i].second) {
      Yes();
      return 0;
    } else {
      level[r] = p[i];
    }
  }
  No();

  return 0;
}
