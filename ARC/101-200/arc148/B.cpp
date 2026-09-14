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
char s[5005];

int cnt_p[5005];
string ans = "", tmp = "";

string solve(int start, int end) {
  string res = "";

  for (int i = 1; i < start; i++) {
    res += s[i];
  }
  for (int i = end; i >= start; i--) {
    if (s[i] == 'p') {
      res += 'd';
    } else {
      res += 'p';
    }
  }
  for (int i = end + 1; i <= n; i++) {
    res += s[i];
  }

  return res;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    ans += s[i];

    cnt_p[i] = cnt_p[i - 1];
    if (s[i] == 'p' && s[i] != s[i - 1]) {
      cnt_p[i]++;
    }
  }

  tmp = "";
  for (int i = 1; i <= n; i++) {
    if (cnt_p[i] <= 1) {
      tmp += 'd';
    } else {
      tmp += s[i];
    }
  }
  ans = min(ans, tmp);

  for (int i = 1; i <= n; i++) {
    if (cnt_p[i - 1] == 0 && cnt_p[i] == 1) {
      for (int j = i; j <= n; j++) {
        ans = min(ans, solve(i, j));
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
