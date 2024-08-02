#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while (pq.size() > 1 && pq.top() < K) {
        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();
        int scoville_sum = s1 + s2 * 2;
        pq.push(scoville_sum);
        answer++;
    }
    
    if(pq.top() == 1 && pq.top() < K)
        answer = -1;
    return answer;
}