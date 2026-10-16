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
ll y, x[20];
string s[105];

int ans = 0, cnt[26];

void solve(int idx) {
  fill(cnt, cnt + 26, 0);
  ll now_x = 0;
  for (int i = 0; i < n; i++) {
    if (idx % 2 == 1) {
      now_x += x[i];
      for (int j = 0; j < s[i].length(); j++) {
        cnt[s[i][j] - 'a']++;
      }
    }

    idx /= 2;
  }

  if (now_x <= y) {
    int res = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] > 0) {
        res++;
      }
    }
    ans = max(res, ans);
  }
  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> y;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> x[i];
  }
  for (int i = 0; i < (1 << n); i++) {
    solve(i);
  }
  cout << ans << '\n';

  return 0;
}
