#include <iostream>

using namespace std;

// 2792번의 두번째 풀이.
// 총 값이 2의 31제곱인 16억보다도 적기에 기껏해야 40번도 이진 탐색을 실행하지 않기에
// 이 풀이가 2배가량 더 빨랐다. 탐색 방법만 조금 다르고 나머지는 첫번째 풀이와 동일하다.

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

    // 상술하였듯 최대 수가 10억인 상황에서 이진 탐색을 기껏해야 35번도 채 실행되지 않는다.
    // 그렇기에 100번을 탐색하는 첫번째 풀이보다 이 풀이가 훨씬 빠르다.
    // 실제로도 2개 가까이 빨랐다.
    while (from <= to)
    {
        int mid = (from + to) / 2;
        // 여기서 mid를 대입해본다.

        // 상술하였듯 인원수가 딱 맞거나 더 적다면 나누어줄 보석의 수를 줄여야 하고
        if (Check(mid))
            to = mid - 1;
        // 오히려 인원수가 많다면 나누어줄 보석의 수를 늘려야한다. 
        else
            from = mid + 1;
    }
    // 이 부분이 헷갈리기 쉽기에 유의해야한다.
    // 정답의 범위는 늘 from ~ to(mid - 1)까지다. 그중 가장 작은수를 출력해야하기에
    // from을 출력한다. 첫번째 풀이와 다르면서 가장 헷갈리기 쉽다. 유의할것.
    cout << from << '\n';
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