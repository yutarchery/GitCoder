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

int n, q, t, x, y;
int a[int(2e5 + 5)];

set<int> st;

void update(int idx) {
  swap(a[idx], a[idx + 1]);

  for (int i = idx - 1; i <= idx + 1; i++) {
    if (a[i] > a[i + 1]) {
      st.insert(i);
    } else {
      st.erase(i);
    }
  }

  return;
}

int main() {
  cin >> n >> q;
  for (int i = 0; i <= n + 1; i++) {
    a[i] = i;
  }

  while (q--) {
    cin >> t >> x >> y;

    if (t == 1) {
      update(x);
    } else {
      while (!st.empty()) {
        auto iter = st.lower_bound(x);
        if (iter == st.end()) {
          break;
        }
        if (*iter >= y) {
          break;
        }
        update(*iter);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i] << (i == n ? "\n" : " ");
  }

  return 0;
}
