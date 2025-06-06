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
int a[int(2e5 + 5)], b[int(2e5 + 5)];

int idx1[int(2e5 + 5)], idx2[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }

  int now = 1;
  for (int j = 1; j <= m; j++) {
    for (int i = now; i <= n; i++) {
      if (a[i] == b[j]) {
        idx1[j] = i;
        now = i + 1;
        break;
      }

      if (i == n) {
        No();
        return 0;
      }
    }
  }

  now = n;
  for (int j = m; j >= 1; j--) {
    for (int i = now; i >= 1; i--) {
      if (a[i] == b[j]) {
        idx2[j] = i;
        now = i - 1;
        break;
      }

      if (i == 1) {
        No();
        return 0;
      }
    }
  }

  for (int i = 1; i <= m; i++) {
    if (idx1[i] != idx2[i]) {
      Yes();
      return 0;
    }
  }
  No();

  return 0;
}
