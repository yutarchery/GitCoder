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
ll a[15];

vector<ll> tmp, vals;

void solve(int idx, ll val) {
  if (idx == n) {
    vals.push_back(val);
    return;
  }

  for (int i = 0; i < tmp.size(); i++) {
    ll next = val ^ tmp[i];
    tmp[i] += a[idx];
    solve(idx + 1, next ^ tmp[i]);
    tmp[i] -= a[idx];
  }

  tmp.push_back(a[idx]);
  solve(idx + 1, val ^ a[idx]);
  tmp.resize(tmp.size() - 1);

  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  solve(0, 0);

  sort(vals.begin(), vals.end());
  int ans = 1;
  for (int i = 1; i < vals.size(); i++) {
    if (vals[i] != vals[i - 1]) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
