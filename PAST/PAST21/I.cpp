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

int n, k;
int a[int(2e5 + 5)];

set<int> st;
int cnt[int(2e5 + 5)];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= k - 1; i++) {
    cnt[a[i]]++;
  }
  for (int i = 1; i <= k; i++) {
    if (cnt[i] != 1) {
      st.insert(i);
    }
  }

  int ans = 0;
  for (int i = k; i <= n; i++) {
    cnt[a[i]]++;
    if (cnt[a[i]] != 1) {
      st.insert(a[i]);
    } else {
      st.erase(a[i]);
    }

    if (st.empty()) {
      ans++;
    }

    cnt[a[i - k + 1]]--;
    if (cnt[a[i - k + 1]] != 1) {
      st.insert(a[i - k + 1]);
    } else {
      st.erase(a[i - k + 1]);
    }
  }
  cout << ans << endl;

  return 0;
}
