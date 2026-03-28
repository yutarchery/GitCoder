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

string s, t;
vector<char> vs, vt;
vector<int> os, ot;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> s;
  cin >> t;

  int cnt_s = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'A') {
      cnt_s++;
    } else {
      os.push_back(cnt_s);
      cnt_s = 0;
      vs.push_back(s[i]);
    }

    if (i == s.length() - 1) {
      os.push_back(cnt_s);
    }
  }

  int cnt_t = 0;
  for (int i = 0; i < t.length(); i++) {
    if (t[i] == 'A') {
      cnt_t++;
    } else {
      ot.push_back(cnt_t);
      cnt_t = 0;
      vt.push_back(t[i]);
    }

    if (i == t.length() - 1) {
      ot.push_back(cnt_t);
    }
  }

  if (vs != vt) {
    cout << -1 << endl;
  } else {
    int ans = 0;
    for (int i = 0; i < os.size(); i++) {
      ans += abs(os[i] - ot[i]);
    }
    cout << ans << endl;
  }

  return 0;
}
