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
string s[int(1e5 + 5)];

pair<pair<int, string>, int> p[int(1e5 + 5)];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];

    bool flag = true;
    for (int j = 0; j < s[i].length(); j++) {
      if (flag && s[i][j] == '0') {
        p[i].second--;
      } else {
        flag = false;
        p[i].first.first++;
        p[i].first.second += s[i][j];
      }
    }
  }
  sort(p, p + n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < -1 * (p[i].second); j++) {
      cout << 0;
    }
    cout << p[i].first.second << endl;
  }

  return 0;
}