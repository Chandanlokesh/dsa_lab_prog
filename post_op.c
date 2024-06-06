#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

double compute(char s,double op1,double op2)
{
	switch(s)
	{
		case '+':result(op1+op2);
		case '-':result(op1-op2);
		case '*':result(op1*op2);
		case '/':result(op1/op2);
		case '$':result(pow(op1,op2));
	}
}

void main()
{
	double res,op1,op2;
	double st[20];
	char sym,pos[20];
	int top,i,n;
	top=-1;
	printf("\n enter postfix expression");
	scanf("%s",pos);
	n=strlen(pos);
	for(i=0;i<n;i++){
		sym=pos[i];
		if(isdigit(sym)){
			st[++top]=sym-'0';
		}
		else
		{
			op2=st[top--];
			op1=st[top--];
			res=compute(sym,op1,op2);
			st[++top]=res;
		}	
	}
	res=st[top--];
	printf("\n result is %f",res);
	getch();
}