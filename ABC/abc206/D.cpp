#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;
#define fi first
#define se second 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

struct UnionFind{
  int N;
  int parent[int(2e5 + 5)] = {};
  int cnt[int(2e5 + 5)] = {};

  int root(int node){
    if (parent[node] == 0){
      return parent[node] = node;
    }
    if (node == parent[node]){
      return node;
    }
    return parent[node] = root(parent[node]);
  }

  void unite(int node1, int node2){
    int root1 = root(node1), root2 = root(node2);
    parent[root1] = root2;
  }

  int solve(){
    for (int i = 1; i <= N; i++){
      cnt[root(i)]++;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++){
      if (cnt[i] == 0) continue;
      ans += cnt[i] - 1;
    }
    return ans;
  }
};

int N, A[int(2e5 + 5)];

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }

  UnionFind unionFind;
  unionFind.N = N;
  for (int i = 0; i < N; i++){
    unionFind.unite(A[i], A[N - 1 - i]);
  }
  cout << unionFind.solve() << endl;

  return 0;
}