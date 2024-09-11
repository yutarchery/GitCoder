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
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

string s, t, u, v;

int main() {
  cin >> s;
  bool point = false;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '.') {
      point = true;
    } else if (point) {
      u += s[i];
    } else {
      t += s[i];
    }
  }

  bool out = true;
  for (int i = u.length() - 1; i >= 0; i--) {
    if (u[i] == '0' && out) {
      continue;
    } else {
      out = false;
      v = u[i] + v;
    }
  }

  if (v.empty()) {
    cout << t << endl;
  } else {
    cout << t << "." << v << endl;
  }

  return 0;
}
