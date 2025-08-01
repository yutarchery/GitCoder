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

ll x;
priority_queue<Pll> que;

map<ll, ll> ans;
map<ll, bool> visited;

ll solve(ll num) {
  if (visited[num]) {
    return ans[num];
  }

  visited[num] = true;
  if (num <= 3) {
    return ans[num] = num;
  }

  return ans[num] = (solve(num / 2) * solve((num + 1) / 2)) % MOD2;
}

int main() {
  cin >> x;
  cout << solve(x) << endl;

  return 0;
}
