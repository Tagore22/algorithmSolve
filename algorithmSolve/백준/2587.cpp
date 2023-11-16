#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 주어지는 5개의 값들의 평균과 3번째로 큰 수를 출력하는 문제다.
// 평균은 그냥 더해서 5로 나누면 되고, 3번째로 큰 수는 정렬하여 얻을수 있다.

// 자세한 설명은 주석으로 남긴다.

int board[5];
int sum = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 5개의 수를 입력받는다.
    for (int i = 0; i < 5; ++i)
    {
        // 정렬할 배열에 저장한다.
        cin >> board[i];
        // 평균을 구하기 위해 모두 더한다.
        sum += board[i];
    }

    // 평균을 출력한다.
    cout << sum / 5 << '\n';
    // 정렬하여 3번째로 큰 수를 출력한다.
    sort(board, board + 5);
    cout << board[2] << '\n';

    return 0;
}