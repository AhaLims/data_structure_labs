
//bigger is ahead

template<typename T>
void swap(T & a1, T & a2)
{
	T temp = a1;
	a1 = a2;
	a2 = temp;
}


template<typename T>
void BubbleSort(T * a, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}


