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

int n, m, r[int(2e5 + 5)], c[int(2e5 + 5)];

int ans = 0;
set<Pii> st;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> r[i] >> c[i];
  }

  for (int i = 1; i <= m; i++) {
    bool flag = true;
    for (int di = 0; di <= 1; di++) {
      for (int dj = 0; dj <= 1; dj++) {
        auto iter = st.lower_bound({r[i] + di, c[i] + dj});

        if (iter != st.end() && (*iter).first == r[i] + di &&
            (*iter).second == c[i] + dj) {
          flag = false;
        }
      }
    }

    if (flag) {
      ans++;

      for (int di = 0; di <= 1; di++) {
        for (int dj = 0; dj <= 1; dj++) {
          st.insert({r[i] + di, c[i] + dj});
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
