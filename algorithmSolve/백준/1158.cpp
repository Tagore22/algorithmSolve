#include <iostream>
#include <list>

//아래 후술할 부분에서 이른바 삽질을 해서 시간을 꽤나 많이 썼다. 반성...

//풀이
//list나 queue를 쓰면 되는 문제인데 나는 list를 썼다. 반복자를 K-1번씩 앞으로 나아가며 도달한 원소의 값을 출력하고 삭제하기를 반복하면 된다.

using namespace std;

int N, K;

void MakeAnswer()
{
    list<int> board;
    for (int i = 1; i <= N; ++i)
        board.push_back(i);

    list<int>::iterator iter = board.begin();
    cout << "<"; //문자 < 하나만을 출력하기에 ' '이든 " " 이든 상관 없음.
    while (board.size() > 1)
    {
        for (int i = 0; i < K - 1; ++i)
        {
            ++iter;
            if (iter == board.end())
                iter = board.begin();
        }

        cout << *iter << ", "; //여기 이 부분에서 기존엔 ', '를 썼는데 다시 생각해보면 말도 안되는 일이다. ' '로 출력한다는건 char타입 하나를 출력한다는 것이기에
                               //이 부분과는 알맞지 않다. 그렇기에 문자열 출력인 " "를 쓰는 것이 맞다.
        iter = board.erase(iter);
        if (iter == board.end())
            iter = board.begin();
    }
    cout << *board.begin() << ">" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}