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

string ans = "";

string solve(string s, int rest) {
  if (rest == 0) {
    return s;
  }

  vector<char> v;
  int cnt_a = 0;
  bool flag = false;
  for (int i = 0; i < s.length(); i++) {
    v.emplace_back(s[i]);
    if (s[i] == 'A') {
      cnt_a++;
    }

    if (cnt_a == rest && !flag) {
      flag = true;
      rest -= cnt_a;
      v.emplace_back('C');
    }
  }

  if (!flag) {
    rest -= cnt_a;
    v.emplace_back('C');
  }

  string res = "";
  for (char c : v) {
    res += c;
  }

  return solve(res, rest);
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int x;
  cin >> x;

  string as = "";
  for (int i = 1; i <= 25; i++) {
    as += 'A';
  }

  string ans = solve(as, x);
  for (int i = 0; i < ans.length(); i++) {
    cout << ans[i] << (i == ans.length() - 1 ? '\n' : 'R');
  }

  return 0;
}
