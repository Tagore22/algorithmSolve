#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ������ ���� ����� ������ �ƴϳ� �����ϰ� �������� �� �Ｚ �������µ� �̹����� �׷���.
// ��������δ� ��Ʈ���� ����� �����̴�. �ٸ� ���ѻ� �κ��� �����ϸ� 2���� ��Ʈ������ �����ؾ� �Ѵ�.
// ����, �ϳ��� ĭ�� ������ ������� ��� �������� �ʰ� ����� ĭ���� �Ʒ��� ��������.
// ���� ��ü�� �����ϴ� ���� �ٽ� �����ϱⰡ ��ƴ�. y, x�� ������ �ִ� �Ķ� ĭ�� ���״�� y, x�� ����� ����Ѵ�.

// �ڼ��� ������ �ּ����� �����.

// �� ĭ�� ���¸� ��Ÿ���� bool �迭��.
bool b_check[6][4], g_check[6][4];
int N, t, y, x, answer = 0;

// �� �������� ���� �����ϴ� ĭ���� ���� ��ȯ�ϴ� �Լ�.
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

// ���� ĭ���� �����ϴ��� Ȯ���ϰ� ����� �Լ�.
void EraseBlock()
{
    // ����ĭ ������ Ȯ���Ͽ� ����� �� ���� ����ĭ Ȯ��.
    // for���� �������� ���� �˰����� Ư�� ������ ���յ��� ������ �������� �پ���� �ʴ´�.
    for (int i = 5; i >= 2;)
    {
        bool isFill = true;
        for (int j = 0; j < 4; ++j)
        {
            // ���� ĭ���� ����ִ� ���� �ִٸ� üũ�ϰ� �ٷ� Ż���Ѵ�.
            if (!g_check[i][j])
            {
                isFill = false;
                break;
            }
        }

        // ���� ĭ�� �����ִٸ�
        if (isFill)
        {
            // ����ĭ�� ����� �� ������ ��ĭ�� �Ʒ��� ������.
            for (int z = i; z >= 1; --z)
                for (int k = 0; k < 4; ++k)
                    g_check[z][k] = g_check[z - 1][k];
            // ������ 1�� ������Ų��.
            ++answer;
            // 1ĭ�� ������⿡ �ּ� 1ĭ�� ���ο� ĭ�� �����Ѵ�. ��ĭ�� ���� ����־�� �Ѵ�.
            for (int k = 0; k < 4; ++k)
                g_check[0][k] = false;
        }
        // ���� ĭ�� �������� �ʴٸ� �����ϰ� ����ĭ���� �Ѿ��.
        else
        {
            --i;
        }
    }
    // ���Ѻκ��� Ȯ���Ѵ�.
    for (int i = 1; i > 0;)
    {
        bool isFill = false;
        for (int j = 0; j < 4; ++j)
        {
            // ���ѻ����� ��ĭ�̶� �����Ѵٸ� üũ�ϰ� Ż���Ѵ�.
            if (g_check[i][j])
            {
                isFill = true;
                break;
            }
        }

        // ���ѻ����� ��ĭ�̶� �����Ѵٸ�
        if (isFill)
        {
            // �� �Ʒ����� 1ĭ�� �Ʒ��� ����.
            for (int z = 5; z >= 1; --z)
                for (int k = 0; k < 4; ++k)
                    g_check[z][k] = g_check[z - 1][k];
            // ���������� �ּ� 1ĭ�� ���ο� ĭ�� �������� �� ĭ�� ��� ����־�� �Ѵ�.
            for (int k = 0; k < 4; ++k)
                g_check[0][k] = false;
        }
        // �������� �ʴ´ٸ� �����Ѵ�.
        else
        {
            --i;
        }
    }

    // �Ķ�ĭ
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

// ĭ�� ���ο� ������ ä��� �Լ�.
void FillBlock()
{
    if (t == 1)
    {
        // �ʷ�ĭ.
        int here = 0;
        while (here <= 4 && !g_check[here + 1][x])
        {
            ++here;
        }
        g_check[here][x] = true;

        // �Ķ�ĭ
        // �Ķ�ĭ�� y, x�� �������� ����ؾ��Ѵ�.
        here = 0;
        while (here <= 4 && !b_check[here + 1][y])
        {
            ++here;
        }
        b_check[here][y] = true;

        // ������� ����� �ִ��� Ȯ���ϰ� �ִٸ� ���ش�.
        EraseBlock();
    }
    else if (t == 2)
    {
        // �ʷ�ĭ.
        int here = 0;
        while (here <= 4 && !g_check[here + 1][x] && !g_check[here + 1][x + 1])
        {
            ++here;
        }
        g_check[here][x] = true;
        g_check[here][x + 1] = true;

        // �Ķ�ĭ.
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
        // �ʷ�ĭ.
        int here = 1;
        while (here <= 4 && !g_check[here + 1][x])
        {
            ++here;
        }
        g_check[here][x] = true;
        g_check[here - 1][x] = true;

        // �Ķ�ĭ.
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