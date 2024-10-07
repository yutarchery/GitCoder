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

int k;
vector<ll> ans;

void solve(ll num) {
  ans.push_back(num);
  if (num % 10 == 0) {
    return;
  }

  for (int i = 0; i < num % 10; i++) {
    solve(num * 10 + i);
  }
  return;
}

int main() {
  cin >> k;
  for (int i = 1; i <= 9; i++) {
    solve(i);
  }
  sort(ans.begin(), ans.end());
  cout << ans[k - 1] << endl;

  return 0;
}
