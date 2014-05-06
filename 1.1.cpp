
/*1.1 Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?*/


#include <iostream>

using namespace std;


bool unique1(string s)
{
	int a[8];  //ASCII 256=32*8
	memset(a,0,sizeof(int)*8);
	
	int len=s.size();
	for(int i=0;i<len;++i)
	{
		int v=(int)s[i];
		int v1=v/32;
		int v2=1<<(v%32);
		if( (a[v1] & v2) ==0)		
			a[v1] |=v2;			
		else{
			cout<<"unique1: string is not unique"<<endl;
			return false;
		}			
	}
	cout<<"unique1: string is unique"<<endl;
	return true;
}//time O(n), space O(1)


/*
int unique1(char ca[],int len)
{
	bool char_set[256];
	memset(char_set,false,sizeof(bool)*256);
	
	for(int i=0;i<len;++i)
		if(char_set[(int)ca[i]]==false)
			char_set[(int)ca[i]]=true;
		else{
			cout<<"unique1: string is not unique"<<endl;
			return false;
		}
		
	cout<<"unique1: string is unique"<<endl;
	return 1;
}//time O(n), space O(1)
*/

void swap(char ca[],int i,int j)
{
	if(i!=j)
	{
		char tmp=ca[i];
		ca[i]=ca[j];
		ca[j]=tmp;
	}
}


void qsort(char ca[],int left,int right)
{
	if(left>=right)
		return;
	
	int last=left;
	swap(ca,left,(left+right)/2);
	for(int i=left+1;i<=right;++i)
		if(ca[i]<ca[left])
			swap(ca,++last,i);
	swap(ca,left,last);
	qsort(ca,left,last-1);
	qsort(ca,last+1,right);

}

int unique2(char ca[],int len)
{
	cout<<"Before sorting: ";
	for(int i=0;i<len;++i)
		cout<<ca[i];
	cout<<endl;
	qsort(ca,0,len-1);
	cout<<"After sorting: ";
	for(int i=0;i<len;++i)
		cout<<ca[i];
	cout<<endl;
	
	for(int i=0;i<len-1;++i)
		if(ca[i]==ca[i+1])	
		{
			cout<<"unique2: string is not unique"<<endl;
			return 0;
		}
	cout<<"unique2: string is unique"<<endl;
	return 1;
}//time O(nlogn+n), space O(logn)


int main()
{
	//char ca[]="3kdfj";
	char ca[]="9a3kzd4f1aj";
	int len=sizeof(ca)/sizeof(*ca)-1;//including '\0' at last 
	
	string s=ca;
	
	cout<<unique1(s)<<endl;
	
	cout<<unique2(ca,len)<<endl;
	
	
	return 0;
}



