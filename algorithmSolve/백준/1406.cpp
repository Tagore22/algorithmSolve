#include <iostream>
#include <list>

using namespace std;

//처음엔 아무 생각 없이 string으로 구현했는데 당연하게도 시간초과가 떴다. 중간에 삽입하는 경우가 많은 경우는 list가 제일 빠르다.

//풀이
//주어지는 입력은 최대 4개의 경우가 있다. 각 경우에 따라서 반복자의 위치를 추적해가며 문자열을 추가 혹은 삭제해나간다.
//별개로 list 등의 연관 컨테이너의 반복자는 원소 추가시에도 변동되지 않는데, 말 그대로 새로운 원소가 삽입되는 경우 distance함수로 begin부터 현재까지 도달할때
//새로운 원소 삽입으로 인해 거리가 1 늘어남으로 현재 반복자를 따로 건드리지 않아도 알아서 거리가 증가한다.
//랜덤 액세스 반복자는 원소의 크기 변화시 날라감. 잊지 말것.

list<char> board;
string str;
int N;

void MakeAnswer()
{
    list<char>::iterator idx = board.end();
    char com;
    for (int i = 0; i < N; ++i)
    {
        cin >> com;
        if (com == 'L' && idx != board.begin())
        {
            --idx;
        }
        else if (com == 'D' && idx != board.end())
        {
            ++idx;
        }
        else if (com == 'B' && idx != board.begin())
        {
            --idx;
            idx = board.erase(idx);
        }
        else if (com == 'P')
        {
            char plus;
            cin >> plus;
            board.insert(idx, plus);
        }
    }

    for (auto& a : board)
        cout << a;
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str >> N;
    for (int i = 0; i < str.size(); ++i)
        board.push_back(str[i]);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}