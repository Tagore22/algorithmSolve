#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 두 문자열이 에너그램인지 확인하는 문제이다.
// 즉 문자열의 존재하는 단어들을 파악하면 되는데 여러가지 풀이가 존재한다.
// 각 문자열을 순회하며 존재하는 문자들의 수를 파악해도 되고, 아래 풀이처럼 정렬하여 같은지
// 확인해도 된다. 다만 나는 정렬하는게 더 편해서 이렇게 하였다.

// 자세한 설명은 주석으로 남긴다.


// from과 to는 이후 두 문자열의 에너그램 여부에 사용되는데 기존의 문자열이 필요할때 쓰인다.
string str1, str2, from, to;
int T;

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        cin >> str1 >> str2;

        from = str1;
        to = str2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        // 두 문자열의 정렬 결과가 같다면 에너그램, 그렇지 않다면 에너그램이 아니다.
        if (str1 == str2)
            cout << from << " & " << to << " are anagrams." << '\n';
        else
            cout << from << " & " << to << " are NOT anagrams." << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}