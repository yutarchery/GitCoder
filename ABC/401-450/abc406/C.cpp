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

int n, p[int(3e5 + 5)];
Pll cnt[int(3e5 + 5)];
map<Pll, ll> pair_cnt;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  for (int i = 2; i + 1 <= n; i++) {
    if (p[i - 1] < p[i] && p[i] > p[i + 1]) {
      cnt[i].first++;
    }
    if (p[i - 1] > p[i] && p[i] < p[i + 1]) {
      cnt[i].second++;
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    cnt[i].first += cnt[i - 1].first;
    cnt[i].second += cnt[i - 1].second;
    pair_cnt[cnt[i]]++;
  }

  ll ans = 0;
  for (int i = 1; i + 3 <= n; i++) {
    if (p[i] >= p[i + 1]) {
      continue;
    }

    ans += pair_cnt[{cnt[i].first + 1, cnt[i].second + 1}];
  }
  cout << ans << endl;

  return 0;
}
