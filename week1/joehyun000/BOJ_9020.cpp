#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

vector<int> PrimeList(int limit) {
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

pair<int, int> findPartition(int num, const vector<int>& primes) {
    pair<int, int> bestPartition = make_pair(-1, -1);
    int minDifference = num;
    
    for (int prime : primes) {
        if (prime > num / 2) break;
        
        int secondPrime = num - prime;
        if (isPrime(secondPrime)) {
            int difference = abs(prime - secondPrime);
            if (difference < minDifference) {
                minDifference = difference;
                bestPartition = make_pair(prime, secondPrime);
            }
        }
    }
    
    return bestPartition; 
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    int maxNum = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }

    vector<int> primes = PrimeList(10000);

    for (int num : arr) {
        pair<int, int> partition = findPartition(num, primes);
        if (partition.first != -1) {
            cout << partition.first << " " << partition.second << endl;
        }
    }

    return 0;
}
