#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 하나의 문자열에서 공백을 만날때마다 단어를 출력하면 된다.
// 공백 있는 문자열을 입력받기 위해 getline()을 사용하였는데 이 함수에는 주의해야할점이 하나 있다.
// 바로 띄워쓰기 등의 공백마저 입력받는다는 것이다. 예를 들어 문제에서 처음 N을 입력하게 되어
// 3을 입력후 엔터를 치면 그 엔터가 입력스트링에 들어가 있는다. 이후 getline()을 호출하면 이 엔터가
// 저장되게 된다. 이것을 해결하기 위한 방법은 2가지가 있다.

// 1. getline()을 다시 호출하여 기존의 엔터를 무시한채 새로 입력받는다.
// 2. cin.ignore()을 호출하여 기존 입력스트링 안에 있는 것들을 무시한다.

// 뭘 해도 상관은 없으나 cin.ignore()가 더 빨랐다.

// 자세한 설명은 주석으로 남긴다.

string str;
int N;

void MakeAnswer()
{
    for (int iter = 0; iter < N; ++iter)
    {
        getline(cin, str);
        int ssize = str.size();
        int space = ssize;
        cout << "Case #" << iter + 1 << ": ";
        // 모든 문자를 순회하며 공백이 나왔을시 공백 사이의 단어를 출력한다.
        for (int i = ssize - 1; i >= 0; --i)
        {
            if (str[i] == ' ')
            {
                for (int j = i + 1; j < space; ++j)
                    cout << str[j];
                cout << ' ';
                space = i;
            }
        }
        // 마지막 단어를 출력한다.
        for (int i = 0; i < space; ++i)
            cout << str[i];
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin.ignore();
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}