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
ll m, a[int(2e5 + 5)];

vector<ll> nums[15];

ll calc_digit(ll num) {
  int res = 0;
  while (num > 0) {
    num /= 10;
    res++;
  }
  return res;
}

int search_nums(int idx, ll num) {
  int ng = 0, ok = nums[idx].size();
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    if (nums[idx][mid] < num) {
      ng = mid;
    } else {
      ok = mid;
    }
  }

  return ok;
}

int main() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ll now = a[i] * 10 % m;
    for (int j = 1; j <= 10; j++) {
      nums[j].push_back(now);
      now = (now * 10) % m;
    }
  }

  for (int j = 1; j <= 10; j++) {
    nums[j].push_back(-1);
    nums[j].push_back(m + 1);
    sort(nums[j].begin(), nums[j].end());
  }

  ll ans = 0;

  for (int i = 1; i <= n; i++) {
    int d = calc_digit(a[i]);
    ll rest = (m - a[i] % m) % m;
    ans += search_nums(d, rest + 1) - search_nums(d, rest);
  }
  cout << ans << endl;

  return 0;
}
