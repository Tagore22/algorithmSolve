#include <iostream>

using namespace std;

//bool 변수 2개를 이용하여 각각 내림순인지 오름순인지 확인해가며 배열을 순회한다.
//둘다 아닌 상태가 되었을 경우 mixed를 출력하며 프로그램을 종료한다.

const int BOARD_NUM = 8;
int board[BOARD_NUM];

void MakeAnswer()
{
    bool asc = true; //오름순인가
    bool des = true; //내림순인가
    for (int i = 1; i < BOARD_NUM; ++i)
    {
        if (board[i - 1] < board[i])
            des = false;
        else
            asc = false;
        if (!des && !asc)
        {
            cout << "mixed" << '\n';
            return;
        }
    }
    cout << (des ? "descending" : "ascending") << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < BOARD_NUM; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}