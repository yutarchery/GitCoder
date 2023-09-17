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

int n, w[int(2e5 + 5)];
string s;

map<int, int> child, adult;
pair<int, Pii> p[int(2e5 + 5)];
int child_cnt[int(2e5 + 5)], adult_cnt[int(2e5 + 5)];

int main() {
  cin >> n;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];

    if (s[i - 1] == '0') {
      child[w[i]]++;
    } else {
      adult[w[i]]++;
    }
  }
  sort(w, w + n + 1);

  int idx = 1;
  for (int i = 1; i <= n; i++) {
    if (w[i] == w[i - 1]) {
      continue;
    }

    p[idx] = {w[i], {child[w[i]], adult[w[i]]}};
    idx++;
  }

  for (int i = 1; i <= idx; i++) {
    child_cnt[i] = child_cnt[i - 1] + p[i].second.first;
  }
  for (int i = idx; i >= 1; i--) {
    adult_cnt[i] = adult_cnt[i + 1] + p[i].second.second;
  }

  int ans = 0;
  for (int i = 1; i <= idx; i++) {
    ans = max(ans, child_cnt[i - 1] + adult_cnt[i + 1] +
                       max(p[i].second.first, p[i].second.second));
  }
  cout << ans << endl;

  return 0;
}