#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 풀이.
// 문자열에서 공백이 아닌 단어들의 순서를 뒤집어 출력하는 문제다.
// 공백까지 모두 입력받아야하기에 <string>의 getline()을 사용하면 되지만
// 한가지 문제가 발생한다. 테스트케이스를 입력받을때 행 바꿈 입력까지 받게 되는데
// 바로 getline()을 사용하면 그 행 바꿈 입력이 아직 입력스트림에 남아 있어
// 그것을 입력받는 것이다. 따라서 테스트케이스 입력 이후에 입력스트림을 비우기 위해
// 의미없는 getline() 혹은 cin.ignore()등을 미리 처리해주어야 한다.
// 참고로 cin.ignore()가 단순 입력스트림을 비우기만 하는것이기에 더 빨랐다.

// 자세한 설명은 주석으로 남긴다.

string str;
int T;

void ReverseStr()
{
    int from = 0;
    int Ssize = str.size();
    for (int i = 0; i < Ssize; ++i)
    {
        if (str[i] == ' ')
        {
            reverse(str.begin() + from, str.begin() + i);
            from = i + 1;
        }
    }
    // 만약 공백이 없을시 위 for문은 아예 시도조차 되지 않는다. 따라서 맨 마지막 처리가 필요하다.
    reverse(str.begin() + from, str.end());
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        getline(cin, str);
        ReverseStr();

        cout << str << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    // 위 상술한 테스트케이스를 입력받을때의 행 바꿈 입력을 비워주는 단계.
    // getline()이든, cin.ignore()든 상관은 없으나 후자가 더 빨랐다.
    getline(cin, str);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}