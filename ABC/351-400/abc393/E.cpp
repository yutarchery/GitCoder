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

int n, k, a[int(12e5 + 5)];
int cnt[int(1e6 + 5)], sum[int(1e6 + 5)], ans[int(1e6 + 5)];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  for (int i = 1; i <= int(1e6); i++) {
    for (int j = i; j <= int(1e6); j += i) {
      sum[i] += cnt[j];
    }
  }

  for (int i = 1; i <= int(1e6); i++) {
    if (sum[i] < k) {
      continue;
    }

    for (int j = i; j <= int(1e6); j += i) {
      ans[j] = i;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[a[i]] << '\n';
  }

  return 0;
}
