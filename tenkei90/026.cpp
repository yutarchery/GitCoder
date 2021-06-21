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

int N;
vector <int> G[int(1e5 + 5)], ans1, ans2;
bool used[int(1e5 + 5)];
int dist[int(1e5 + 5)];

int dfs(int node){
  used[node] = true;
  for (int i : G[node]){
    if (!used[i]){
      dist[i] = dist[node] + 1;
      dfs(i);
    }
  }
  return 0;
}

int main(){
  cin >> N;
  for (int i = 0; i < N - 1; i++){
    int A, B;
    cin >> A >> B;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  for (int i = 1; i <= N; i++){
    if (G[i].size() == 1){
      dfs(i);
      break;
    }
  }

  for (int i = 1; i <= N; i++){
    if (dist[i] % 2 == 0){
      ans1.push_back(i);
    }else{
      ans2.push_back(i);
    }
  }

  if (ans1.size() < ans2.size()){
    for (int i = 0; i < N / 2; i++){
      cout << ans2[i];
      if (i == N / 2 - 1) cout << endl;
      else cout << " ";
    }
  }else{
    for (int i = 0; i < N / 2; i++){
      cout << ans1[i];
      if (i == N / 2 - 1) cout << endl;
      else cout << " ";
    }
  }

  return 0;
}