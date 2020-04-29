#define MULT(A,B)A*B
#define N 5

main()
{
 int i=0;
 int a;

 printf("%d\n", MULT(1+2, 3));
 printf("%d\n", MULT(1+2, 3+4));

 i=i+5;
 for(i=0;i<N;i=i+1)
     printf("i",i);

 i=1;
 while(i<5)
     printf("i",i++);
 a=0xdeadbeef;

 i=5;
}