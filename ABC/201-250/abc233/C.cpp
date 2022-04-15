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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n;
ll x;
vector<vector<ll>> a;
int ans = 0;

void dfs(int idx, ll rest) {
  if (idx == n) {
    if (rest == 1) {
      ans++;
    }
    return;
  }

  for (ll aij : a[idx]) {
    if (rest % aij == 0) {
      dfs(idx + 1, rest / aij);
    }
  }

  return;
}

int main() {
  cin >> n >> x;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    for (int j = 0; j < l; j++) {
      ll aij;
      cin >> aij;
      a[i].push_back(aij);
    }
  }

  dfs(0, x);
  cout << ans << endl;

  return 0;
}