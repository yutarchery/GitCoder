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

int n, m;
string s, t;
bool prefix = true, suffix = true;

int main() {
  cin >> n >> m;
  cin >> s;
  cin >> t;

  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      prefix = false;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i + (m - n)]) {
      suffix = false;
    }
  }

  if (prefix && suffix) {
    cout << 0 << endl;
  } else if (prefix && !suffix) {
    cout << 1 << endl;
  } else if (suffix) {
    cout << 2 << endl;
  } else {
    cout << 3 << endl;
  }

  return 0;
}
