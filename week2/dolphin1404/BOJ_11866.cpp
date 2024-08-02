#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> q;

int main(){
  cin >> n >> k;
  for(int i = 1; i <= n; i++) q.push(i);
  cout << "<";
  while(q.size() != 0){
    for(int j = 1; j < k; j++){
      q.push(q.front());
      q.pop();
    }
    cout << q.front();
    if(q.size() != 1) cout << ", ";
    q.pop();
  }
  cout << ">";
  return 0;
}