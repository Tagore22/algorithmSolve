#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> price;
vector<string> cashe;

string CompareStr(const string& str1, const string& str2)
{
    if (str1.size() == 0)
        return str2;
    else if (str2.size() == 0)
        return str1;
    if (str1[0] == '0')
        return str2;
    else if (str2[0] == '0')
        return str1;
    if (str1.size() > str2.size())
        return str1;
    else if (str2.size() > str1.size())
        return str2;
    else
        return str1 > str2 ? str1 : str2;
}

string CalculDP(int money)
{
    string& ans = cashe[money];
    if (ans != "")
        return ans;

    for (int i = 0; i < N; ++i)
        if (money >= price[i])
            ans = CompareStr(ans, CalculDP(money - price[i]) + static_cast<char>(i + '0'));
    if (ans[0] == '0') //출력이 "00"처럼 모두 0일때를 생각하지 못해 오래걸렸다 T^T
        ans = "0";
    return ans;
}

void ShowAnswer()
{
    cashe.assign(M + 1, "");
    CalculDP(M);
    cout << cashe[M] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    price.assign(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> price[i];
    cin >> M;
    ShowAnswer();
    return 0;
}