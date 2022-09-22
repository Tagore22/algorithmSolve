#include <iostream>
#include <string>

using namespace std;

//getline은 기존처럼 공백을 기준으로 하지 않고 한줄씩 입력받음.
//매개변수 순서 잊지말것. 또한, 헤더에 string이 있어야한다.

string str;

void Cal()
{
    int answer = 0;
    for (int i = 0; i < str.size(); ++i)
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
            || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            ++answer;
    cout << answer << '\n';
}

void MakeAnswer()
{
    while (true)
    {
        getline(cin, str);
        if (str == "#")
            break;
        Cal();
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Init();
    MakeAnswer();
    return 0;
}