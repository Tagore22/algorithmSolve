#include <iostream>

using namespace std;

//풀이
//'('와 ')'의 개수를 추적한다. '('가 들어오면 수를 plus를 1 증가하고 ')'가 들어오면 plus가 1 이상일 경우 감소한다.
//다만 plus가 0이라는 건 '('없이 ')'만 있다는 것이기에 추가해야하는 괄호값 answer을 1 증가한다.
//string을 모두 순회한 끝에 plus가 1이상이라는건 '('을 ')'로 없애지 못한채 남아 있다는 것이기에 answer에 남은 plus값을 더해서
//최종 답으로 출력한다.

string str;

void MakeAnswer()
{
    int answer = 0;
    int plus = 0;
    for (auto& c : str)
    {
        if (c == '(')
        {
            ++plus;
        }
        else
        {
            if (plus != 0)
                --plus;
            else
                ++answer;
        }
    }
    cout << answer + plus << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}