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
ll a, b;
char s[int(1e6 + 5)];

ll cnt_l = 0, cnt_r = 0;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> a >> b;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> s[i];

    if (s[i] == '(') {
      cnt_l++;
    } else {
      if (cnt_l > 0) {
        cnt_l--;
      } else {
        cnt_r++;
      }
    }
  }

  ll ans = (abs(cnt_l - cnt_r) / 2) * b +
           ((min(cnt_l, cnt_r) + 1) / 2) * min(a, 2 * b);
  cout << ans << '\n';

  return 0;
}
