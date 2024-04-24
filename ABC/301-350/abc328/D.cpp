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
set<int> st;

int main() {
  cin >> s;
  for (int i = 0; i < int(s.length()); i++) {
    st.insert(i);
  }

  auto iter1 = st.begin(), iter2 = iter1, iter3 = iter2;
  iter2++;
  iter3++;
  iter3++;

  while (true) {
    if (s[*iter1] == 'A' && s[*iter2] == 'B' && s[*iter3] == 'C') {
      int a = *iter1, b = *iter2, c = *iter3;
      if (iter1 == st.begin()) {
        iter1 = iter3;
        iter1++;
      } else {
        iter1--;
        if (iter1 != st.begin()) {
          iter1--;
        }
      }

      st.erase(a);
      st.erase(b);
      st.erase(c);

      if (iter1 == st.end()) {
        break;
      }
      iter2 = iter1;
      iter2++;
      if (iter2 == st.end()) {
        break;
      }
      iter3 = iter2;
      iter3++;
    } else if (iter3 == st.end()) {
      break;
    } else {
      iter1++;
      iter2++;
      iter3++;
    }
  }

  for (int i : st) {
    cout << s[i];
  }
  cout << endl;

  return 0;
}
