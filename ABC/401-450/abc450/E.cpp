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

string x, y;

int l_x, l_y;
ll cnt_x[10005][26], cnt_y[10005][26], lengths[1005], ans[1005][26];

ll solve(int idx, ll rest, char now) {
  if (idx == 1) {
    return cnt_x[rest][now - 'a'];
  }
  if (idx == 2) {
    return cnt_y[rest][now - 'a'];
  }

  if (rest == lengths[idx]) {
    return ans[idx][now - 'a'];
  }

  if (rest <= lengths[idx - 1]) {
    return solve(idx - 1, rest, now);
  } else {
    return solve(idx - 1, lengths[idx - 1], now) +
           solve(idx - 2, rest - lengths[idx - 1], now);
  }
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> x >> y;
  l_x = x.length(), l_y = y.length();
  for (int i = 1; i <= l_x; i++) {
    for (int j = 0; j < 26; j++) {
      cnt_x[i][j] = cnt_x[i - 1][j];
    }
    cnt_x[i][x[i - 1] - 'a']++;
  }
  for (int j = 0; j < 26; j++) {
    ans[1][j] = cnt_x[l_x][j];
  }

  for (int i = 1; i <= l_y; i++) {
    for (int j = 0; j < 26; j++) {
      cnt_y[i][j] = cnt_y[i - 1][j];
    }
    cnt_y[i][y[i - 1] - 'a']++;
  }
  for (int j = 0; j < 26; j++) {
    ans[2][j] = cnt_y[l_y][j];
  }

  int k = 0;
  lengths[1] = l_x, lengths[2] = l_y;
  for (int i = 3; i <= 1000; i++) {
    lengths[i] = lengths[i - 1] + lengths[i - 2];
    for (int j = 0; j < 26; j++) {
      ans[i][j] = ans[i - 1][j] + ans[i - 2][j];
    }

    if (lengths[i] > 1e18) {
      k = i;
      break;
    }
  }

  int q;
  cin >> q;
  while (q--) {
    ll l, r;
    char c;
    cin >> l >> r >> c;
    cout << solve(k, r, c) - solve(k, l - 1, c) << '\n';
  }

  return 0;
}
