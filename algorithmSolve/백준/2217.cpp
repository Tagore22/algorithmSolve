#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 방식만 알면 구현은 식은죽먹기인 문제다.
// 오름차순으로 정렬을 하여 현재부터 끝까지의 원소수 * 현재 로프가 버틸수 있는 중량을 모든 원소를 순회하며
// 구한후 그 최대값을 출력하면 된다. 다만 예를 들어 10만개의 동일한 중량을 버틸수 있는 로프 일경우 
// 10만번 - 1번을 무의미하게 계산해야하나 최대 10만번이므로 무시해도 된다.

// 자세한 설명은 주석으로 남긴다.

int board[100000];
int N;

void MakeAnswer()
{
    // 모든 원소들을 오름차순으로 정렬한다.
    sort(board, board + N);
    int answer = 0;

    // 모든 원소들을 순회하며 현재 중량 * 현재부터 끝까지의 원소수를 구하여 최대값과 비교하여 최대값을 갱신한다.
    for (int i = 0; i < N; ++i)
        answer = max(answer, board[i] * (N - i));

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}