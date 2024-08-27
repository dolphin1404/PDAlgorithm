#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> stack;
    
    for (char digit : number) {
        while (!stack.empty() && stack.back() < digit && k > 0) {  //비어있지 않고 빼려는 수가 0보다 크고 현재 수가 스택 맨윗값보다 클때
            stack.pop_back(); 
            k--;
        }
        stack.push_back(digit);
    }
    
    while (k > 0) {
        stack.pop_back();
        k--;
    }
    
    for (char digit : stack) {
        answer += digit;
    }
    
    return answer;
}
