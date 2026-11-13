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

int n;
ll x[int(4e5 + 5)], y[int(4e5 + 5)];
int order[int(8e5 + 5)];

int get_area(ll x, ll y) {
  if (x > 0 && y >= 0) {
    return 1;
  } else if (x <= 0 && y > 0) {
    return 2;
  } else if (x < 0 && y <= 0) {
    return 3;
  } else {
    return 4;
  }
}

bool my_comp(const int &i, const int &j) {
  int i_area = get_area(x[i], y[i]), j_area = get_area(x[j], y[j]);
  if (i_area != j_area) {
    return i_area < j_area;
  }

  if (i_area == 1 || i_area == 3) {
    return abs(y[i]) * abs(x[j]) < abs(y[j]) * abs(x[i]);
  } else {
    return abs(y[j]) * abs(x[i]) < abs(y[i]) * abs(x[j]);
  }
}

int solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    x[i] = -1 * x[i - n];
    y[i] = -1 * y[i - n];
  }

  for (int i = 1; i <= 2 * n; i++) {
    order[i] = i;
  }
  sort(order + 1, order + 2 * n + 1, my_comp);

  for (int i = 2 * n + 1; i <= 4 * n; i++) {
    order[i] = order[i - 2 * n];
  }

  int r = 0, ans = 0, cnt = 0;
  for (int i = 1; i <= 2 * n; i++) {
    if (order[i] > n) {
      continue;
    }

    r = max(r, i);
    while (order[r] != order[i] + n) {
      if (order[r] <= n) {
        cnt++;
      }
      r++;
    }

    ans = max(ans, max(n - cnt, cnt));
    cnt--;
  }

  return ans;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }

  return 0;
}
