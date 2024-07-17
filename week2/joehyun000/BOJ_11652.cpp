#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<long long, int> countMap;


    for(int i=0; i < N; i++) {
        long long num;
        cin >> num;
        countMap[num]++;
    }

    long long maxNum = 0;
    int maxCount = 0;
    for (auto map = countMap.begin(); map != countMap.end(); ++map) {
        if (map->second > maxCount || (map->second == maxCount && map->first < maxNum)) {
            maxNum = map->first;
            maxCount = map->second;
        }
    }

    cout << maxNum << endl;
    return 0;
}