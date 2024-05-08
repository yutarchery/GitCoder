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

int a, b, c, x, ans[3];

int main() {
  cin >> a >> b >> c;
  ans[1] += b;
  ans[2] += c;
  for (int i = 0; i < 12; i++) {
    cin >> x;
    ans[0] += max(0, (x - 3) * a);
    ans[1] += max(0, (x - 50) * a);
  }
  sort(ans, ans + 3);
  cout << ans[0] << endl;

  return 0;
}
