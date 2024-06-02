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

int ans_l[int(2e5 + 5)], ans_r[int(2e5 + 5)];
int dp_l[int(2e5 + 5)], dp_r[int(2e5 + 5)];

void prepare() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  fill(ans_l + 1, ans_l + n + 2, 0);
  fill(ans_r + 1, ans_r + n + 2, 0);
  dp_l[0] = 0;
  fill(dp_l + 1, dp_l + n + 2, int(2e9));
  dp_r[0] = int(2e9);
  fill(dp_r + 1, dp_r + n + 2, 0);

  return;
}

void solve() {
  prepare();

  for (int i = 1; i <= n; i++) {
    int l = 0, r = n + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (dp_l[mid] < a[i]) {
        l = mid;
      } else {
        r = mid;
      }
    }
    ans_l[i] = r;
    dp_l[r] = a[i];
  }

  for (int i = n; i >= 1; i--) {
    int l = 0, r = n + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (dp_r[mid] > a[i]) {
        l = mid;
      } else {
        r = mid;
      }
    }
    ans_r[i] = r;
    dp_r[r] = a[i];
  }

  int m = 0;
  for (int i = 1; i <= n; i++) {
    m = max(m, ans_l[i] + ans_r[i]);
  }

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (m == ans_l[i] + ans_r[i]) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;
  cout << ans[0];
  for (int i = 1; i < ans.size(); i++) {
    cout << " " << ans[i];
  }
  cout << endl;

  return;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }

  return 0;
}
