#include <iostream>

using namespace std;

// 풀이.
// 0 ~ 9번째 인덱스들중 2중 for문으로 하나씩 선택할때 그 2개를 제외한
// 나머지 7개의 합이 100이라면 출력한다.

int board[9];
int answer = 0;

int main()
{
    for (int iter = 0; iter < 9; ++iter)
    {
        cin >> board[iter];
        answer += board[iter];
    }

    for (int i = 0; i < 9; ++i)
        for (int j = i + 1; j < 9; ++j)
            if (answer - board[i] - board[j] == 100)
            {
                for (int iter = 0; iter < 9; ++iter)
                    if (iter != i && iter != j)
                        cout << board[iter] << '\n';
                return 0;
            }
}