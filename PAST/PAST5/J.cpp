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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

string s;
ll x;

ll cnt[int(2e5 + 5)];

int main() {
  cin >> s >> x;
  for (int i = 1; i <= s.length(); i++) {
    if ('0' <= s[i - 1] && s[i - 1] <= '9') {
      ll now = s[i - 1] - '0';
      cnt[i] = min(ll(1e15), cnt[i - 1] * (now + 1));
    } else {
      cnt[i] = cnt[i - 1] + 1;
    }
  }

  for (int i = s.length(); i >= 0; i--) {
    if (cnt[i] < x) {
      if ('a' <= s[i] && s[i] <= 'z') {
        cout << s[i] << endl;
        break;
      } else {
        x = (x - 1) % cnt[i] + 1;
      }
    }
  }

  return 0;
}