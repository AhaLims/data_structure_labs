#include<iostream>
#include<cmath>
using std::endl;
using std::cout;
using std::cin;

const int maxn = 1000;
int ans[maxn][maxn];//棋盘数组
int number = 0;//牌的号码

//sx(start x) sy(start y)代表子棋盘的开始坐标(也就是最左上角的坐标)
//posx,posy 代表缺块的坐标
//size 棋盘坐标
void tromino(int sx,int sy,int posx,int posy,int size)
{
	if (size == 1)return;//1*1的子棋盘 且在之前已经被覆盖了
	size /= 2;
	int c = number++;
	//划分为四个等大的子棋盘
	//可以看作 1 2 3 4象限

	//象限1
	if (posx <= sx + size - 1 && posy <= sy + size - 1)//缺块在第一象限
	{
		tromino(sx, sy, posx, posy, size);
	}
	else//不在第一象限 则添加骨牌 构造成缺块的子棋盘
	{
		ans[sx + size - 1][sy + size - 1] = c;
		tromino(sx, sy, sx + size - 1, sy + size - 1, size);
	}

	//象限2
	if (posx > sx + size - 1 && posy <= sy + size - 1)
	{
		tromino(sx + size, sy,posx, posy,size);
	}
	else
	{
		ans[sx + size][sy + size - 1] = c;//左下角被牌覆盖
		tromino(sx + size, sy, sx + size, sy + size - 1, size);
	}

	if(posx <= sx + size - 1 && posy > sy + size - 1)//象限3
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