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

ll n;

const ll coins[6] = {1, 5, 10, 50, 100, 500};

vector<Pll> ans;

void solve(ll rest, int idx, ll now) {
  if (idx == 5) {
    ans.push_back({now % 500, rest + now / 500});
    return;
  }

  for (ll i = 0; i <= min(rest, coins[idx + 1] / coins[idx] - 1); i++) {
    solve(rest - i, idx + 1, now + i * coins[idx]);
  }

  return;
}

int main() {
  cin >> n;
  solve(n, 0, 0);
  cout << ans.size() << endl;

  return 0;
}
