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
ll d;
Pll rl[int(2e5 + 5)];

int main() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> rl[i].second >> rl[i].first;
  }
  sort(rl, rl + n);

  int ans = 0, now_r = 0;
  for (int i = 0; i < n; i++) {
    if (now_r < rl[i].second) {
      ans++;
      now_r = rl[i].first + d - 1;
    }
  }
  cout << ans << endl;

  return 0;
}