#include <iostream>

using namespace std;

// 풀이.
// 잠이 덜깨서 그런가 아니면 이런류의 문제가 오랜만이라 그런가 꽤나 헤맸던 문제다.
// 찾아야 하는 것은 가장 최소값의 겹치지 않는 십자가 모양 3개이다. 처음에는 DP나, DFS를 사용할까
// 했으나 첫째로 범위가 굉장히 적고, 둘째로 DP를 사용하기 굉장히 까다로운 문제였다.
// 따라서 중복연산이 있을지 몰라도 주먹구구식으로 풀수밖에 없었다.
// 정확히 말하자면 주먹구구식이 아니고 순회했다가 다시 되돌아와서 그 이후를 순회하는 뭐가 있었는데 기억이 안난다.
// 찾아보니 백트래킹이다. 풀이의 원리는 다음과 같다.

// 1. 1, 1부터 시작해서 첫번째 꽃의 위치를 찾는다. 
// 2. 그 위치부터 다시 순회해가며 다음 꽃의 위치를 찾는다.
// 3. 이렇게 3번째 꽃의 위치까지 찾았다면 여기서 그치지 않고 비용을 비교한후, 맨마지막(N - 2, N - 2)까지 순회하며
// 최소값을 비교한다.
// 4. 그랬을때 최초의 함수가 반환하는 값이 최종값이 된다.

// 아래 풀이를 보면 배열값을 벗어나는지 확인하는 코드가 없는데 애시당초 0, 0은 건너뛰고 1, 1부터 시작하는 원리를 적용하였기
// 때문이다. 또한 처음에 풀때 상술한 3번처럼 끝까지 돌아야하는데 그러지 않고 3번째 꽃까지 찾으면 바로 반환하였기에 이상한 답이
// 나왔다.

// 자세한 설명은 주석으로 남긴다.

bool isFlo[10][10] = { false, };
int board[10][10];
int N;

// y, x부터 새로운 꽃의 위치를 찾는 함수.
int CalCost(int y, int x, int num)
{
    // 이미 3개의 꽃을 모두 찾았다면 무시한다.
    if (num >= 3)
        return 0;
    // 비용의 최초값은 3001로 한다. 문제에서 가장 큰 한칸의 비용이 200이기 때문에 꽃 하나에 5칸 * 3개이므로
    // 최대 비용이 3000이기 때문이다.
    int sum = 3001;
    for (int i = y; i < N - 1; ++i)
    {
        // 최초로 가로를 순회할때는 x부터 시작해야하나 그 이후로는 1부터 시작해야한다.
        int row = i == y ? x : 1;
        for (int j = row; j < N - 1; ++j)
            // 현재 칸으로부터 십자가 모양이 모두 꽃의 위치가 아니라면
            if (!isFlo[i][j] && !isFlo[i - 1][j] && !isFlo[i][j - 1] && !isFlo[i + 1][j]
                && !isFlo[i][j + 1])
            {
                // 꽃의 위치임을 표시하고 다시 재귀하며 최소값을 비교한다.
                isFlo[i][j] = true;
                isFlo[i - 1][j] = true;
                isFlo[i][j - 1] = true;
                isFlo[i + 1][j] = true;
                isFlo[i][j + 1] = true;
                sum = min(sum, board[i][j] + board[i - 1][j] + board[i][j - 1] + board[i + 1][j] +
                    board[i][j + 1] + CalCost(i, j, num + 1));
                isFlo[i][j] = false;
                isFlo[i - 1][j] = false;
                isFlo[i][j - 1] = false;
                isFlo[i + 1][j] = false;
                isFlo[i][j + 1] = false;
                // 여기서 멈추지 않고 마지막까지 순회하며 모든 최소값을 찾아본다.
            }
    }
    // 최소값 반환.
    return sum;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];


    int answer = CalCost(1, 1, 0);

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