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
ll a[int(1e6 + 5)], sum[int(1e6 + 5)];

int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    a[i] = 1;
    sum[i] = i + 1;
  }
  a[k] = k;
  sum[k] = sum[k - 1] + a[k];

  for (int i = k + 1; i <= n; i++) {
    a[i] = (sum[i - 1] - sum[i - 1 - k]) % ll(1e9);
    if (a[i] < 0) {
      a[i] += ll(1e9);
    }

    sum[i] = sum[i - 1] + a[i];
    sum[i] %= ll(1e9);
  }
  cout << a[n] << endl;

  return 0;
}
