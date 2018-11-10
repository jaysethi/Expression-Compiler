#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

class IN_To_POST
{
	 char stack[100];
	 int top;

	 public:
	 IN_To_POST()
	 {
		  top=-1;
	 }

	 void push(char item)
	 {
		  if(top >99)
				cout<<"\nStack Overflow.";
		  else
				stack[++top] = item;
	 }

	 char pop()
	 {
		  char item ;

		  if(top <0)
		  {
				cout<<"stack under flow: invalid infix expression";
				return ' ';
		  }
		  else
		  {
				item = stack[top--];
				return item;
		  }
	 }

	 int is_operator(char symbol)
	 {
		  if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '%' || symbol == '+' || symbol =='-')
				return 1;
		  else
				return 0;
	 }

	 int precedence(char symbol)
	 {
		  if(symbol == '^')/* exponent operator, highest precedence*/
		  {
				return(3);
		  }
		  else if(symbol == '*' || symbol == '/' || symbol=='%')
		  {
				return(2);
		  }
		  else if(symbol == '+' || symbol == '-')          /* lowest precedence */
		  {
				return(1);
		  }
		  else
		  {
				return(0);
		  }
	 }
	 void InfixToPostfix(char infix_exp[], char postfix_exp[]);
};

	 void IN_To_POST::InfixToPostfix(char infix_exp[], char postfix_exp[])
	 {
		  int i, j;
		  char item;
		  char x;

		  i=0;
		  j=0;
		  item=infix_exp[i];         /* initialize before loop*/

		  while(item != '\0')        /* run loop till end of infix expression */
		  {
				if(item == '(')
				{
					 push(item);
				}
				else if(isalnum(item))
				{
					 postfix_exp[j] = item;				 /* add operand symbol to postfix expr */
					 j++;
				}
				else if(is_operator(item) == 1)        /* means symbol is operator */
				{
					 x=pop();
					 while(is_operator(x) == 1 && precedence(x)>= precedence(item))
					 {
						  postfix_exp[j] = x;                  /* so pop all higher precendence operator and */
						  j++;
						  x = pop();                       /* add them to postfix expresion */
					 }
					 push(x);
					 /* because just above while loop will terminate we have
					 oppped one extra item
					 for which condition fails and loop terminates, so that one*/

					 push(item);                 /* push current oprerator symbol onto stack */
				}
				else if(item == ')')         /* if current symbol is ')' then */
				{
					 x = pop();                   /* pop and keep popping until */
					 while(x != '(')                /* '(' encounterd */
					 {
						  postfix_exp[j] = x;
						  j++;
						  x = pop();
					 }
				}
				else
				{ /* if current symbol is neither operand not '(' nor ')' and nor
					 operator */
					 cout<<"\nInvalid infix Expression.\n";        /* the it is illegeal  symbol */
					 return;
				}
				i++;

				item = infix_exp[i]; /* go to next symbol of infix expression */
		  } /* while loop ends here */
		  if(top>0)
		  {
				cout<<"\nInvalid infix Expression.\n";        /* the it is illegeal  symbol */
				return;
		  }
	 }

	 /* main function begins */
	 void main()
	 {
		  char temp[100],infix[100], postfix[100];         /* declare infix string and postfix string */
		  int i;
		  IN_To_POST ip;
		  /* why we asked the user to enter infix expression
			* in parentheses ( )
			* What changes are required in porgram to
			* get rid of this restriction since it is not
			* in algorithm
			* */
		  cout<<"ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n";
		  cout<<"\nEnter Infix expression : ";
		  cin>>temp;
		  strcpy(infix,"(");
		  strcat(infix,temp);
		  strcat(infix,")");

		  ip.InfixToPostfix(infix,postfix);                   /* call to convert */
		  cout<<"Postfix Expression: "<<postfix<<endl;                     /* print postfix expression */
		  getch();
	 }
	 /*Output

	 First Run:
	 Enter Infix expression : A+(B*C-(D/E^F)*G)*H
	 Postfix Expression: ABC*DEF^/G*-H*+
	  */
