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

int q, t, x, d;
char c;

vector<Pii> now;

int main() {
  cin >> q;
  int idx = 0;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> c >> x;
      now.push_back({c - 'a', x});
    } else {
      cin >> d;
      ll del[26] = {};

      while (d > 0) {
        if (now.size() == idx) {
          break;
        }

        if (now[idx].second <= d) {
          del[now[idx].first] += now[idx].second;
          d -= now[idx].second;
          now[idx].second = 0;
          idx++;
        } else {
          del[now[idx].first] += d;
          now[idx].second -= d;
          break;
        }
      }

      ll ans = 0;
      for (int i = 0; i < 26; i++) {
        ans += del[i] * del[i];
      }
      cout << ans << endl;
    }
  }

  return 0;
}
