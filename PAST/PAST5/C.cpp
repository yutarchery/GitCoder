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

int main() {
  int n;
  cin >> n;

  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }

  string ans = "";
  while (n > 0) {
    int num = n % 36;

    char c;
    if (num < 10) {
      c = '0' + num;
    } else {
      c = 'A' + (num - 10);
    }

    ans = c + ans;
    n /= 36;
  }
  cout << ans << endl;

  return 0;
}