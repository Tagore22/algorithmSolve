#include <iostream>
#include <cctype>

using namespace std;

//풀이
//tolower 함수로 대문자를 소문자로 변환시켜, 입력받은 문자열에 대입시킨다.

int N;

void MakeAnswer()
{
    string answer;
    for (int i = 0; i < N; ++i)
    {
        cin >> answer;
        for (int j = 0; j < answer.size(); ++j)
            answer[j] = tolower(answer[j]);

        cout << answer << '\n';
    }
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