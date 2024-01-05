#include <iostream>

using namespace std;

// 풀이.
// 연속적으로 점점 커지거나 작아지는 가장 긴 연속수열의 길이를 출력하는 문제다.
// 점점 커지는것이 가장 길때도 있고 반대의 경우도 있으므로 모두 파악해야했다.
// 예를 들어 점점 커지다가 이번에 작아지면 기존의 커진 길이를 최종답 answer와 비교하여 갱신하고
// 다시 작아지는 답을 키우면 된다. 

// 자세한 설명은 주석으로 남긴다.

int board[100000];
int N;

void MakeAnswer()
{
    cin >> board[0];
    // 모든 길이의 최소값은 현재 원소로부터 시작하는 1이다.
    int answer = 1, upper = 1, lower = 1;
    for (int i = 1; i < N; ++i)
    {
        cin >> board[i];
        // 현재 원소가 기존 원소보다 클때.
        // 이전에는 점점 작아졌을수도 있으므로 작아지는 값의 크기를
        // answer와 비교하여 갱신하고 1로 초기화시킨다.
        // 그후 커지는 값의 크기를 1 증가시킨다.
        if (board[i] > board[i - 1])
        {
            answer = max(answer, lower);
            lower = 1;
            ++upper;
        }
        // 현재 원소가 기존 원소보다 작을때.
        // 이전에는 점점 커졌을수도 있으므로 커지는 값의 크기를
        // answer와 비교하여 갱신하고 1로 초기화시킨다.
        // 그후 작아지는 값의 크기를 1 증가시킨다.
        else if (board[i] < board[i - 1])
        {
            answer = max(answer, upper);
            upper = 1;
            ++lower;
        }
        // 값이 같은 것은 양쪽 모두에 포함되기에 둘다 1 증가시킨다.
        else
        {
            ++upper;
            ++lower;
        }
    }
    // 이 부분이 빠졌었는데 예를 들어 N이 3이고 각 수열이 1, 1, 1일때
    // 답은 3이지만 실제로는 1이 된다. upper와 lower가 증가는 했으나 
    // 최종답 answer와 비교하는 곳이 위에는 없기 때문이다.
    // 또한 N이 3이고 각 수열이 1, 2, 3일때에도 답은 3이지만 실제로는 1이
    // 나온다. upper는 계속 증가하지만 answer와 비교하는곳이 없기 때문이다.
    answer = max(answer, upper);
    answer = max(answer, lower);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}