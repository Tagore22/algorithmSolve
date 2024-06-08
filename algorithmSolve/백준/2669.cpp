#include <iostream>

using namespace std;

// 풀이.
// 얼핏보면 기하학과 연관된 문제 같으나 실제로는 전혀 관련없이 풀수 있다.
// 그 풀이가 아래 풀이다. 면적을 구하지 않고 그냥 사각형의 좌표를 입력받아
// 그 범위들을 board에 저장해두면 된다. 마지막에 board를 순회하며 저장되어있던
// 면적들을 모두 더해 출력하면 된다. 아마도 이전에 기하학으로 접근하려다가
// 넘긴거 같은데 그래도 이번에 풀어서 다행이다.

int main()
{
    bool board[101][101] = { false, };
    int x1, y1, x2, y2;
    for (int iter = 0; iter < 4; ++iter)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; ++i)
            for (int j = x1; j < x2; ++j)
                board[i][j] = true;
    }
    int answer = 0;
    for (int i = 0; i < 101; ++i)
        for (int j = 0; j < 101; ++j)
            if (board[i][j])
                ++answer;
    cout << answer << '\n';
    return 0;
}