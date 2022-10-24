#include <iostream>
#include <string>

//답의 크기가 너무 커서 long long으로도 다 담지 못하기에 string을 써야했다. 이상한 곳에서 시간을 많이 잡아먹었는데 두 문자열을 더하는
//함수에서 두 문자열의 길이를 맞추기 위해 짧은 쪽 앞에 계속 0을 더해준다. 두 문자열의 크기를 비교해가며 똑같을때 까지 계속 더해주는데
//이것을 초기에 Asize, Bsize로 잡아놓고 이 값을 증가시키지 않은 채로 while문을 돌리며 왜 시간초과가 뜨지 라고 생각하고 있었다. ㅠㅠ

using namespace std;

const int MAX_NUM = 100 + 1;
string board[MAX_NUM][MAX_NUM];
int n, m;

string AddStr(string a, string b)
{
    if (a.size() > b.size()) //기존에 Asize, Bsize 두개의 변수로 초창기 길이 값을 잡아놓고 while문을 돌리고 있었음.
        while (a.size() != b.size())
            b = '0' + b;
    else
        while (a.size() != b.size())
            a = '0' + a;

    string add = "";
    int check = 0;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        check += (a[i] - '0') + (b[i] - '0');
        add = to_string(check % 10) + add;

        check = check >= 10 ? 1 : 0; //두 문자열의 현재 원소값의 덧셈값이 10이상 일시 다음 시작값을 1로 결정함.
    }

    if (check == 1) //마지막 자리(문자열에선 인덱스0값)들의 덧셈이 10을 초과할경우 맨앞자리 1을 추가.
        add = '1' + add;

    return add;
}

void MakeAnswer()
{
    board[0][0] = "1";
    board[1][0] = "1";
    board[1][1] = "1";

    for (int i = 2; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
        {
            if (i == j || j == 0) //n,m값이 같거나 m값이 0이면 경우의 수는 1.
                board[i][j] = "1";
            else
                board[i][j] = AddStr(board[i - 1][j], board[i - 1][j - 1]);
        }

    cout << board[n][m] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}