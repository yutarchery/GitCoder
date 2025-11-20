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

int n;
ll x[int(5e5 + 5)];

set<Pli> st;
ll dist[int(5e5 + 5)], ans[int(5e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }

  st.insert({0, 0});
  st.insert({1e16, 0});

  dist[0] = x[1];
  dist[1] = x[1];
  ans[1] = x[1] * 2;
  st.insert({x[1], 1});

  for (int i = 2; i <= n; i++) {
    auto before_iter = st.lower_bound({x[i], i});
    auto after_iter = before_iter;
    before_iter--;
    Pli bf = *before_iter, af = *after_iter;

    ans[i] = ans[i - 1];
    ans[i] =
        ans[i] - dist[bf.second] + min(dist[bf.second], abs(bf.first - x[i]));
    dist[bf.second] = min(dist[bf.second], abs(bf.first - x[i]));

    ans[i] =
        ans[i] - dist[af.second] + min(dist[af.second], abs(af.first - x[i]));
    dist[af.second] = min(dist[af.second], abs(af.first - x[i]));

    dist[i] = min(abs(bf.first - x[i]), abs(af.first - x[i]));
    ans[i] = ans[i] + dist[i];
    st.insert({x[i], i});
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
