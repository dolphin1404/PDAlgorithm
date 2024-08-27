#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> arr(N);
        for(int i = 0; i < N; i++) {
            cin >> arr[i].first >> arr[i].second;
        }

        sort(arr.begin(), arr.end());

        int count = 1; 
        int bestInterviewRank = arr[0].second; 

        for(int i = 1; i < N; i++) {
            if(arr[i].second < bestInterviewRank) {
                count++;
                bestInterviewRank = arr[i].second; 
            }
        }
        cout << count << endl;
    }

    return 0;
}
