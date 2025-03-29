#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n,m;
    vector<string> arr;
    map<string, int> hashmap;

    cin >> n >> m;
    for(int i=0; i<n+m; i++) {
        string str;
        cin >> str;
        hashmap[str]++;
        if(hashmap[str] == 2) {
            arr.push_back(str);
        }
    }
    sort(arr.begin(), arr.end());
    cout << arr.size() << endl;
    for(int i =0; i<arr.size();i++) {
        cout << arr[i] << endl;
    }
}