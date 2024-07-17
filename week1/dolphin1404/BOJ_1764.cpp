#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	set<string> arr;
  
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		arr.insert(str);
	}

	vector<string> answer;

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		
		auto it = arr.find(str);
		if (it != arr.end()) answer.push_back(str);
	}

	cout << answer.size() << "\n";
	
	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}