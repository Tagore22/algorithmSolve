#include <iostream>

using namespace std;

// 풀이.
// 2792번의 첫번째 풀이.
// 이진 탐색 문제인데 그 탐색의 방법 2가지중 첫번째 풀이이다.
// 무조건 100번을 탐색하는 방법인데 겨우 100번이라 이 방법을 자주 사용하였었다.
// 하지만 맹점이 있었는데 한번 한번에 최대 30만의 연산이 들어갈 경우
// 100번은 총 3000만이 되어버린다. 그렇기 때문에 BFS, DFS처럼 상황에 맞게 
// 2가지중 하나를 골라야한다.

// 자세한 설명은 주석으로 남긴다.

int board[300000];
int N, M;

// 현재 개수의 가능성을 체크하는 함수.
bool Check(int num)
{
    int cur = 0;
    // 각 보석을 나누어줄수 있는 총 인원들의 수를 구한다.
    for (int i = 0; i < M; ++i)
    {
        cur += board[i] / num;
        if (board[i] % num != 0)
            ++cur;
    }

    // 인원수가 딱 맞거나 더 적다면 나누어줄 보석의 수를 줄여야 하고
    // 오히려 인원수가 많다면 나누어줄 보석의 수를 늘려야한다. 
    return cur <= N;
}

void MakeAnswer()
{
    int from = 1;
    int to = 1000000000;
    for (int i = 0; i < 100; ++i)
    {
        int mid = (from + to) / 2;
        // 여기서 mid를 대입해본다.

        // 상술하였듯 인원수가 딱 맞거나 더 적다면 나누어줄 보석의 수를 줄여야 하고
        if (Check(mid))
            to = mid;
        // 오히려 인원수가 많다면 나누어줄 보석의 수를 늘려야한다. 
        else
            from = mid;
    }
    // 이 부분이 헷갈리기 쉽기에 유의해야한다.
    // 정답의 가능성이 있는 값은 늘 to이다.(to = mid가 되는 부분) 그렇기 때문에
    // to를 반환해야한다. 다른 풀이에서와 다른다. 유의할것.
    cout << to << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}