#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int digit_sum(const string &str) {
    int sum = 0;
    for(char c : str) {  
        if(isdigit(c)) {
            sum += c - '0';
        }
    }
    return sum;
}

bool compare_serial(const string &a, const string &b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    else {
        int sum_a = digit_sum(a);
        int sum_b = digit_sum(b);
        if(sum_a != sum_b) {
            return sum_a < sum_b;
        }
    }
    return a < b;
}

int main() {
    int N;
    cin >> N;
    vector<string> serials(N);

    for(int i = 0; i < N; i++) {
        cin >> serials[i];
    }
    sort(serials.begin(), serials.end(), compare_serial);

    for(int i = 0; i < serials.size(); i++) {
        cout << serials[i] << endl;
    }
    return 0;
}
