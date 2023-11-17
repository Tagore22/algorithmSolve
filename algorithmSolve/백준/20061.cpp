#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 문제가 뭔가 어려운 개념은 아니나 복잡하고 귀찮으면 늘 삼성 문제였는데 이번에도 그랬다.
// 결과적으로는 테트리스 비슷한 구현이다. 다만 연한색 부분이 존재하며 2개의 테트리스를 구현해야 한다.
// 또한, 하나의 칸이 꽉차서 사라질때 계속 내려가지 않고 사라진 칸부터 아래로 떨어진다.
// 문제 자체도 복잡하다 보니 다시 설명하기가 어렵다. y, x가 뒤집혀 있는 파란 칸은 말그대로 y, x를 뒤집어서 계산한다.

// 자세한 설명은 주석으로 남긴다.

// 각 칸의 상태를 나타내는 bool 배열들.
bool b_check[6][4], g_check[6][4];
int N, t, y, x, answer = 0;

// 맨 마지막에 현재 존재하는 칸들의 수를 반환하는 함수.
int FindBlock()
{
    int ans = 0;
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 4; ++j)
        {
            if (b_check[i][j])
                ++ans;
            if (g_check[i][j])
                ++ans;
        }
    return ans;
}

// 꽉찬 칸들이 존재하는지 확인하고 지우는 함수.
void EraseBlock()
{
    // 연한칸 전까지 확인하여 지우고 그 이후 연한칸 확인.
    // for문의 마지막을 보면 알겠으나 특정 조건이 부합되지 않으면 다음수로 줄어들지 않는다.
    for (int i = 5; i >= 2;)
    {
        bool isFill = true;
        for (int j = 0; j < 4; ++j)
        {
            // 현재 칸들중 비어있는 곳이 있다면 체크하고 바로 탈출한다.
            if (!g_check[i][j])
            {
                isFill = false;
                break;
            }
        }

        // 현재 칸이 꽉차있다면
        if (isFill)
        {
            // 현재칸을 지우고 맨 위까지 한칸씩 아래로 내린다.
            for (int z = i; z >= 1; --z)
                for (int k = 0; k < 4; ++k)
                    g_check[z][k] = g_check[z - 1][k];
            // 점수를 1점 증가시킨다.
            ++answer;
            // 1칸이 사라졌기에 최소 1칸은 새로운 칸이 등장한다. 이칸은 전부 비어있어야 한다.
            for (int k = 0; k < 4; ++k)
                g_check[0][k] = false;
        }
        // 현재 칸이 꽉차있지 않다면 무시하고 다음칸으로 넘어간다.
        else
        {
            --i;
        }
    }
    // 연한부분을 확인한다.
    for (int i = 1; i > 0;)
    {
        bool isFill = false;
        for (int j = 0; j < 4; ++j)
        {
            // 연한색에서 한칸이라도 존재한다면 체크하고 탈출한다.
            if (g_check[i][j])
            {
                isFill = true;
                break;
            }
        }

        // 연한색에서 한칸이라도 존재한다면
        if (isFill)
        {
            // 맨 아래부터 1칸씩 아래로 당긴다.
            for (int z = 5; z >= 1; --z)
                for (int k = 0; k < 4; ++k)
                    g_check[z][k] = g_check[z - 1][k];
            // 마찬가지로 최소 1칸은 새로운 칸이 생겼으며 이 칸은 모두 비어있어야 한다.
            for (int k = 0; k < 4; ++k)
                g_check[0][k] = false;
        }
        // 존재하지 않는다면 무시한다.
        else
        {
            --i;
        }
    }

    // 파란칸
    for (int i = 5; i >= 2;)
    {
        bool isFill = true;
        for (int j = 0; j < 4; ++j)
        {
            if (!b_check[i][j])
            {
                isFill = false;
                break;
            }
        }

        if (isFill)
        {
            for (int z = i; z >= 1; --z)
                for (int k = 0; k < 4; ++k)
                    b_check[z][k] = b_check[z - 1][k];
            ++answer;
            for (int k = 0; k < 4; ++k)
                b_check[0][k] = false;
        }
        else
        {
            --i;
        }
    }
    for (int i = 1; i > 0;)
    {
        bool isFill = false;
        for (int j = 0; j < 4; ++j)
        {
            if (b_check[i][j])
            {
                isFill = true;
                break;
            }
        }

        if (isFill)
        {
            for (int z = 5; z >= 1; --z)
                for (int k = 0; k < 4; ++k)
                    b_check[z][k] = b_check[z - 1][k];
            for (int k = 0; k < 4; ++k)
                b_check[0][k] = false;
        }
        else
        {
            --i;
        }
    }
}

// 칸을 새로운 공간에 채우는 함수.
void FillBlock()
{
    if (t == 1)
    {
        // 초록칸.
        int here = 0;
        while (here <= 4 && !g_check[here + 1][x])
        {
            ++here;
        }
        g_check[here][x] = true;

        // 파란칸
        // 파란칸은 y, x가 뒤집혀서 계산해야한다.
        here = 0;
        while (here <= 4 && !b_check[here + 1][y])
        {
            ++here;
        }
        b_check[here][y] = true;

        // 사라지는 블록이 있는지 확인하고 있다면 없앤다.
        EraseBlock();
    }
    else if (t == 2)
    {
        // 초록칸.
        int here = 0;
        while (here <= 4 && !g_check[here + 1][x] && !g_check[here + 1][x + 1])
        {
            ++here;
        }
        g_check[here][x] = true;
        g_check[here][x + 1] = true;

        // 파란칸.
        here = 1;
        while (here <= 4 && !b_check[here + 1][y])
        {
            ++here;
        }
        b_check[here][y] = true;
        b_check[here - 1][y] = true;

        EraseBlock();
    }
    else
    {
        // 초록칸.
        int here = 1;
        while (here <= 4 && !g_check[here + 1][x])
        {
            ++here;
        }
        g_check[here][x] = true;
        g_check[here - 1][x] = true;

        // 파란칸.
        here = 0;
        while (here <= 4 && !b_check[here + 1][y] && !b_check[here + 1][y + 1])
        {
            ++here;
        }
        b_check[here][y] = true;
        b_check[here][y + 1] = true;

        EraseBlock();
    }
}

void MakeAnswer()
{
    memset(b_check, false, sizeof(b_check));
    memset(g_check, false, sizeof(g_check));
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> t >> y >> x;
        if (y < 0 || y >= 4 || x < 0 || x >= 4)
            continue;

        FillBlock();
    }

    cout << answer << '\n';
    cout << FindBlock() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}