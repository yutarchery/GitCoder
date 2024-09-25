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

int n, q, a[int(2e5 + 5)], ik, xk;
set<int> mex;
map<int, int> cnt;

int main() {
  cin >> n >> q;
  for (int i = 0; i <= n + 1; i++) {
    mex.insert(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (cnt[a[i]] == 0 && a[i] <= n + 1) {
      mex.erase(a[i]);
    }
    cnt[a[i]]++;
  }

  for (int i = 1; i <= q; i++) {
    cin >> ik >> xk;
    cnt[a[ik]]--;
    if (cnt[a[ik]] == 0) {
      mex.insert(a[ik]);
    }

    a[ik] = xk;
    if (cnt[xk] == 0 && xk <= n + 1) {
      mex.erase(xk);
    }
    cnt[xk]++;

    cout << *mex.begin() << endl;
  }

  return 0;
}
