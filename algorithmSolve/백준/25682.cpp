#include <iostream>
#include <algorithm>

using namespace std;

// ���� �Ϸ����� Ǯ���µ� ��Ǯ����. ���߿� �ٽ� �����غ���.

// 2025. 1. 1
// ���� ������ ���� Ȯ���غ��� �����Ͽ� �κ��տ��� �ô� �����̾���.
// ���� �� ����� �ȳ�����. �� �����ؾ߰ڴ�.

int N, M, K;
char board[2000][2000];

int chess(char color) {
	int value, pSum[N + 1][M + 1] = {};

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!((i + j) % 2)) value = board[i][j] != color; // (i + j) % 2 = 0�� ���, ���ڷ� �ҷ��� color �״��
			else value = board[i][j] == color; // (i + j) % 2 = 1�� ���, ���ڷ� �ҷ��� color �ݴ��

			pSum[i + 1][j + 1] = pSum[i][j + 1] + pSum[i + 1][j] - pSum[i][j] + value;
		}
	}
	int tmp, result = 100000000;

	for (int i = 0; i <= N - K; i++) {
		for (int j = 0; j <= M - K; j++) {
			tmp = pSum[i + K][j + K] - pSum[i][j + K] - pSum[i + K][j] + pSum[i][j];
			result = (tmp < result) ? tmp : result;
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	cout << min(chess('B'), chess('W')) << '\n';
}