/*
 * assign7.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: Smita
 */
#include<iostream>
#include<ctype.h>
using namespace std;
#define max 40
class Stack
{
	char stack[max];
	int top;
public:
	void reverse(char str[]);
	char* remove_punction(char str[]);
	void palindrome(char str[]);
	void push(char a)
	{
		if(top==max-1)
		{
			cout<<"\n Stack is full";
		}
		else
		{
		top++;
		stack[top]=a;
		}
	}
	char pop()
	{
		char value;
		if(top==-1)
		{
			cout<<"\n Stack is empty";
			return '\0';
		}
		value=stack[top];
		top--;
		return value;
	}
	Stack()
	{
		top = -1;
		for(int i =0 ;i< max;i++)
		{
			stack[i]='\0';
		}
	}
};
char *Stack::remove_punction(char str[])
{
	char dst[max];
	char *p=dst;
	int i,j;
	i=0,j=0;
	while(str[i]!='\0')
	{
		if(ispunct((unsigned char)str[i])||str[i]==' ')
		{
			i++;
		}
		else if(isupper((unsigned char)str[i]))
		{
			dst[j]=tolower((unsigned char)str[i]);
			i++;
			j++;
		}
		else
		{
			dst[j]=str[i];
			j++;
			i++;
		}
	}
	dst[j]='\0';
	return p;
}
void Stack::reverse(char str[])
{
	int i;
	i=0;
	while(str[i]!='\0')
	{
		push(str[i]);
		i++;
	}
	cout<<"\n Reverse string is: ";
	while(top!=-1)
	{
		cout<<pop();
	}
}
void Stack::palindrome(char str[])
{
	int i,flag=0;
	i=0;
	while(str[i]!='\0')
	{
		push(str[i]);
		i++;
	}
	i=0;
	while(top!=-1)
	{
		char temp=pop();
		if(str[i]!=temp)
		{
			flag=1;
			break;
		}
		i++;
	}
	if(flag==1)
		cout<<"String is not palindrome";
	else
		cout<<"String is palindrome";
}
int main()
{
	char str[max];
	Stack s,s1,s2;
	int ch;
	char ans='y';
	setbuf(stdout,NULL);
	cout<<"\n Enter the string: ";
	gets(str);
	cout<<"The string is: "<<str;
	do
	{
		cout<<"\n 1. Check for palindrome";
		cout<<"\n 2. Check for palindrome after removing punctuation, spaces and converting uppercase to lowercase";
		cout<<"\n 3. Reverse String";
		cout<<"\n Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			s.palindrome(str);
			break;
		case 2:
			char *New=s1.remove_punction(str);
			s1.palindrome(New);
			break;
		case 3:
			s2.reverse(str);
			break;
		}
		cout<<"\n Do you want to continue: ";
		cin>>ans;
	}while(ans=='y');
	return 0;
}
