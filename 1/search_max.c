int search (int arr[], int n)
{
int i;
int max = arr[0];
for (i=1;i<n;i++)
{
 if (arr[i] > max)
 max = arr[i];
}
printf ("Inside function, max = %d",max);
return max;
}
