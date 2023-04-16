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

int n, q;
int num, i, j;

multiset<int> box[int(2e5 + 5)];
set<int> number[int(2e5 + 5)];

void display_box(int idx) {
  vector<int> ans;
  auto iter = box[idx].begin();

  while (iter != box[idx].end()) {
    ans.push_back(*iter);
    iter++;
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i == ans.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return;
}

void display_number(int idx) {
  vector<int> ans;
  auto iter = number[idx].begin();

  while (iter != number[idx].end()) {
    ans.push_back(*iter);
    iter++;
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i == ans.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return;
}

int main() {
  cin >> n >> q;
  for (int k = 0; k < q; k++) {
    cin >> num;

    if (num == 1) {
      cin >> i >> j;
      number[i].insert(j);
      box[j].insert(i);

    } else if (num == 2) {
      cin >> i;
      display_box(i);
    } else {
      cin >> i;
      display_number(i);
    }
  }

  return 0;
}