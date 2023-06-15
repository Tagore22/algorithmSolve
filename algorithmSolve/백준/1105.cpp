#include <iostream>

using namespace std;

// 풀이.
// 주어지는 수가 1 ~ 20억으로 단순히 1씩 증가하며 푸는 방법으로는 불가능했다.
// 그러면 조건을 이용한 그리디 문제일텐데 그 조건이 잘 생각나질 않았다.
// 결국 반례들을 찾아보며 풀었다.

// 자세한 설명은 주석으로 남긴다.

int L_array[10], R_array[10];
int L, R, L_num, R_num;

void MakeArray()
{
    L_num = -1;
    while (L >= 1)
    {
        ++L_num;
        L_array[L_num] = L % 10;
        L /= 10;
    }

    R_num = -1;
    while (R >= 1)
    {
        ++R_num;
        R_array[R_num] = R % 10;
        R /= 10;
    }
}

void MakeAnswer()
{
    // 1. L과 R이 같다면 8의 개수를 출력한다.
    // 2. 둘이 다르다면 
    // 2-1. 둘의 자리수가 같다면 마지막 자리부터 순회한다.
    // 2-1-1. 각 자리수가 같으면서 그 수가 8이라면 답이 1 증가한다.
    // 2-1-2. 각 자리수가 같지만 8이 아니라면 무시하고 넘어간다. << 이부분을 생각하지 못했었다.
    // 2-1-3. 각 자리수가 다르다면 반복문을 탈출한다.
    // 2-2. 둘의 자리수가 다르다면 0.
    int answer = 0;
    if (L == R)
    {
        while (L >= 1)
        {
            if (L % 10 == 8)
                ++answer;
            L /= 10;
        }
        cout << answer << '\n';
    }
    else
    {
        MakeArray();
        if (L_num == R_num)
        {
            for (int i = L_num; i >= 0; --i)
            {
                if (L_array[i] == R_array[i])
                {
                    if (L_array[i] == 8)
                        ++answer;
                }
                else
                {
                    break;
                }
            }

            cout << answer << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> R;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}