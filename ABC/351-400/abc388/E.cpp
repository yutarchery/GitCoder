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

int n, a[int(5e5 + 5)];

bool judge(int now) {
  for (int i = 1; i <= now; i++) {
    if (a[i] * 2 > a[(n - now) + i]) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ok = 0, ng = n / 2 + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    if (judge(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << endl;

  return 0;
}
