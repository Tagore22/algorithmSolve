#include <iostream>

using namespace std;

// 풀이.
// 고민을 많이 했던 문제다. for문을 여러번 돌며 가장 큰수부터 하나씩 줄여나가기에는 100만 * 100만의 연산량을
// 요구하기에 시간초과가 났고, 현재 등장하는 높이들을 저장해서 한번의 for문으로 풀기에는 저장할만한 컨테이너가
// 없었다. 우선순위 큐는 인덱스를 사용할 수 없고 인덱스가 가능한 벡터나 다른 컨테이너들은 저장된 값들을 빨리 꺼
// 내기 위해 lower_bound를 사용하기에는 매번 정렬해야했기 때문이다. 따라서 컨테이너가 아닌 현재 존재하는 높이들
// 을 가리키는 1 ~ 100만짜리 배열과 현재 높이의 수를 따로 계산해서 구해야했다.

// 자세한 설명은 주석으로 남긴다.

int board[1000001];
int N;

void MakeAnswer()
{
    // 현재 존재하는 높이값 answer
    int answer = 0, num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        // 현재 높이 num의 값이 존재한다면 따로 쏠 필요가 없다
        if (board[num] != 0)
            --board[num];
        // 존재하지 않는다면 높이 num에서 무조건 한번은 쏴야한다
        else
            ++answer;
        // 다음엔 높이값보다 1 낮춘 값에서 쏴야한다
        ++board[num - 1];
    }
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