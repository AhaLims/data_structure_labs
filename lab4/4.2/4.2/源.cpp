#include<iostream>
#include<string>
using namespace std;
double alpha = 0.5;
struct Hashmap
{
	Hashmap()
	{
		index = -1;
		//iffree = true;
	}
	//bool iffree;//to mark whether the hash is free 
	int index;
};
class Hash
{
public:
	Hash(string *s, int size)//build hash
	{
		maxsize = size / alpha;
		m = size;
		hashmap = new Hashmap[maxsize];
		int index;
		for (int i = 0; i < m; i++)
		{
			index = hashfunction(s[i].at(0));
			//
			//while (hashmap[index].index == -1)
			//{
			//	index = d(index++);//?????
			//}
			int pos = index % m;
			for (int j = 0; hashmap[pos].index == -1 && j < maxsize; j++)
			{
				pos = (index + j) % m;
			}
			hashmap[pos].index = i;
		}
	}
	void search(char c)
	{
		int i = hashfunction(c);
	}
private:
	Hashmap * hashmap;
	int hashfunction(char c)//哈希函数
	{
		if(c >='a' && c <= 'z')
			return c - 'a';
		else return c - 'A';
	}
	int d(int i)
	{
		return i;//增量序列
	}
	int maxsize;
	int m;
};


int main()
{

}