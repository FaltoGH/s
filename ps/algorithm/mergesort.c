typedef INPUT_YOUR_TYPE_HERE sortType;
sortType __aux[INPUT_YOUR_N_MAX_HERE];

int compare(sortType *x, sortType *y)
{
	if ((x->coord) < (y->coord))
	{
		return -1;
	}
	if ((x->coord) > (y->coord))
	{
		return 1;
	}
	return 0;
}

void swap(sortType *x, sortType *y)
{
	sortType tmp = *x;
	*x = *y;
	*y = tmp;
}

void mergeSort(sortType *arr, int begin, int end)
{
	if (begin + 1 >= end)
		return;
	if (begin < 0)
		return;

	if (begin + 2 == end)
	{
		if (compare(arr + begin, arr + begin + 1) > 0)
		{
			swap(arr + begin, arr + begin + 1);
		}
		return;
	}

	int mid = (begin + end) >> 1;
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid, end);

	int i;
	int j1 = begin;
	int j2 = mid;
	for (i = begin; i < end; i++)
	{
		if (j1 >= mid)
		{
			__aux[i] = arr[j2];
			j2++;
		}
		else if (j2 >= end)
		{
			__aux[i] = arr[j1];
			j1++;
		}
		else if (compare(arr + j1, arr + j2) <= 0)
		{
			__aux[i] = arr[j1];
			j1++;
		}
		else
		{
			__aux[i] = arr[j2];
			j2++;
		}
	}

	for (i = begin; i < end; i++)
	{
		arr[i] = __aux[i];
	}
}
