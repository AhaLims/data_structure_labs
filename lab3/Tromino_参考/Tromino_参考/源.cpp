#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1 

#include<iostream>
#include<cmath>

using namespace std;

int a[1000][1000];//����d
int c;//���Ƶĺ���

	  /* tr��tc���������Ͻǵ��±�,dr��dc�����ⷽ����±�,size�����̵Ĵ�С */
void Tromino(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)
		return;

	int t = c++;
	int s = size / 2;//��������

	//���Ͻ�
	if (dr < tr + s && dc < tc + s)
		Tromino(tr, tc, dr, dc, s);
	else
	{
		a[tr + s - 1][tc + s - 1] = t;
		Tromino(tr, tc, tr + s - 1, tc + s - 1, s);
	}

	//���Ͻ�
	if (dr < tr + s && dc >= tc + s)
		Tromino(tr, tc + s, dr, dc, s);
	else
	{
		a[tr + s - 1][tc + s] = t;
		Tromino(tr, tc + s, tr + s - 1, tc + s, s);
	}

	//���½�
	if (dr >= tr + s && dc < tc + s)
		Tromino(tr + s, tc, dr, dc, s);
	else
	{
		a[tr + s][tc + s - 1] = t;
		Tromino(tr + s, tc, tr + s, tc + s - 1, s);
	}

	//���½�
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
	printf("�������������б�֤kֵ���ڵ���1���±겻Խ��!!!\n");
	printf("��ֱ�����kֵ�����ⷽ���±꣬����3��0��ʾ������\n");
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
