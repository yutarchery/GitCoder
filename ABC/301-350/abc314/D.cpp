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

int n, q, t, x;
int last_updated[int(5e5 + 5)], l;
char s[int(5e5 + 5)], c;
bool bigger = false, lower = false;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> t >> x >> c;
    if (t == 1) {
      s[x] = c;
      last_updated[x] = i;
    } else if (t == 2) {
      bigger = false;
      lower = true;
      l = i;
    } else {
      bigger = true;
      lower = false;
      l = i;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (l < last_updated[i]) {
      cout << s[i];
    } else {
      if (!bigger && !lower) {
        cout << s[i];
      } else {
        if ('A' <= s[i] && s[i] <= 'Z') {
          s[i] = s[i] - 'A' + 'a';
        }

        if (bigger) {
          cout << char(s[i] - 'a' + 'A');
        } else {
          cout << s[i];
        }
      }
    }
  }
  cout << endl;

  return 0;
}
