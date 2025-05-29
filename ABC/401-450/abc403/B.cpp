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

string s, t;

int main() {
  cin >> s;
  cin >> t;

  for (int i = 0; i < s.length() - t.length() + 1; i++) {
    bool flag = true;
    for (int j = 0; j < t.length(); j++) {
      if (s[i + j] != t[j] && s[i + j] != '?') {
        flag = false;
      }
    }
    if (flag) {
      Yes();
      return 0;
    }
  }
  No();

  return 0;
}
