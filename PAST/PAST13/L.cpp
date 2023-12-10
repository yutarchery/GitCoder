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

bool range_compare(Pii &a, Pii &b) {
  if (a.second == b.second) {
    return a.first < b.first;
  } else {
    return a.second > b.second;
  }
}

int n;
Pii range[int(2e5 + 5)];

int dp[int(2e5 + 5)];

void update_dp(int value) {
  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;

    if (dp[mid] <= value) {
      l = mid;
    } else {
      r = mid;
    }
  }

  dp[r] = value;
  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> range[i].first >> range[i].second;
  }
  sort(range + 1, range + n + 1, range_compare);

  fill(dp + 1, dp + n + 2, int(1e9 + 5));

  for (int i = 1; i <= n; i++) {
    update_dp(range[i].first);
  }

  for (int i = 1; i <= n; i++) {
    if (dp[i + 1] == int(1e9 + 5)) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
