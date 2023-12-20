#include <iostream>

using namespace std;

// 슬라이딩 윈도우를 이용한 5582번의 더 빠른 풀이.
// 구현은 완전히 같으나 사용하는 메모리가 의미있게 차이나며
// 속도 또한 빨라진다. 아마 배열 생성 및 초기화에 시간이 단축되어
// 그만큼 속도가 빨라지는듯 하다.

// 자세한 설명은 주석으로 남긴다.

int board[2][4001] = { 0 };
string A, B;

void MakeAnswer()
{
    // 슬라이딩 윈도우를 제외한 모든 구현은 같다.
    int Asize = A.size(), Bsize = B.size();
    int answer = 0, idx = 0;
    for (int i = 0; i < Asize; ++i)
    {
        for (int j = 0; j < Bsize; ++j)
        {
            if (A[i] == B[j])
            {
                board[idx][j + 1] = board[1 - idx][j] + 1;
                if (board[idx][j + 1] > answer)
                    answer = board[idx][j + 1];
            }
            else
            {
                board[idx][j + 1] = 0;
            }
        }
        // 0에서 1로, 1에서 0으로.
        idx ^= 1;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> A >> B;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}