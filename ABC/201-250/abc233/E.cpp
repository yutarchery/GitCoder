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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int ans[int(1e6 + 5)];

int main() {
  string x;
  cin >> x;

  for (int i = 0; i < x.length(); i++) {
    ans[i] += x[x.length() - 1 - i] - '0';
  }

  for (int i = x.length(); i >= 0; i--) {
    ans[i] += ans[i + 1];
  }

  for (int i = 0; i < int(1e6) - 1; i++) {
    ans[i + 1] += ans[i] / 10;
    ans[i] %= 10;
  }

  bool displayFirst = false;
  for (int i = int(1e6) - 1; i >= 0; i--) {
    if (!displayFirst && ans[i] == 0) {
      continue;
    }
    displayFirst = true;
    cout << ans[i];
  }
  cout << endl;

  return 0;
}