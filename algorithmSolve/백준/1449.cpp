#include <iostream>
#include <algorithm>

using namespace std;

//생각보다 난해한 문제인듯 했으나, 언제나 그렇듯 쫄아서 그런것뿐이다.

//풀이
//처음에 난해하다고 생각했던건 최소 0.5만큼은 더 크게 붙여야 한다는 것과, 한번의 테이프로 여러개의 새는 곳을 막는 것을 어떻게 연관시켜서 풀지였다.
//답은 생각보다 간단했는데 예를 들어 처음 물이 새는 곳이 1이고 테이프의 길이가 2라면 최소한 0.5부터 2.5까지 붙일수 있다는 것이다.
//그렇다면 2에서 샌곳까지 막을수 있는 건데 이는 처음 새는곳 - 1 + 테이프의 길이인 2까지 막을수 있다는 것이다.
//게다가 주어지는 위치는 모두 자연수라서 최소 1이기에 0으로 인한 - 연산은 일어나지 않기에 이 또한 걱정할 필요가 없다.
//결국 풀이는 모든 위치를 정렬한 뒤에 처음 새는곳 - 1 + L까지 현재 테이프 위치를 잡아놓고 1번째(실제로는 2번째)원소부터 해당 테이프 위치안에 존재하는지를
//확인하면 된다. 만약 존재하지 않는다면 다시 테이프의 수를 한개 늘리고 현 원소 - 1 + L까지 테이프를 붙인후 다시 반복문을 순회하면 된다.


int board[1000];
int N, L;

void MakeAnswer()
{
    sort(board, board + N);
    int cur = board[0] - 1 + L;
    int answer = 1;
    for (int i = 1; i < N; ++i)
        if (board[i] > cur)
        {
            cur = board[i] - 1 + L;
            ++answer;
        }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}