#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 공백이 포함된 문자열을 입력받은 후 그중 웃는 이모티콘과 우는 이모티콘의 개수를 파악한후
// 비교하여 그 결과값을 출력한다.

// 자세한 설명은 주석으로 남긴다.

string str;

void MakeAnswer()
{
    int h = 0, s = 0;
    // 모든 문자들을 순회하며 각 이모티콘의 개수를 파악한다.
    for (int i = 0; i < str.size() - 2; ++i)
    {
        if (str[i] == ':' && str[i + 1] == '-')
        {
            if (str[i + 2] == ')')
                ++h;
            else if (str[i + 2] == '(')
                ++s;
        }
    }

    // 각 이모티콘의 개수를 비교하여 결과값을 출력한다.
    if (h == 0 && s == 0)
        cout << "none" << '\n';
    else if (h == s)
        cout << "unsure" << '\n';
    else if (h > s)
        cout << "happy" << '\n';
    else
        cout << "sad" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getline(cin, str);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}