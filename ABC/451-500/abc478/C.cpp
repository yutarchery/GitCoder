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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, k, a[int(2e5 + 5)];

int mins[int(2e5 + 5)], maxs[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  maxs[1] = a[1];
  for (int i = 1; i <= n; i++) {
    maxs[i] = max(maxs[i - 1], a[i]);
  }

  mins[n] = a[n];
  for (int i = n - 1; i >= 1; i--) {
    mins[i] = min(mins[i + 1], a[i]);
  }

  int start = n, end = 0;
  for (int i = 1; i <= n; i++) {
    if (maxs[i] > mins[i]) {
      start = min(start, i);
      end = max(end, i);
    }
  }

  (end - start < k) ? Yes() : No();

  return 0;
}
