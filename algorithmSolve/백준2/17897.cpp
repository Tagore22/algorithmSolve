#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 뭔가 이상하다 했더니 주어지는 문자열에 공백이 존재했다.
// getline()을 이용한 문자열 입력과 cin >> 이후에 공백을
// 날려버리기 위한 cin.ignore()만 안다면 문제없다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string answer = "Anywhere is fine I guess";
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        string name;
        cin.ignore();
        getline(cin, name);
        bool hascake = false, hassoup = false;
        for (int j = 0; j < k; ++j)
        {
            string str;
            getline(cin, str);
            if (str == "pancakes")
                hascake = true;
            else if (str == "pea soup")
                hassoup = true;
        }
        if (hascake && hassoup && answer == "Anywhere is fine I guess")
            answer = name;
    }
    cout << answer << '\n';
    return 0;
}