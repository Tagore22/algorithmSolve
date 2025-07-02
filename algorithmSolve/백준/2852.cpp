#include <iostream>
#include <string>

using namespace std;

int point[2] = { 0, }, answer[2] = { 0, }, cur[2] = { 0, };
int N, winning = 0;

int StringToInt(string str)
{
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
}

string IntToString(int num)
{
    string str = to_string(num / 60) + ':' + to_string(num % 60);
    if (str[1] == ':')
        str = '0' + str;
    if (str[str.size() - 2] == ':')
        str = str.substr(0, 3) + '0' + str.substr(3, 1);
    return str;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int iter = 0; iter < N; ++iter)
    {
        int num;
        string str;
        cin >> num >> str;
        --num;
        ++point[num];

        int other = (num + 1) % 2;
        int now = StringToInt(str);
        if (point[num] == point[other] + 1)
        {
            winning = num;
            cur[num] = now;
        }
        else if (point[num] == point[other])
        {
            winning = -1;
            answer[other] += now - cur[other];
        }
    }
    if (winning != -1)
        answer[winning] += 2880 - cur[winning];
    cout << IntToString(answer[0]) << '\n';
    cout << IntToString(answer[1]) << '\n';
    return 0;
}