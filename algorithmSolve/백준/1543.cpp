#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//풀이
//문자열 l과 s를 받아서 l에서 s를 몇번 셀수 있는지에 대한 문제다. 다만 l에서 s를 발견하면 그 부분은 제외하고 다음부분에서부터 다시 세어야 한다.
//그렇기에 string::find 함수를 사용하되 시작점이 되는 idx를 s의 길이만큼 늘려줘야 중복으로 세지 아니한다.
//또한, 입력받는 l, s에 공백이 존재할수 있기에 보통처럼 cin이 아닌 getline을 사용해줘야한다.

string l, s;

void MakeAnswer()
{
    int answer = 0, idx = 0;

    while (true)
    {
        idx = l.find(s, idx);
        if (idx == string::npos)
            break;
        idx += s.size();
        ++answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getline(cin, l);
    getline(cin, s);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}