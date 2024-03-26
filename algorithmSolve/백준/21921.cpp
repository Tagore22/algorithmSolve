#include <iostream>

using namespace std;

// 풀이
// 누적합과 투포인터 혹은 슬라이딩 윈도우를 사용하면 되는 문제다.
// 문제에서 직접적으로 연속된 날들중 이라는 말은 없었으나 문제에 예시를 보면 연속된 날들중 최대값을 구하는 것을
// 알수 있다. 따라서 첫번째 날부터 X번째 날까지 총합을 초기값으로 구해서 그 이후부터 하루씩 더하고 가장 오래된날을 지우고
// 하는 식으로 각 일자의 값을 알수 있다. 이렇게 모든 일자를 순회해도 최대 25만번밖에 들지 않기에 시간내에도 충분히 풀수 있다.

// 자세한 설명은 주석으로 남긴다.

int board[250000];
int N, X;

void MakeAnswer()
{
    // 연속된 X일의 총합을 초기화한다.
    int sum = 0;
    for (int i = 0; i < X; ++i)
        sum += board[i];
    pair<int, int> answer = make_pair(1, sum);
    // 모든 일자를 순회하며 총합의 최대값 및 겹치는 횟수를 찾는다.
    for (int i = X; i < N; ++i)
    {
        // 새로운 앞부분을 추가하고,
        sum += board[i];
        // 가장 뒷부분을 지운다.
        sum -= board[i - X];
        // 최대값을 한번 더 찾았다면 횟수를 증가시킨다.
        if (sum == answer.second)
            ++answer.first;
        // 새로운 최대값을 찾았다면 갱신한다.
        else if (sum > answer.second)
            answer = make_pair(1, sum);
    }
    // 만약 최대값이 0이라면.
    if (answer.second == 0)
        cout << "SAD" << '\n';
    // 그렇지 않다면.
    else
        cout << answer.second << '\n' << answer.first << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> X;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}