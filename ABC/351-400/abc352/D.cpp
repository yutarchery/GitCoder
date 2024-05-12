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

int n, k, p[int(2e5 + 5)], idx[int(2e5 + 5)];
set<int> st;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    idx[p[i]] = i;
  }

  for (int i = 1; i < k; i++) {
    st.insert(idx[i]);
  }

  int ans = n;
  for (int i = k; i <= n; i++) {
    st.insert(idx[i]);

    auto s = st.begin(), t = st.end();
    t--;
    ans = min(ans, *t - *s);

    st.erase(idx[i - k + 1]);
  }
  cout << ans << endl;

  return 0;
}
