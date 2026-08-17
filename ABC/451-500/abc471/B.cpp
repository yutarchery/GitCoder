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
string s[105], t[105];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    for (int j = 0; j < s[i].length(); j++) {
      if ('a' <= s[i][j] && s[i][j] <= 'z') {
        t[i] += s[i][j];
      } else {
        t[i] += char(s[i][j] - 'A' + 'a');
      }
    }
  }
  sort(t + 1, t + n + 1);

  int ans = 0, cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (t[i] == t[i - 1]) {
      cnt++;
    } else {
      ans = max(ans, cnt);
      cnt = 1;
    }
  }
  ans = max(ans, cnt);
  cout << ans << '\n';

  return 0;
}
