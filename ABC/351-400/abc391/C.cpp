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

int n, q, num, p, h;
int loc[int(1e6 + 5)], cnt[int(1e6 + 5)], ans;

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    loc[i] = i;
    cnt[i]++;
  }

  while (q--) {
    cin >> num;
    if (num == 1) {
      cin >> p >> h;
      cnt[loc[p]]--;
      if (cnt[loc[p]] == 1) {
        ans--;
      }

      cnt[h]++;
      if (cnt[h] == 2) {
        ans++;
      }

      loc[p] = h;
    } else {
      cout << ans << endl;
    }
  }

  return 0;
}
