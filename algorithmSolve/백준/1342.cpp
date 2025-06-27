#include <iostream>

using namespace std;

// 풀이.
// 1342번의 첫번째 풀이. 직접 모든 행운의 문자열을 만들어 그 수를 파악한다.
// 다만 문자열을 만드는 과정이 STL의 next_permutation()보다 비효율적이기 때문에
// 가독성으로 보나 속도로 보나 이 다음 코드가 더 낫다.

string str, cur = "";
bool visit[10] = { false, };
int ssize, answer = 0;

bool IsLuckyStr(string cur)
{
    for (int i = 0; i < cur.size() - 1; ++i)
        if (cur[i] == cur[i + 1])
            return false;
    return true;
}

void MakeString(int idx)
{
    if (cur.size() == ssize && IsLuckyStr(cur))
    {
        ++answer;
        return;
    }

    bool isuse[26] = { false, };

    for (int i = 0; i < ssize; ++i)
    {
        if (!visit[i] && !isuse[str[i] - 'a'])
        {
            visit[i] = true;
            cur += str[i];
            isuse[str[i] - 'a'] = true;
            MakeString(idx + 1);
            cur.erase(cur.size() - 1, 1);
            visit[i] = false;
        }
    }
}


int main()
{
    cin >> str;
    ssize = str.size();
    MakeString(0);
    cout << answer << '\n';
    return 0;
}