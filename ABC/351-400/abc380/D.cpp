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

ll n;
string s;
int q;
ll k[int(2e5 + 5)], pows[65];
char ans[int(2e5 + 5)];

char reverse(char c) {
  if ('A' <= c && c <= 'Z') {
    return char(c - 'A' + 'a');
  } else {
    return char(c - 'a' + 'A');
  }
}

int main() {
  cin >> s;
  n = s.length();

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> k[i];
  }

  pows[0] = 1;
  for (int i = 1; i <= 60; i++) {
    pows[i] = pows[i - 1] * 2;
  }

  for (int i = 1; i <= q; i++) {
    char c = s[(k[i] - 1) % n];
    ll num = (k[i] - 1) / n + 1;

    bool flag = true;
    for (int j = 60; j >= 1; j--) {
      if (num >= pows[j - 1]) {
        flag = !flag;
        num = num % pows[j - 1];
        if (num == 0) {
          num = pows[j - 1];
        }
      }
    }

    if (flag) {
      ans[i] = reverse(c);
    } else {
      ans[i] = c;
    }
  }

  cout << ans[1];
  for (int i = 2; i <= q; i++) {
    cout << " " << ans[i];
  }
  cout << endl;

  return 0;
}
