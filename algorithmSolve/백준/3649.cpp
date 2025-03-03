#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 문제 자체는 어려울게 없었다. while(cin >> 변수)를 통한 eof처리와 투포인터를 통해
// 합이 X가 되는 차이가 가장 큰 한쌍을 찾으면 되기 때문이다. 다만 한가지 실수로 인해
// 20분은 넘게 헤맨것 같다.

// 자세한 설명은 주석으로 남긴다.

int board[1000000];
int X, N;
const int MUL = 10000000;

void MakeAnswer()
{
    // eof 처리.
    while (cin >> X)
    {
        cin >> N;
        for (int iter = 0; iter < N; ++iter)
            cin >> board[iter];
        // 센티미터에서 나노미터로의 치환.
        X *= MUL;

        // 투포인터 처리를 위한 정렬.
        sort(board, board + N);
        int from = 0, to = N - 1;
        // 본래라면 답을 찾았을때 while문을 탈출해야 하나 한층 더 밖의
        // while문을 탈출하면 안되기에 답을 찾았는지 못찾았는지를 따지는
        // bool 변수가 하나 필요하다.
        bool bIsFind = false;
        // 이곳에서 실수가 있었다. 아무 생각없이 from <= to로 구현하였기 때문이다.
        // 하지만 문제에서는 무조건 2개의 조각을 찾아야했기 때문에 from == to인 경우는
        // 존재해서는 안된다.
        while (from < to)
        {
            // 합이 X인 최초의 한쌍을 발견하였다면 출력후 작은 while문을 탈출한다.
            // 문제에서 차이가 가장 큰 한쌍을 요구하였는데 양끝에서 시작하는 투포인터 특성상
            // 최초로 발견된 이 한쌍의 차이가 가장 크기 때문이다.
            if (board[from] + board[to] == X)
            {
                cout << "yes " << board[from] << ' ' << board[to] << '\n';
                bIsFind = true;
                break;
            }
            // 합이 클 경우 to값을 줄여 맞춰나간다.
            else if (board[from] + board[to] > X)
            {
                --to;
            }
            // 합이 작을 경우 from값을 늘려 맞춰나간다.
            else
            {
                ++from;
            }
        }
        // 모든 순회 끝에 답을 찾지 못했을 경우.
        if (!bIsFind)
            cout << "danger" << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}