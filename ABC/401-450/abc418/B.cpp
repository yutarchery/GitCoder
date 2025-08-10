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

string s;
double ans = 0;

int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    for (int j = i + 2; j < s.length(); j++) {
      if (s[i] == 't' && s[j] == 't') {
        int cnt = 0;
        for (int k = i + 1; k <= j - 1; k++) {
          if (s[k] == 't') {
            cnt++;
          }
        }
        ans = max(ans, double(cnt) / double(j - i - 1));
      }
    }
  }
  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}
