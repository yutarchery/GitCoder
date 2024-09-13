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
ll x, y, a[int(2e5 + 5)], b[int(2e5 + 5)];

int main() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + n + 1, greater<ll>());
  sort(b + 1, b + n + 1, greater<ll>());

  int ans_a = n;
  ll now_a = 0;
  for (int i = 1; i <= n; i++) {
    if (now_a + a[i] > x) {
      ans_a = i;
      break;
    }
    now_a += a[i];
  }

  int ans_b = n;
  ll now_b = 0;
  for (int i = 1; i <= n; i++) {
    if (now_b + b[i] > y) {
      ans_b = i;
      break;
    }
    now_b += b[i];
  }

  cout << min(ans_a, ans_b) << endl;

  return 0;
}