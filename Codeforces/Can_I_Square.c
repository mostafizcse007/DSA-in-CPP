#include <stdio.h>
#include <math.h>
int main()
{
    long long int test;
    scanf("%lld", &test);
    for (long long int i = 0; i < test; i++)
    {
        long long int bucket;
        scanf("%lld", &bucket);
        long long int arr[bucket];
        for (long long int j = 0; j < bucket; j++)
        {
            scanf("%lld", &arr[j]);
        }
        long long int count = 0;
        for (long long int j = 0; j < bucket; j++)
        {
            count += arr[j];
        }
        double root = sqrt(count);
        if (root - (long long int)root == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}