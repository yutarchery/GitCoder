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

int n, k;
string s;

const char c[4] = {'R', 'S', 'P', 'R'};

string solve(string now, int rest) {
  string t = now;
  if (now.length() % 2 == 1) {
    t += now;
  }

  string res = "";
  if (rest == 1) {
    if (t[0] == t[1]) {
      res += t[0];
    } else {

      for (int j = 0; j < 3; j++) {
        if (t[0] == c[j] && t[1] == c[j + 1]) {
          res += c[j];
        } else if (t[0] == c[j + 1] && t[1] == c[j]) {
          res += c[j];
        }
      }
    }
    return res;
  }

  for (int i = 0; i < t.length(); i += 2) {
    if (t[i] == t[i + 1]) {
      res += t[i];
      continue;
    }

    for (int j = 0; j < 3; j++) {
      if (t[i] == c[j] && t[i + 1] == c[j + 1]) {
        res += c[j];
      } else if (t[i] == c[j + 1] && t[i + 1] == c[j]) {
        res += c[j];
      }
    }
  }

  return solve(res, rest - 1);
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  cin >> s;

  cout << solve(s, k) << '\n';

  return 0;
}
