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

int n, k, a[105], b[105], m;
bool is_max[105];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    m = max(m, a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (m == a[i]) {
      is_max[i] = true;
    }
  }

  for (int i = 1; i <= k; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= k; i++) {
    if (is_max[b[i]]) {
      Yes();
      return 0;
    }
  }
  No();

  return 0;
}
