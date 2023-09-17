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

int l1, r1, l2, r2;
bool red[105], blue[105];

int main() {
  cin >> l1 >> r1 >> l2 >> r2;
  for (int i = l1; i < r1; i++) {
    red[i] = true;
  }
  for (int i = l2; i < r2; i++) {
    blue[i] = true;
  }

  int ans = 0;
  for (int i = 0; i <= 100; i++) {
    if (red[i] && blue[i]) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}