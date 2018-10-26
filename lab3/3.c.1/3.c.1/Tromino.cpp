#include<iostream>
#include<cmath>
using std::endl;
using std::cout;
using std::cin;

const int maxn = 1000;
int ans[maxn][maxn];//��������
int number = 0;//�Ƶĺ���

//sx(start x) sy(start y)���������̵Ŀ�ʼ����(Ҳ���������Ͻǵ�����)
//posx,posy ����ȱ�������
//size ��������
void tromino(int sx,int sy,int posx,int posy,int size)
{
	if (size == 1)return;//1*1�������� ����֮ǰ�Ѿ���������
	size /= 2;
	int c = number++;
	//����Ϊ�ĸ��ȴ��������
	//���Կ��� 1 2 3 4����

	//����1
	if (posx <= sx + size - 1 && posy <= sy + size - 1)//ȱ���ڵ�һ����
	{
		tromino(sx, sy, posx, posy, size);
	}
	else//���ڵ�һ���� ����ӹ��� �����ȱ���������
	{
		ans[sx + size - 1][sy + size - 1] = c;
		tromino(sx, sy, sx + size - 1, sy + size - 1, size);
	}

	//����2
	if (posx > sx + size - 1 && posy <= sy + size - 1)
	{
		tromino(sx + size, sy,posx, posy,size);
	}
	else
	{
		ans[sx + size][sy + size - 1] = c;//���½Ǳ��Ƹ���
		tromino(sx + size, sy, sx + size, sy + size - 1, size);
	}

	if(posx <= sx + size - 1 && posy > sy + size - 1)//����3
	{
		tromino(sx, sy + size, posx, posy, size);
	}
	else
	{
		ans[sx + size - 1][sy + size] = c;
		tromino(sx,sy + size , sx + size - 1, sy + size, size);
	}

	if(posx > sx + size - 1 && posy > sy + size - 1)
	{
		tromino(sx + size, sy + size, posx, posy, size);
	}
	else
	{
		ans[sx + size][sy + size] = c;
		tromino(sx + size, sy + size, sx + size, sy + size, size);
	}

}

void solve(int size, int x, int y)
{
	ans[x][y] = 0;
	number = 1;//initialize
	tromino(0, 0, x, y, size);
}


int main()
{
	int a;
	int x, y;
	while (true)
	{
		cout << "enter n :";
		cin >> a;
		int size = pow(2, a);
		cout << "enter the the coordinate : ";
		cin >> x >> y;
		if (x >= size || y >= size)
		{
			cout << "wrong input,try again\n";
			continue;
		}
		if (x < 0 || y < 0)
		{
			cout << "wrong input,try again\n";
			continue;
		}
		
		solve(size, x, y);

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				cout << ans[i][j] << " ";
			cout << endl;
		}
	}
}