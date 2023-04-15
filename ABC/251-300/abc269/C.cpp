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
vector<ll> candidate, ans;
map<ll, bool> used;

void solve(ll num, int i) {
  if (!used[num]) {
    ans.push_back(num);
    used[num] = true;
  }

  if (i == candidate.size()) {
    return;
  }

  solve(num, i + 1);
  solve(num + candidate[i], i + 1);
  return;
}

int main() {
  cin >> n;

  ll now = 1, rest = n;
  for (int i = 0; i < 61; i++) {
    if ((n | now) == n) {
      candidate.push_back(now);
    }
    now *= 2;
  }

  solve(0, 0);
  sort(ans.begin(), ans.end());

  for (ll a : ans) {
    cout << a << endl;
  }

  return 0;
}