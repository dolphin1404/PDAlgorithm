#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    int N;
    cin >> N;
    unordered_map<int,bool> hash_map;
    for(int i =0; i<N; i++) {
        int num;
        cin >> num;
        hash_map[num] = true;
    }

    int M;
    cin >> M;

    for(int i=0; i< M ; i++) {
        int key;
        cin >> key;
        if(hash_map.find(key) != hash_map.end()) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
}