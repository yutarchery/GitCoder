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
ll s, a[int(4e5 + 5)], sum[int(4e5 + 5)];

int main() {
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  for (int i = 1; i <= n * 2; i++) {
    sum[i] = sum[i - 1] + a[i];
  }

  s %= sum[n];
  if (s == 0) {
    Yes();
    return 0;
  }

  for (int i = 1; i <= n * 2; i++) {
    int l = i, r = n * 2;

    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (sum[mid] - sum[i - 1] <= s) {
        l = mid;
      } else {
        r = mid;
      }
    }

    if (sum[l] - sum[i - 1] == s) {
      Yes();
      return 0;
    }
  }
  No();

  return 0;
}
