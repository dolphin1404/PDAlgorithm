#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < scoville.size(); i++) pq.push(scoville[i]);
    
    while (pq.top() < K)
    {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();
      int newsco = a + 2*b;
      pq.push(newsco);
      if(pq.size() == 1 && newsco < K) return -1;
      answer++;
    }
    return answer;
}