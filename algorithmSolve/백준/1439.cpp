#include <iostream>

using namespace std;

// 풀이.
// 입력받은 문자열의 각 원소를 순회하며 앞원소와 값이 두번 다를때마다 최종답 answer를 1씩 증가시켜
// 순회 후에 answer를 출력하면 된다. 첫번째 다를때에는 값이 바로 증가하지만 그 이후부터는 2번째부터
// 증가하기에 bool 변수를 이용하여야 했다.

// 자세한 설명은 주석으로 남긴다.

string str;

void MakeAnswer()
{
    // 값의 변동을 체크하는 bool 변수.
    bool isTrans = false;
    int answer = 0;
    for (int i = 1; i < str.size(); ++i)
    {
        // 앞원소와 값이 다를때마다 bool 변수를 반전시킨다.
        if (str[i] != str[i - 1])
        {
            isTrans ^= 1;
            // bool 변수가 true값이 되었을때 answer를 1씩 증가시킨다.
            // 예시를 잘보면 첫번째로 값이 다를때에는 값이 바로 증가하나
            // 그 이후부터는 두번 달라야 값이 1증가해야한다.
            answer = isTrans ? answer + 1 : answer;
        }
    }

    // 최종값 출력.
    cout << answer << '\n';
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