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

int n;
string s, t, u;

int main() {
  cin >> n;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      t += "BB";
    } else {
      t += s[i];
    }
  }

  for (int i = 0; i < t.length(); i++) {
    if (i + 1 < t.length() && t[i] == 'B' && t[i + 1] == 'B') {
      u += 'A';
      i++;
    } else {
      u += t[i];
    }
  }

  cout << u << endl;

  return 0;
}