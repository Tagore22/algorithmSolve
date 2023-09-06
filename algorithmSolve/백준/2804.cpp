#include <iostream>

using namespace std;

// 풀이.
// 뭐랄까.. 귀찮지만 어렵지 않은 브론즈 특유의 기본적인 출력에 좀더 중시한 문제다.
// 문자열 A와 B가 주어질때 A에서 가장 앞에서부터 또한 B의 가장 앞에서부터 두 문자열의 겹치는 문자를
// 찾아 크로스로 출력하는 문제다.

// 자세한 설명은 주석으로 남긴다.

string str1, str2;
int a, b;

// 이중 for문으로 가장 앞부분에서부터 겹치는 문자의 위치를 찾는 함수.
void FindPivot()
{
    for (int i = 0; i < str1.size(); ++i)
    {
        for (int j = 0; j < str2.size(); ++j)
        {
            if (str1[i] == str2[j])
            {
                a = i, b = j;
                return;
            }
        }
    }
}

void MakeAnswer()
{
    cin >> str1 >> str2;
    FindPivot();
    // 출력부분이 조금 까다로웠다. 
    for (int i = 0; i < b; ++i)
    {
        for (int j = 0; j < a; ++j)
            cout << '.';
        cout << str2[i];
        for (int j = a + 1; j < str1.size(); ++j)
            cout << '.';
        cout << '\n';
    }
    cout << str1 << '\n';
    for (int i = b + 1; i < str2.size(); ++i)
    {
        for (int j = 0; j < a; ++j)
            cout << '.';
        cout << str2[i];
        for (int j = a + 1; j < str1.size(); ++j)
            cout << '.';
        cout << '\n';
    }
}

int main()
{
    MakeAnswer();
    return 0;
}