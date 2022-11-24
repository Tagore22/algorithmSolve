#include <iostream>

using namespace std;

//코딩 수정시 변수 이름 하나를 바꿔주지 않아서 어처구니 없이 한번 틀린 문제. 확인을 잘하자

//풀이
//변수 3개를 받아서 같은 수가 몇개 있는지를 찾는 문제다. 주사위를 3개 던지기에 결과적으로 3번을 확인해야하는데, 코드를 깔끔하게 하고자 for문을 썼다. 
//3개의 수가 모두 같다면 변수 equal은 3이 될테고, 2개의 수만 같다면 1이 될것이다. 2는 절대로 존재할수 없으며 모두 다르다면 0이 된다.
//나머지는 N명이 얻는 상금중 최고 금액을 출력하면 된다.

int dice[3];
int N;

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        int equal = 0, check = 0, max_num = -1;

        for (int j = 0; j < 3; ++j)
        {
            cin >> dice[j];
            max_num = max(max_num, dice[j]);
        }

        for (int from = 0; from < 3; ++from)
            for (int to = from + 1; to < 3; ++to)
                if (dice[from] == dice[to])
                {
                    ++equal;
                    check = dice[from];
                }

        if (equal == 3)
            answer = max(answer, 10000 + check * 1000);
        else if (equal == 1)
            answer = max(answer, 1000 + check * 100);
        else
            answer = max(answer, max_num * 100);
    }
    cout << answer << '\n';
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
    MakeAnswer();
    return 0;
}