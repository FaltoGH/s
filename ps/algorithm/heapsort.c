#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct _person
{
    int age, height, weight;
} person;

//-----BEGIN HEAPSORT-----
typedef person sortT;

int compare(sortT *x, sortT *y)
{
    int xs = (x->height);
    int ys = (y->height);
    if (xs < ys)
    {
        return -1;
    }
    if (xs > ys)
    {
        return 1;
    }
    return 0;
}

void swap(sortT *x, sortT *y)
{
    sortT tmp = *x;
    *x = *y;
    *y = tmp;
}

void siftDown(sortT *arr, int root, int count)
{
    while (1)
    {
        int child = (root << 1) + 1;
        if (child >= count)
        {
            return;
        }

        if ((child + 1) < count)
        {
            if (compare(arr + child, arr + child + 1) < 0)
            {
                child++;
            }
        }

        if (compare(arr + root, arr + child) < 0)
        {
            swap(arr + root, arr + child);
            root = child;
        }
        else
        {
            return;
        }
    }
}

void heapsort(sortT *arr, int count)
{
    int i;
    for (i = count - 1; i >= 0; i--)
    {
        siftDown(arr, i, count);
    }
    for (i = count - 1; i >= 0; i--)
    {
        swap(arr, arr + i);
        siftDown(arr, 0, i);
    }
}
//-----END HEAPSORT-----

bool isSorted(sortT *arr, int count)
{
    int i;
    int end = count - 1;
    for (i = 0; i < end; i++)
    {
        int result = compare(arr + i, arr + i + 1);
        if (result > 0)
        {
            return false;
        }
    }
    return true;
}

bool test(int count)
{
    person *arr = malloc(sizeof(person) * count);
    int i;
    for (i = 0; i < count; i++)
    {
        arr[i].age = rand();
        arr[i].height = rand() % 255;
        arr[i].weight = rand();
    }

    if (count < 10)
    {
        for (i = 0; i < count; i++)
        {
            printf("%3d ", arr[i].height);
        }
        puts("");
    }

    heapsort(arr, count);

    if (count < 10)
    {
        for (i = 0; i < count; i++)
        {
            printf("%3d ", arr[i].height);
        }
        puts("");
    }

    bool result = isSorted(arr, count);

    free(arr);

    return result;
}

int main()
{
    srand(time(NULL));

    int testargs[7] = {1, 2, 3, 4, 8, 16, 100000};
    int i;
    for (i = 0; i < 7; i++)
    {
        bool result = test(testargs[i]);
        if (!result)
        {
            fprintf(stderr, "Something went wrong!");
            return 0;
        }
    }

    puts("Everything is OK!!");
    return 0;
}
