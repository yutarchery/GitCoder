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

ll n, a, b, c, d, y;
string x;

int main() {
  cin >> n;
  cin >> a >> b >> c >> d;
  cin >> x;

  for (int i = 0; i < 5; i++) {
    if (x[i] == '.') {
      continue;
    }
    y *= 10;
    y += x[i] - '0';
  }

  ll sum = (1000 - y) * a + (2000 - y) * b + (3000 - y) * c + (4000 - y) * d;

  if (sum <= 0) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = sum / (y - 1000);
  if (sum % (y - 1000) != 0) {
    ans++;
  }

  cout << ans << endl;

  return 0;
}