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

int n;
string s[105];

bool judge(int i, int j) {
  string t = s[i];
  t += s[j];

  for (int k = 0; k < t.length(); k++) {
    if (t[k] != t[t.length() - 1 - k]) {
      return false;
    }
  }

  return true;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        continue;
      }
      if (judge(i, j)) {
        Yes();
        return 0;
      }
    }
  }
  No();

  return 0;
}
