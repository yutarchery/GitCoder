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
ll ans, h[int(2e5 + 5)];

void solve(int idx) {
  while (ans % 3 != 0) {
    if (h[idx] <= 0) {
      break;
    }
    if (ans % 3 == 1) {
      ans++;
      h[idx]--;
      continue;
    }
    if (ans % 3 == 2) {
      ans++;
      h[idx] -= min(ll(3), h[idx]);
      continue;
    }
  }

  if (h[idx] <= 0) {
    return;
  }
  ans += (h[idx] / 5) * 3;
  h[idx] %= 5;
  if (h[idx] == 1) {
    ans++;
  } else if (h[idx] == 2) {
    ans += 2;
  } else if (h[idx] > 0) {
    ans += 3;
  }
  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    solve(i);
  }
  cout << ans << endl;

  return 0;
}
