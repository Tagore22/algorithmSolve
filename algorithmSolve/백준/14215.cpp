#include <iostream>
#include <algorithm>

using namespace std;


// 풀이.
// 처음에는 이등변 삼각형, 피타고라스의 법칙 등등 별의 별것들 다 떠올렸었으나, 삼각형의 성립법칙이라는게 있었다.
// 아주 간단했는데 세변의 길이중 가장 긴 변의 길이가 나머지 두변의 길이의 합보다 작아야한다는 것이다.
// 따라서 각 세변의 값을 입력받아서 오름차순으로 정렬하여 board[2]값을 비교후 줄일지 말지를 선택하여 값을 출력하면 된다.

int board[3];

int main()
{
    for (int i = 0; i < 3; ++i)
        cin >> board[i];

    sort(board, board + 3);
    if (board[2] < board[0] + board[1])
        cout << board[0] + board[1] + board[2] << '\n';
    else
        cout << board[0] + board[1] + board[0] + board[1] - 1 << '\n';
    return 0;
}