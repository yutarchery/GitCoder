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

int n, a[int(2e5 + 5)], loc[int(2e5 + 5)];
vector<Pii> ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    loc[a[i]] = i;
  }

  for (int i = 1; i <= n; i++) {
    if (loc[i] == i) {
      continue;
    }

    int b = a[i];
    ans.push_back({i, loc[i]});
    swap(a[i], a[loc[i]]);
    swap(loc[i], loc[b]);
  }

  cout << ans.size() << endl;
  for (Pii p : ans) {
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}
