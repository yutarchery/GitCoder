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

int n, a[int(3e5 + 5)], cnt[int(3e5 + 5)];
set<int> st1, st2;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i == 1) {
      st1.insert(a[i]);
    } else {
      cnt[a[i]]++;
      st2.insert(a[i]);
    }
  }

  int ans = st1.size() + st2.size();
  for (int i = 2; i <= n - 1; i++) {
    cnt[a[i]]--;
    st1.insert(a[i]);
    if (cnt[a[i]] == 0) {
      st2.erase(a[i]);
    }
    ans = max(ans, int(st1.size()) + int(st2.size()));
  }
  cout << ans << endl;

  return 0;
}
