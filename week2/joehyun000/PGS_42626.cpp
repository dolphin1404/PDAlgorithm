#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> minHeap(scoville.begin(),scoville.end());
    int answer = 0;

    while (minHeap.top() < K) {

        if (minHeap.size() < 2) {
            return -1;
        }
        answer++;

        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        
        int new_scoville = first + (second*2);
        minHeap.push(new_scoville);
    }

    return answer;
}
