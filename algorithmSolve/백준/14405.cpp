#include <iostream>

using namespace std;

// 풀이.
// 처음에는 set을 이용할까도 생각했으나, 비교되는 문자열들이 짧고 수가 적기 때문에
// 그냥 주먹구구식으로 구현해도 상관이 없었다. 인덱스를 0부터 시작하여
// 각각 비교하여 마지막까지 맞는지 확인하되, 중간에 맞지 않다면 "NO"를 출력하고 탈출하면 되고
// 끝까지 도달하였다면 "YES"를 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

string str;

void MakeAnswer()
{
    int from = 0, to = str.size();
    while (from < to)
    {
        // 현재 "pi"일 경우. 2칸 건너뛴다.
        if (str[from] == 'p' && str[from + 1] == 'i')
        {
            from += 2;
        }
        // 현재 "ka"일 경우. 2칸 건너뛴다.
        else if (str[from] == 'k' && str[from + 1] == 'a')
        {
            from += 2;
        }
        // 현재 "chu"일 경우. 3칸 건너뛴다.
        else if (str[from] == 'c' && str[from + 1] == 'h' && str[from + 2] == 'u')
        {
            from += 3;
        }
        // 그 이외의 경우는 발음이 불가능하므로 "NO"를 출력후 탈출한다.
        else
        {
            cout << "NO" << '\n';
            return;
        }
    }
    // 마지막까지 모두 발음할수 있었으므로 "YES"를 출력하고 탈출한다.
    cout << "YES" << '\n';
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