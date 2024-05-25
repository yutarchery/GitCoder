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

int w, b, cnt[6005][2];
string s = "wbwbwwbwbwbw", t = "";

int main() {
  cin >> w >> b;
  while (t.length() < 5000) {
    t += s;
  }
  for (int i = 1; i <= t.length(); i++) {
    for (int j = 0; j < 2; j++) {
      cnt[i][j] = cnt[i - 1][j];
    }
    if (t[i - 1] == 'w') {
      cnt[i][0]++;
    } else {
      cnt[i][1]++;
    }
  }

  for (int i = 0; i <= t.length(); i++) {
    for (int j = i + 1; j <= t.length(); j++) {
      if (cnt[j][0] - cnt[i][0] == w && cnt[j][1] - cnt[i][1] == b) {
        Yes();
        return 0;
      }
    }
  }
  No();

  return 0;
}
