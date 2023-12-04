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

int n, q, c[int(2e5 + 5)], box_index[int(2e5 + 5)];
set<int> box[int(2e5 + 5)];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    box[i].insert(c[i]);
    box_index[i] = i;
  }

  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;

    int a_index = box_index[a], b_index = box_index[b];
    if (box[a_index].size() > box[b_index].size()) {
      swap(a_index, b_index);
      swap(box_index[a], box_index[b]);
    }

    auto iter = box[a_index].begin();
    while (iter != box[a_index].end()) {
      box[b_index].insert(*iter);
      iter++;
    }

    box[a_index] = {};
    cout << box[b_index].size() << endl;
  }

  return 0;
}