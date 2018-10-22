
//bigger is ahead
template<typename T>
void swap(T & a1, T & a2)
{
	T temp = a1;
	a1 = a2;
	a2 = temp;
}


template<typename T>
void InsertSort(T * a, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount; j++)
		{
			if (a[j] < a[i])swap(a[j], a[i]);
		}
	}
}


