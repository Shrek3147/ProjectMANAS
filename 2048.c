
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int i,j,a[5][5]={};/*2 Dimensional array a[5][5] For all 0*/
void ka()/* Generate start interface */
{
  printf("Welcome to 2048\n");
  printf(" press 1 for a new game \n");

}
int defen(int a[][5])/* The scoring function */
{
  int max=a[0][0];
  int static sum=0;
  for(i=0;i<5;i++)
    for(j=0;j<5;j++)
      if(a[i][j]>max)
        max=a[i][j];
  sum+=max;
  return sum;/* Take the sum of the largest number as the score */
}
void gen(int a[][5])
{
  int b[2]={2,4},c[5]={0,1,2,3,4},sum,n,m;
  do
  {
    srand((int)time(NULL));/* Take time as a random number seed */
    m=c[rand()%5];
    n=c[rand()%5];
    /* Randomly generated coordinates */
    if(a[m][n]==0)/* Determines whether it is a space */
    {
      a[m][n]=b[rand()%2];/* Randomly generated 2 or 4*/
      break;/* Jump out of the loop */
    }
  }while(1);
  printf("%d %d %d\n",m,n,a[m][n]);
  for(i=0;i<5;i++)
  {
    printf("-------------------------\n");
    for(j=0;j<5;j++)
      {
        if((m==i)&&(n==j))
          printf("| %d ",a[m][n]);/* The output is randomly generated 2 or 4*/
        else
        {
          if(a[i][j]>0)
            printf("| %d ",a[i][j]);/* if a[i][j] If there are Numbers, output them */
          else
            printf("|   ");/* if a[i][j] No Numbers, output Spaces */
        }
      }
    printf("|\n");
  }
    printf("-------------------------\n");
    printf("      score :%d\n",sum=defen(a));
}
void hebingup(int a[][5])/* Up to merge */
{
  int m;
  for(j=0;j<5;j++)
    for(i=0;i<4;i++)
      if(a[i][j]>0)/* if a[i][j] Don't for 0 Judge, otherwise jump straight down 1 item */
        if(a[i][j]==a[i+1][j]&&a[i][j]!=0)/* To determine whether two adjacent terms are equal */
        {
          a[i][j]=2*a[i][j];/* The above 1 This term is going to double */
          if(i==2)
            a[i+1][j]=0;
          else
            for(m=i+1;m<3;m++)
            {
              a[m][j]=a[m+1][j];
              a[m+1][j]=0;
            }
          /* Move the following Numbers up as a whole and recycle */
        }
}
void hebingdown(int a[][5])/* Merge down */
{
  int m;
  for(j=0;j<5;j++)
    for(i=4;i>0;i--)
      if(a[i][j]>0)
        if(a[i][j]==a[i-1][j])
        {
          a[i][j]=2*a[i][j];
          if(i==1)
            a[i-1][j]=0;
          else
            for(m=i-1;m>0;m--)
            {
              a[m][j]=a[m-1][j];
              a[m-1][j]=0;
            }
        }
}
void hebingleft(int a[][5])/* To the left to merge */
{
  int m;
  for(i=0;i<5;i++)
    for(j=0;j<4;j++)
      if(a[i][j]>0)
        if(a[i][j]==a[i][j+1])
        {
          a[i][j]=2*a[i][j];
          if(j==2)
            a[i][j+1]=0;
          else
            for(m=j+1;m<4;m++)
            {
              a[i][m]=a[i][m+1];
              a[i][m+1]=0;
            }
        }
}
void hebingright(int a[][5])/* Merge to the right */
{
  int m;
  for(i=0;i<5;i++)
    for(j=4;j>0;j--)
      if(a[i][j]>0)
        if(a[i][j]==a[i][j-1])
        {
          a[i][j]=2*a[i][j];
          if(j==1)
            a[i][j-1]=0;
          else
            for(m=j-1;m>0;m--)
            {
              a[i][m]=a[i][m-1];
              a[i][m-1]=0;
            }
        }
}
void yidong(char b)
{
  int x,m;
  switch(b)
  {
    case 'w' :
      for(j=0;j<5;j++)
        for(i=1;i<=4;i++)
          for(x=i,m=i;x>0;x--,m--)/*x Is the number of cycles, m alternative i Keep the cycle going */
          {
            if(a[m-1][j]>0)
              break;/* If the 1 A non 0 And jump down 1 position */
            else
            {
              a[m-1][j]=a[m][j];
              a[m][j]=0;
            }
          }
      hebingup(a);
      break;
    case 's' :
      for(j=0;j<5;j++)
        for(i=3;i>=0;i--)
          for(x=4-i,m=i;x>0;x--,m++)
          {
            if(a[m+1][j]>0)
              break;
            else
            {
              a[m+1][j]=a[m][j];
              a[m][j]=0;
            }
          }
      hebingdown(a);
      break;
    case 'a' :
      for(i=0;i<5;i++)
        for(j=1;j<=4;j++)
          for(x=j,m=j;x>0;x--,m--)
          {
            if(a[i][m-1]>0)
              break;
            else
            {
              a[i][m-1]=a[i][m];
              a[i][m]=0;
            }
          }
      hebingleft(a);
      break;
    case 'd' :
      for(i=0;i<5;i++)
        for(j=3;j>=0;j--)
          for(x=4-j,m=j;x>0;x--,m++)
          {
            if(a[i][m+1]>0)
              break;
            else
            {
              a[i][m+1]=a[i][m];
              a[i][m]=0;
            }
          }
      hebingright(a);
      break;
  }
}
int main(int argc,char *argv[])
{
  int flag=1;
  char c,k;
  
outloop:;
  ka();
  k=getchar();
  printf("\n");
  if(k=='1')
  {
    while(flag==1)
    {
      gen(a);
      c=getchar();
      printf("\n");
      yidong(c);
      for(i=0;i<5;i++)
        for(j=0;j<5;j++)
        {
          if(a[i][j]==0)
          {
            flag=1;
            goto end;/* If you have a checkerboard 1 Jump out of the judgment and continue to generate random Numbers */
          }
          else
            flag=0;
        }
       end:;
    }
  }
  if(k=='2')
  {
    do
    {
      printf("  <w>,<s>,<a>,<d> Key to move the Numbers up, down, left and right.  \n");
      printf("  3). return \n");
      k=getchar();
    }while(k!=3);
    goto outloop;/* Jump to the start screen */
  }
  printf("      Game over \n");
  return 0;
}
