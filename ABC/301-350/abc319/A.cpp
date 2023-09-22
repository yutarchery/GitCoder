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

int main() {
  pair<string, int> p[10] = {{"tourist", 3858},   {"ksun48", 3679},
                             {"Benq", 3658},      {"Um_nik", 3648},
                             {"apiad", 3638},     {"Stonefeang", 3630},
                             {"ecnerwala", 3613}, {"mnbvmar", 3555},
                             {"newbiedmy", 3516}, {"semiexp", 3481}};

  string s;
  cin >> s;
  for (int i = 0; i < 10; i++) {
    if (s == p[i].first) {
      cout << p[i].second << endl;
    }
  }

  return 0;
}