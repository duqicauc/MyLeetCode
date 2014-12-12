#include <iostream>
using namespace std;

int lengthOfLastWord(const char *s) {
	//1、字符串为空，或者指针为空
	if(s==NULL || *s=='\0')
		return 0;
	int length = strlen(s);
	//2、注意字符串末尾可能有多个空格
	while(s[--length]==' ' && length>=0);

	//3、向前回溯的时候，注意可能到串首边界
	int r = 0;
	for(;length>=0 && s[length--]!=' '; r++);
	return r;
}

int main()
{
	const char *str = "w";
	const char *s2 = "a  ";
	const char *s3 = "";
	const char *s4 = "Hello world";
	int len = lengthOfLastWord(str);
	cout << len <<endl;
	return 0;
}
