#include <iostream>
#include <cctype>

using namespace std;

//Ǯ��
//tolower �Լ��� �빮�ڸ� �ҹ��ڷ� ��ȯ����, �Է¹��� ���ڿ��� ���Խ�Ų��.

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