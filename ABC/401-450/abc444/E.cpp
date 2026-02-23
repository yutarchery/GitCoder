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
ll d, a[int(4e5 + 5)];

set<ll> now;
ll ans = 0;
int l_idx = 1;

void insert(int idx) {
  auto iter = now.lower_bound(a[idx]);

  if (*iter == a[idx]) {
    while (a[l_idx] != a[idx]) {
      now.erase(a[l_idx]);
      l_idx++;
    }
    l_idx++;
    ans += now.size() - 2;

    return;
  }

  auto before_iter = iter, after_iter = iter;
  before_iter--;

  while (!(abs(*before_iter - a[idx]) >= d && abs(*after_iter - a[idx]) >= d)) {
    now.erase(a[l_idx]);
    l_idx++;

    before_iter = now.lower_bound(a[idx]);
    before_iter--;
    after_iter = now.lower_bound(a[idx]);
  }

  now.insert(a[idx]);

  ans += now.size() - 2;
  return;
}

int main() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  now.insert(ll(-1e16));
  now.insert(ll(1e16));

  for (int i = 1; i <= n; i++) {
    insert(i);
  }
  cout << ans << endl;

  return 0;
}
