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

bool solve() {
  int n = s.length(), m = t.length();
  if (n > m) {
    return false;
  }

  int t_idx = 0;
  for (int i = 0; i < n; i++) {
    if (t_idx == m) {
      return false;
    }

    for (int j = t_idx; j < m; j++) {
      if (s[i] == t[j]) {
        t_idx = j + 1;
        break;
      }

      if (j == m - 1) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  cin >> s;
  while (!solve()) {
    t += "io";
  }
  cout << t.length() - s.length() << endl;

  return 0;
}
