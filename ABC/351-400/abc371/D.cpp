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

int n, q, x[int(2e5 + 5)], l[int(2e5 + 5)], r[int(2e5 + 5)];
ll p[int(2e5 + 5)], sum[int(6e5 + 5)];

set<int> st;

map<ll, int> idx;
map<ll, ll> cnt;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    st.insert(x[i]);
  }
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    cnt[x[i]] = p[i];
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> l[i] >> r[i];
    st.insert(l[i] - 1);
    st.insert(r[i]);
  }

  int now = 1;
  for (int s : st) {
    idx[s] = now;
    now++;
  }
  for (int i = 1; i <= n; i++) {
    sum[idx[x[i]]] = p[i];
  }
  for (int i = 1; i <= int(6e5); i++) {
    sum[i] += sum[i - 1];
  }

  for (int i = 1; i <= q; i++) {
    cout << sum[idx[r[i]]] - sum[idx[l[i] - 1]] << endl;
  }

  return 0;
}
