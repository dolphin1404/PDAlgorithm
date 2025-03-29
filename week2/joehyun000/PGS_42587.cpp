#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> priorityQueue;
    queue<pair<int, int>> printQueue;
    int answer = 0;
    
    for (int i = 0; i < priorities.size(); i++) {
        priorityQueue.push(priorities[i]);
        printQueue.push({priorities[i], i});
    }
    
    while (!priorityQueue.empty()) {
        int current_priority = printQueue.front().first;
        int current_index = printQueue.front().second;
        printQueue.pop();
        
        if (current_priority == priorityQueue.top()) {
            answer++;
            priorityQueue.pop();
            if (current_index == location) {
                return answer;
            }
        } else {
            printQueue.push({current_priority, current_index});
        }
    }
    return answer;
}
