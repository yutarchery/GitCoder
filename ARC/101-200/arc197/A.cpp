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

int h, w;
char s[int(4e5 + 5)];

int top[int(4e5 + 5)], bottom[int(4e5 + 5)];

ll solve() {
  cin >> h >> w;

  int rest_d = h - 1, rest_r = w - 1;
  for (int i = 1; i <= h + w - 2; i++) {
    cin >> s[i];

    if (s[i] == 'D') {
      rest_d--;
    } else if (s[i] == 'R') {
      rest_r--;
    }
  }

  fill(top + 1, top + w + 1, h + 1);
  int now_i = 1, now_j = 1, cnt_r = 0;
  for (int i = 1; i <= h + w - 2; i++) {
    top[now_j] = min(top[now_j], now_i);
    if (s[i] == 'D') {
      now_i++;
    } else if (s[i] == 'R') {
      now_j++;
    } else {
      if (cnt_r < rest_r) {
        now_j++;
        cnt_r++;
      } else {
        now_i++;
      }
    }
    top[now_j] = min(top[now_j], now_i);
  }

  fill(bottom + 1, bottom + w + 1, 0);
  now_i = 1, now_j = 1;
  int cnt_d = 0;
  for (int i = 1; i <= h + w - 2; i++) {
    bottom[now_j] = max(bottom[now_j], now_i);
    if (s[i] == 'D') {
      now_i++;
    } else if (s[i] == 'R') {
      now_j++;
    } else {
      if (cnt_d < rest_d) {
        now_i++;
        cnt_d++;
      } else {
        now_j++;
      }
    }
    bottom[now_j] = max(bottom[now_j], now_i);
  }

  ll ans = 0;
  for (int i = 1; i <= w; i++) {
    ans += ll(bottom[i] - top[i] + 1);
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
