#include<iostream>
#include<string>
using namespace std;
class Gapbuffer
{
	char *buffer;
	int size;
	int gapsize;
	int gapl,gapr;
	public:
		Gapbuffer();
		Gapbuffer(int);
		void grow(int,int=10);
		void left(int);
		void right(int);
		void cursor(int);
		void insert(string,int=0);
		string input(string);         
};
Gapbuffer::Gapbuffer()
{
	buffer=new char[50];
	size=10;
	gapsize=10;
	gapl=0;
	gapr=9;
}
Gapbuffer::Gapbuffer(int s)
{
	buffer=new char[s];
	size=s;
	gapsize=10;
	gapl=0;
	gapr=gapsize-gapl-1;
}
void Gapbuffer::grow(int pos,int x)
{
	char arr[size];
	int i;
	for(i=pos;i<size;i++)
	{
		arr[i-pos]=buffer[i];
	}
	for(i=0;i<x;i++)
	{
		buffer[i+pos]='_';
	}
	for(i=0;i<pos+x;i++)
	{
		buffer[pos+x+i]=arr[i];
	}
	gapr+=x;
	size+=x;
}
void Gapbuffer::left(int pos)
{
	 while (pos<gapl)
	 {  
        gapl--;  
        gapr--;  
        buffer[gapr+1]=buffer[gapl]; 
        buffer[gapl]='_'; 
    }  
}
void Gapbuffer::right(int pos)  
{    
    while (pos>gapl)
	{  
        gapl++;  
        gapr++;  
        buffer[gapl-1] = buffer[gapr];  
        buffer[gapr]='_'; 
    }  
}  
void Gapbuffer::cursor(int pos)  
{  
    if (pos<gapl)
	{  
        left(pos);  
    }  
    else
	{  
        right(pos);  
    }  
}  
void Gapbuffer::insert(string str,int pos)
{
	int len=str.length();
	int i=0;
	if(pos!=gapl)
	{
		cursor(pos);
	}
	while(i<len)
	{
		if(gapl==gapr)
		{
			grow(pos);
		}
		buffer[gapl] = str[i];  
        gapl++;  
        i++;  
        pos++; 
	}
}
string Gapbuffer::input(string str)
{
	int i;
	for (i = 0; i<str.length(); i++)
	 {  
        buffer[i] = '_';  
     }
     insert(str);
     string str1;
     int pos1;
     cout<<"enter the position:"<<" ";
     cin>>pos1;
     cout<<"enter the string to insert:"<<" ";
     cin>>str1;
     insert(str1,pos1);
       string a="";
    for (int i = 0; i <size; i++) {
		if(buffer[i]!='_')
		{  
        a+=buffer[i];
		}
 }
	return a;  
}

