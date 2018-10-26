#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1 

#include<iostream>
#include<cmath>

using namespace std;

int a[1000][1000];//棋盘d
int c;//骨牌的号码

	  /* tr和tc是棋盘左上角的下标,dr和dc是特殊方格的下标,size是棋盘的大小 */
void Tromino(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)
		return;

	int t = c++;
	int s = size / 2;//划分棋盘

	//左上角
	if (dr < tr + s && dc < tc + s)
		Tromino(tr, tc, dr, dc, s);
	else
	{
		a[tr + s - 1][tc + s - 1] = t;
		Tromino(tr, tc, tr + s - 1, tc + s - 1, s);
	}

	//右上角
	if (dr < tr + s && dc >= tc + s)
		Tromino(tr, tc + s, dr, dc, s);
	else
	{
		a[tr + s - 1][tc + s] = t;
		Tromino(tr, tc + s, tr + s - 1, tc + s, s);
	}

	//左下角
	if (dr >= tr + s && dc < tc + s)
		Tromino(tr + s, tc, dr, dc, s);
	else
	{
		a[tr + s][tc + s - 1] = t;
		Tromino(tr + s, tc, tr + s, tc + s - 1, s);
	}

	//右下角
	if (dr >= tr + s && dc >= tc + s)
		Tromino(tr + s, tc + s, dr, dc, s);
	else
	{
		a[tr + s][tc + s] = t;
		Tromino(tr + s, tc + s, tr + s, tc + s, s);
	}
}

int main()
{
	int k;
	int x, y;
	printf("输入数据请自行保证k值大于等于1，下标不越界!!!\n");
	printf("请分别输入k值，特殊方格下标，输入3个0表示结束：\n");
	while (scanf("%d%d%d", &k, &x, &y) && (k || x || y))
	{
		//init
		c = 1;
		int num = pow(2, k);
		memset(a, 0, sizeof(a));

		Tromino(0, 0, x, y, num);

		//print
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
				printf("%-3d ", a[i][j]);
			printf("\n");
		}

		printf("\n");
	}

	return 0;
}
