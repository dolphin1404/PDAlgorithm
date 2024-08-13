#include<iostream>
#include<queue>
using namespace std;

bool can_go(int top, int now, int goal, int up, int down, int* button)
{
	vector<bool> visited(top + 1, false); // 방문 여부를 체크하는 배열
	queue<pair<int, int>> q; // (현재 층, 버튼 누른 횟수) 저장
	q.push({now, 0});
	visited[now] = true;

	while (!q.empty()) {
		int current_floor = q.front().first;
		int current_button = q.front().second;
		q.pop();

		if (current_floor == goal) {
			*button = current_button;
			return true;
		}

		int next_floor_up = current_floor + up;
		if (next_floor_up <= top && !visited[next_floor_up]) {
			visited[next_floor_up] = true;
			q.push({next_floor_up, current_button + 1});
		}

		int next_floor_down = current_floor - down;
		if (next_floor_down >= 1 && !visited[next_floor_down]) {
			visited[next_floor_down] = true;
			q.push({next_floor_down, current_button + 1});
		}
	}

	// 목표 층에 도달할 수 없는 경우
	return false;
}

int main() {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	int button_count = 0;

	if (can_go(f, s, g, u, d, &button_count)) {
		cout << button_count;
	} else {
		cout << "use the stairs";
	}
	return 0;
}
