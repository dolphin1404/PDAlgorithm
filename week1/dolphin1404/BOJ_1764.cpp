#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	set<string> s;	// key값만 저장하기 위해 (자동 정렬)
	
	for (int i = 0; i < n; i++){
		string str;
		cin >> str;
		s.insert(str);
	}

	vector<string> answer;

	for (int i = 0; i < m; i++){
		string str;
		cin >> str;

		auto it = s.find(str);	// index 위치
		if(it != s.end()) answer.push_back(str);
	}
	
	cout << answer.size() << "\n";

	sort(answer.begin(), answer.end());
	
	for (int i = 0; i < answer.size(); i++){
		//cout << answer.at(i) << "\n"; // 범위를 점검하여 느림
		cout << answer[i] << "\n";	// 범위를 점검하지 않아 5배정도 더 빠름. 그러나 예외발생 처리가 안됨
	}
}

/*
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
*/