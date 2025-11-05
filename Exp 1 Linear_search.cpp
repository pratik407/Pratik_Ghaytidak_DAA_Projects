#include<stdio.h>
void main()
{
int a[10],i,key,n,flag=0;
printf("\nEnter size of array:");
scanf("%d",&n);
printf("\nEnter array elements are:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("\nEnter key element to be search:");
scanf("%d",&key);
for(i=0;i<n;i++)
{
IF(key==a[i])
{
flag=1;
break;
}
}
if(flag==1)
{
printf("\n Element is found");
}
else
{
printf("\n Element is not found");
}
}
