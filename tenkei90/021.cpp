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

int N, M;
vector <int> G[int(1e5 + 5)], H[int(1e5 + 5)];
vector <int> I;

bool used[int(1e5 + 5)];

int dfs(int node){
  used[node] = true;
  for (int next : G[node]){
    if (!used[next]){
      dfs(next);
    }
  }
  I.push_back(node);
  return 0;
}

ll cnt = 0, ans = 0;
int dfs2(int node){
  used[node] = true;
  cnt++;
  for (int next : H[node]){
    if (!used[next]){
      dfs2(next);
    }
  }
  return 0;
}

int main(){
  cin >> N >> M;
  for (int i = 0; i < M; i++){
    int A, B; cin >> A >> B;
    G[A].push_back(B);
    H[B].push_back(A);
  }

  for (int i = 1; i <= N; i++){
    if (!used[i]) dfs(i);
  }

  fill(used, used + N + 1, false);
  for (int i = N - 1; i >= 0; i--){
    if (!used[I[i]]){
      cnt = 0;
      dfs2(I[i]);
      ans += cnt * (cnt - 1) / 2;
    }
  }
  cout << ans << endl;

  return 0;
}