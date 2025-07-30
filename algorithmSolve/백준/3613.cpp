#include <iostream>

using namespace std;

// 풀이.
// 20퍼에 달하는 정답율답게 실3치고는 난이도가 있던 문제다.
// 주어지는 문자열이 cpp이라면 java로, java라면 cpp로, 둘다 해당하지 않는다면
// "Error!"를 출력하는 문제인데 둘다 해당하지 않는 조건이 꽤나 추상적이라 애먹었다.

// 1. 대문자 혹은 '_'로 시작하는 경우.
// 2. '_'는 단어와 단어를 구분하기 위해 존재하므로 연속으로 나올 경우.
// 3. '_'가 맨 마지막에 나와서 나눌 단어가 없는 경우.
// 4. 문자열에 대문자와 '_'가 동시에 나오는 경우.

// 위 경우가 에러인 경우이고 나머지는 치환만 하면 된다. 또한, 예시에 주어진 name처럼
// 대문자나 '_'가 나오지 않을 경우도 존재함에 주의한다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    // 1번, 3번 경우.
    if (str[0] == '_' || ('A' <= str[0] && str[0] <= 'Z') || str[str.size() - 1] == '_')
    {
        cout << "Error!" << '\n';
        return 0;
    }
    bool isCpp = false, isJava = false;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '_')
        {
            isCpp = true;
            // 2번 경우.
            if (i != 0 && str[i - 1] == '_')
            {
                cout << "Error!" << '\n';;
                return 0;
            }
        }
        else if ('A' <= str[i] && str[i] <= 'Z')
            isJava = true;
    }
    // 4번 경우.
    if (isCpp && isJava)
    {
        cout << "Error!" << '\n';
        return 0;
    }
    // Java에서 Cpp로.
    else if (isJava)
    {
        for (int i = 0; i < str.size(); ++i)
        {
            if ('A' <= str[i] && str[i] <= 'Z')
            {
                str[i] += 32;
                cout << '_';
            }
            cout << str[i];
        }
    }
    // Cpp에서 Java로.
    else if (isCpp)
    {
        bool isupper = false;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == '_')
            {
                isupper = true;
                continue;
            }
            else if (isupper)
            {
                str[i] -= 32;
                isupper = false;
            }
            cout << str[i];
        }
    }
    // 둘다 속하는 소문자만 존재하는 경우.
    else
    {
        cout << str;
    }
    cout << '\n';
    return 0;
}