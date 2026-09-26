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
char s[int(2e5 + 5)];

int cnt_a[int(2e5 + 5)], cnt_c[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i <= n; i++) {
    if (s[i] == 'A') {
      cnt_a[i] = cnt_a[i - 1] + 1;
    } else {
      cnt_a[i] = 0;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (s[i] == 'C') {
      cnt_c[i] = cnt_c[i + 1] + 1;
    } else {
      cnt_c[i] = 0;
    }
  }

  multiset<int> mst;
  for (int i = 1; i <= n; i++) {
    if (s[i] != 'R') {
      continue;
    }

    if (cnt_a[i - 1] > 0 && cnt_c[i + 1] > 0) {
      mst.insert(min(cnt_a[i - 1], cnt_c[i + 1]));
    }
  }

  int ans = 0;
  while (!mst.empty()) {
    ans++;

    if (ans % 2 == 1) {
      auto iter = mst.end();
      iter--;

      int now = *iter;
      mst.erase(iter);
      if (now - 1 >= 1) {
        mst.insert(now - 1);
      }
    } else {
      auto iter = mst.begin();
      mst.erase(iter);
    }
  }
  cout << ans << '\n';

  return 0;
}
