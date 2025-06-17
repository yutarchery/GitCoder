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

int n, q, num, x, c;

int color_count[int(5e5 + 5)];
set<Pii> st;

int main() {
  cin >> n >> q;
  for (int i = 0; i <= n + 1; i++) {
    color_count[i]++;
    st.insert({i, i});
  }

  while (q--) {
    cin >> num;
    if (num == 1) {
      cin >> x >> c;

      auto now_iter = st.upper_bound({x, n + 1});
      now_iter--;
      Pii now = *now_iter;

      auto before_iter = now_iter;
      before_iter--;
      Pii before = *before_iter;

      auto next_iter = now_iter;
      next_iter++;
      Pii next = *next_iter;

      color_count[now.second] -= next.first - now.first;
      color_count[c] += next.first - now.first;
      st.erase(now_iter);

      Pii p = {now.first, c};
      if (before.second == c) {
        st.erase(before_iter);
        p.first = before.first;
      }
      if (next.second == c) {
        st.erase(next_iter);
      }
      st.insert(p);
    } else {
      cin >> c;
      cout << color_count[c] << endl;
    }
  }

  return 0;
}
