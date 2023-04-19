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

int n, ord[5];
string s, t;

bool judge_same() {
  if (s == t) {
    return true;
  }

  bool same = true;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[n - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    ord[i] = i;
  }

  do {
    t = "";
    for (int i = 0; i < n; i++) {
      t += s[ord[i]];
    }

    if (!judge_same()) {
      cout << t << endl;
      return 0;
    }
  } while (next_permutation(ord, ord + n));

  cout << "None" << endl;

  return 0;
}