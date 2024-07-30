#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
  int answer = 0;
  priority_queue<int> pq;
  queue<pair<int, int>> q;

  for(int i = 0; i < priorities.size(); i++){
    pq.push(priorities[i]);
    q.push(make_pair(priorities[i], i));
  }

  while(true){
    int a = q.front().first;  // 우선순위
    int b = q.front().second; // 위치
    q.pop();

    if(a == pq.top()){ 
      pq.pop();
      answer++;
      if(b == location) break;
    }else q.push(make_pair(a, b));
  }
  return answer;
}