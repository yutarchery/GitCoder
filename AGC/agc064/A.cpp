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

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> ans;

  for (int i = 1; i <= n; i++) {
    ans.emplace_back(n);
    if (i == n) {
      ans.emplace_back(n - 2);
    } else {
      ans.emplace_back(n - 1);
    }
  }

  for (int i = n - 2; i >= 1; i--) {
    int rest = i;
    if (i == n - 2) {
      rest--;
    }

    vector<int> tmp;
    for (int j = 0; j < ans.size(); j++) {
      if (ans[j] == 0) {
        continue;
      }

      if (rest > 0 && ((ans[j] == i + 1 && ans[j + 1] == i + 2) ||
                       (ans[j] == i + 2 && ans[j + 1] == i + 1))) {
        tmp.emplace_back(ans[j]);
        ans[j] = 0;
        tmp.emplace_back(i);
        rest--;
        tmp.emplace_back(ans[j + 1]);
        ans[j + 1] = 0;
      }

      if (ans[j] > 0) {
        tmp.emplace_back(ans[j]);
      }
    }

    ans = tmp;
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }

  return 0;
}
