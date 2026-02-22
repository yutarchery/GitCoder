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

int n, a[int(2e5 + 5)];

ll ans[int(3e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans[0]++;
    ans[a[i]]--;
  }

  for (int i = 1; i <= int(2e5 + 5); i++) {
    ans[i] += ans[i - 1];
  }

  for (int i = 0; i <= int(3e5); i++) {
    ans[i + 1] += ans[i] / 10;
    ans[i] %= 10;
  }

  bool flag = false;
  for (int i = int(3e5); i >= 0; i--) {
    if (!flag && ans[i] == 0) {
      continue;
    } else if (!flag) {
      flag = true;
    }
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
