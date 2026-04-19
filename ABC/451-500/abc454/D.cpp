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

string transform(string s) {
  vector<char> ans;
  for (int i = 0; i < s.length(); i++) {
    ans.push_back(s[i]);

    while (ans.size() >= 4) {
      string now = "";
      for (int j = ans.size() - 4; j <= ans.size() - 1; j++) {
        now += ans[j];
      }

      if (now == "(xx)") {
        for (int j = 0; j < 4; j++) {
          ans.pop_back();
        }
        ans.emplace_back('x');
        ans.emplace_back('x');
      } else {
        break;
      }
    }
  }

  string res = "";
  for (int i = 0; i < ans.size(); i++) {
    res += ans[i];
  }

  return res;
}

void solve() {
  string a, b;
  cin >> a;
  cin >> b;

  if (transform(a) == transform(b)) {
    Yes();
  } else {
    No();
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
