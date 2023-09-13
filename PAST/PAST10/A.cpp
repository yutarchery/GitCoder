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

int x[3], ans_min = 1e9, ans_max = -1e9;

int main() {

  for (int i = 0; i < 3; i++) {
    cin >> x[i];
  }

  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      ans_min = min(ans_min, x[i] * x[j]);
      ans_max = max(ans_max, x[i] * x[j]);
    }
  }
  cout << ans_min << " " << ans_max << endl;

  return 0;
}