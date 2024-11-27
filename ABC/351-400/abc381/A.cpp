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
string s;
bool ans = true;

int main() {
  cin >> n;
  cin >> s;

  if (n % 2 == 0) {
    ans = false;
  }
  if (s[n / 2] != '/') {
    ans = false;
  }

  for (int i = 0; i < n / 2; i++) {
    if (s[i] != '1') {
      ans = false;
    }
  }
  for (int i = n / 2 + 1; i < n; i++) {
    if (s[i] != '2') {
      ans = false;
    }
  }

  if (ans) {
    Yes();
  } else {
    No();
  }

  return 0;
}
