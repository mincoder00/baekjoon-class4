#include <bits/stdc++.h>
using namespace std;
int arr[8];


void dfs(int n, int m, int depth, int start) {
	if (depth == m) {
		for (int i = 0;i < m;i++) cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = start;i <= n;i++) {
		arr[depth] = i;
		dfs(n, m, depth + 1, i + 1);
	}
}


int main(void) {
	int n, m;
	cin >> n >> m;
	dfs(n, m, 0, 1);
}

/*
[백트래킹 문제]
dfs + depth 개념를 활용한 pruning
key point: 여기서 끝나는 것이 아니라 "고른 수열은 오름차순이어야 한다." 조건
따라서 {2,3}과 {3,2} 중에서 {2,3}만 유효하다!
이를 위해서 인자 start를 dfs 함수에 하나 더 추가
i=start부터 시작해서 n까지 반복문을 돌고, 재귀 호출에서는 현재 i에 1 더한 값을 start로 넣어준다.
*/