#include <iostream.h>
#include <conio.h>
#include <string.h>


class MyStack
{
    int a[100];
    int top, m;
    public:

    MyStack(int max)
    {
	m=max;
	top=-1;
    }

    void push(int key)
    {
	a[++top]=key;
    }

    int pop()
    {
	return(a[top--]);
    }
};

class Evaluation
{
   public:
   int calculate(char s[]);
};

int Evaluation::calculate(char s[])
{
	 int n,r=0;
	 n=strlen(s);
	 MyStack a(n);
	 for(int i=0;i<n; i++)
	 {
	      char ch=s[i];
	      if(ch>='0'&& ch<='9')
		  a.push((int)(ch-'0'));
	      else
	      {
		     int x=a.pop();
		     int y=a.pop();
		     switch(ch)
		     {
			  case '+':r=x+y;
				   break;
			  case '-':r=y-x;
				   break;
			  case '*':r=x*y;
				   break;
			  case '/':r=y/x;
				   break;
			  default:r=0;
		     }
		     a.push(r);
	      }
	  }
	  r=a.pop();
	  return(r);
    }



void main()
{
	clrscr();
	Evaluation e;

	char input[99];
	while(1)
	{
	    cout<<"\nEnter the postfix expresion. To escape, enter the word'exit'."<<endl;
	    cin>>input;

	    if(strcmpi(input,"exit")==0)
		break;
	    cout<<"\nResult: "<<e.calculate(input)<<endl;
	}
}


