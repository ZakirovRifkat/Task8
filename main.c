#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void puzirek(int a[],int N)
{
    int i,j,b,srav=0,perest=0;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N-i-1;j++)
        {   srav=srav+1;
            if(a[j]>a[j+1])
            {
                b=a[j];
                a[j]=a[j+1];
                a[j+1]=b;
                perest=perest+1;
            }
        }
    }
    printf("количество перестановок %d\n",perest);
    printf("количество сравнений %d\n",srav);


}
void QuickSort(int array[],int start,int end,int *nif,int *nswap)
{
 int index=start,i,pivot=array[end],temp;
 if(start<end)
 {
  for(i=start;i<end;i++)
  { *nif=*nif+1;
   if(array[i]<=pivot)
   {
    temp=array[i];
    array[i]=array[index];
    array[index]=temp;
    index++;
    *nswap=*nswap+1;
   }
  }
  temp=array[index];
  array[index]=array[end];
  array[end]=temp;
  QuickSort(array,start,index-1,&*nif,&*nswap);
  QuickSort(array,index+1,end,&*nif,&*nswap);
 }
}








int main()
{
int v=-1,*t,q,*arr,first,last,n;
setlocale(LC_ALL,"RUS");
printf("1-Сортировка пузырьком\n");
printf("2- Quicksort-быстрая сортировка\n");
printf("|Для выхода введите 0|");
printf("\n\n");
while(v!=0)
{
    printf("Выберите номер задания:");
    scanf("%d",&v);
    switch(v)
    {
    case 1:
        printf("\nВведите количество элементов в массиве:");
	    scanf("%d", &q);
	    if(q<=0) printf("В массиве нет элементов\n\n");
	    else
        {
	    t = (int*)malloc(q * sizeof(int));
	    printf("Введите элементы массива\n");
	    for (int i = 0; i < q; i++)
        {
            scanf("%d", &t[i]);
        }
        puzirek(t,q);
        printf("Массив отсортирован и имеет вид:");
        for(int i=0;i<q;i++)
        {
            printf(" %d ",t[i]);
        }
        printf("\n\n");
        }
        break;

    case 2:
        printf("Введите кол-во элементов массива\n");
        scanf("%d", &n);
        arr = (int*) malloc(n*sizeof(int));
        printf("Введите элементы массива\n");
        for (int i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int nif,nswap;
        QuickSort(arr,0,n-1,&nif,&nswap);
        printf("Кол-во перестановок: %d\n", nswap);
        printf("Кол-во сравнений: %d\n", nif);
        printf("Массив после сортировки:");
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n\n");
        break;
    }
}
return 0;
}
