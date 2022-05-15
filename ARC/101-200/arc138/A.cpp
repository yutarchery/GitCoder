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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, k, a[int(4e5 + 5)];
vector<Pii> after;

int ans = mod;

int makeAfter() {
  after.push_back({0, 0});
  after.push_back({a[k], k});
  int now = a[k];
  for (int i = k + 1; i < n; i++) {
    if (now < a[i]) {
      after.push_back({a[i], i});
      now = a[i];
    }
  }
  return now;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int afterMax = makeAfter();

  for (int i = 0; i < k; i++) {
    if (a[i] >= afterMax) {
      continue;
    }

    int l = 0, r = after.size();
    while (r - l > 1) {
      int mid = (l + r) / 2;

      if (a[i] < after[mid].fi) {
        r = mid;
      } else {
        l = mid;
      }
    }
    ans = min(ans, (after[r].se - i));
  }

  if (ans == mod) {
    ans = -1;
  }

  cout << ans << endl;

  return 0;
}