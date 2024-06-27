#include<iostream>
using namespace std;

	bool isVowel(char ch){
		ch=tolower(ch);
		return(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
	}
	bool isAlphabet(char ch){
		return(ch>='a'&& ch<='z')||(ch>='A'&& ch<='Z');
	
	}
	int main()
	{
		char ch;
		cout<<"Enter a character";
		cin>>ch;
		if(!isAlphabet(ch)){
			cout<<ch<<"is not"<<endl;
			
		}
		else if(isVowel(ch)){
			cout<<ch<<"is vowel"<<endl;
		}
		else {
			cout<<ch<<"is consonant"<<endl;
		}
		
	 } 

