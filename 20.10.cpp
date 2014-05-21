

//use graph theory to solve this problem

/*
20.10 Given two words of equal length that are in a dictionary, write a method to transform one word into another word by changing only one letter at a time. The new word you get in each step must be in the dictionary.
EXAMPLE
*/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define tr(c,it) \
	for(typeof(c.begin()) it=c.begin();it!=c.end();++it)
	
typedef set<string>  Dict;



bool oneDiff(string s1,string s2)
{
	if(s1.size()!=s2.size())
		return false;
	unsigned cnt=0;
	for(unsigned i=0;i<s1.size();++i)
	{
		if(s1[i]==s2[i])
			++cnt;
		if(cnt<i) return false;    
	}
	return (cnt==s1.size()-1);
} //time O(d), d is average length of words

void transform(const Dict &dict, const string src, const string dst)
{	
	if(dict.count(src)==0 || dict.count(dst)==0 )
	{
		cout<<"src or dst not in dict\n"; return;
	}
	map<string,bool> visited;
	map<string,string> prev;
	stack<string> path;
	queue<string> qs;
	qs.push(src);
	tr(dict,it)
	{
		visited[*it]=false;
		prev[*it]="";
	}
	while(!qs.empty())
	{
		string next=qs.front();	qs.pop();
		if(next==dst)
		{
			path.push(next);
			while(prev[next]!="")
			{
				path.push(prev[next]);
				next=prev[next];
			}
			while(!path.empty())
			{
				if(path.size()>1)
					cout<<path.top()<<"->";
				else cout<<path.top();
				path.pop();
			}
			cout<<endl;
			return;
		}
		visited[next]=true;
		tr(dict,it)
		{
			if(oneDiff(next,*it) && !visited[*it])
			{
				qs.push(*it);
				visited[*it]=true;
				prev[*it]=next;
			}			
		}		
	}
	cout<<"no path found for transformation\n";
}//time O(E+v*d),space O(V)



int main()
{
	Dict dict;
	dict.insert("DAMP");   //DAMP -> LAMP -> LIMP -> LIME -> LIKE
	dict.insert("LAMP");
	dict.insert("LIMP");
	dict.insert("LIME");
	dict.insert("LIKE");
	dict.insert("LIMM");
	dict.insert("dfd");
	dict.insert("ddd");
	dict.insert("ddc");
	dict.insert("abc");
	
	transform(dict,"abc","ddc");
	
	return 0;
}






