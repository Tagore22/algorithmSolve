#include <iostream>

using namespace std;

//´Ü¼øÇÑ µ¡¼À, »¬¼À ±¸Çö

void MakeAnswer()
{
    int answer = 0, minus, plus, check = 0;
    for (int i = 0; i < 4; ++i)
    {
        cin >> minus >> plus;
        check -= minus;
        check += plus;
        answer = answer < check ? check : answer;
    }

    cout << answer << '\n';
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Init();
    MakeAnswer();
    return 0;
}