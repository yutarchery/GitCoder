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
vector<ll> ans;

int main() {
  cin >> n;
  for (int i = 1; i <= 12; i++) {
    ll num_i = (pow(10, i) - 1) / 9;
    for (int j = i; j <= 12; j++) {
      ll num_j = (pow(10, j) - 1) / 9;
      for (int k = j; k <= 12; k++) {
        ll num_k = (pow(10, k) - 1) / 9;
        ans.push_back(num_i + num_j + num_k);
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans[n - 1] << endl;

  return 0;
}
