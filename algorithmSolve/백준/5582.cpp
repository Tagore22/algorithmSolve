#include <iostream>

using namespace std;

// 풀이. 
// 최장 공통 문자열, 즉 LCS를 이용한 문제였다.
// 점화식은 다음과 같다.

// if(i == 0 || j == 0)
//    board[i][j] = 0;
// else if(A[i] == B[j])
//    board[i][j] = board[i + 1][j + 1] + 1;
// else 
//    board[i][j] = 0;

// 다만 슬라이딩 윈도우를 이용한 더 빠른 풀이가 존재했다.
// 자세한 설명은 주석으로 남긴다.

int board[4001][4001] = { 0 };
string A, B;

void MakeAnswer()
{
    // LCS의 정석적인 알고리즘 구현.
    int Asize = A.size(), Bsize = B.size();
    int answer = 0;
    // 각 A와 B의 길이만큼 순회하며 위 점화식을 구현한다.
    // 다만 애시당초 0으로 초기화하여 점화식에서 맨 위 구현은 생략할수 있다.
    for (int i = 0; i < Asize; ++i)
        for (int j = 0; j < Bsize; ++j)
        {
            if (A[i] == B[j])
            {
                board[i + 1][j + 1] = board[i][j] + 1;
                answer = max(answer, board[i + 1][j + 1]);
            }
            else
            {
                board[i + 1][j + 1] = 0;
            }
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