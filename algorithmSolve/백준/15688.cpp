#include <iostream>

using namespace std;

// 풀이.
// 그냥 값을 입력받아 sort()로 정렬하여 출력해도 되지만 이렇게 for문을 두번 사용하여
// 앞에서부터 등장한 횟수만큼 출력해주어도 된다. 다만 sort()의 최적화가 매우 강력하게 되어있기에
// N이 특출나게 큰 경우가 아니면 감수해야하는 메모리에 비해 속도에 있어서 유의미한 차이는 나지 않았다.

const int MAXNUM = 2000001;
int board[MAXNUM];
int N;

void Solve()
{
    for (int iter = 0; iter < N; ++iter)
    {
        int num;
        cin >> num;
        ++board[num + 1000000];
    }

    for (int i = 0; i < MAXNUM; ++i)
    {
        while (board[i])
        {
            cout << i - 1000000 << '\n';
            --board[i];
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    Solve();
    return 0;
}