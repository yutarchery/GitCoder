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

int n, q, a[int(2e5 + 5)], b[int(2e5 + 5)], t[int(2e5 + 5)], ans[int(4e5 + 5)];
map<int, int> idx;
set<int> st;
vector<int> times;

int main() {
  cin >> n;
  st.insert(0);
  st.insert(int(1e9 + 5));
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    st.insert(a[i]);
    st.insert(b[i] + 1);
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> t[i];
  }

  int cnt = 0;
  for (int s : st) {
    idx[s] = cnt;
    times.push_back(s);
    cnt++;
  }
  for (int i = 1; i <= n; i++) {
    ans[idx[a[i]]]++;
    ans[idx[b[i] + 1]]--;
  }
  for (int i = 1; i <= 2 * n + 1; i++) {
    ans[i] += ans[i - 1];
  }

  for (int i = 1; i <= q; i++) {
    int l = 0, r = times.size();
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (times[mid] <= t[i]) {
        l = mid;
      } else {
        r = mid;
      }
    }

    cout << ans[l] << endl;
  }

  return 0;
}
