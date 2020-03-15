#include<stdio.h>
#include<iostream>
using namespace std;

//字符统计函数
void charcount(FILE *file)
{
	int charnum = 0;
	char c;
	c = fgetc(file);
	while (c != EOF)
	{
		charnum++;
		c = fgetc(file);
	}
	cout <<"The sum of char is:" << charnum << endl;
}


//词数统计函数
void wordcount(FILE *file)
{
	int wordnum = 0;
	char c,prc;
	c = fgetc(file);
	while (c != EOF)
	{
		prc = c;
		c = fgetc(file);
		if ((('a' <= prc && prc <= 'z') || ('A' <= prc && prc <= 'Z')) && (c < 'A' || ('Z' < c && c < 'a') || c > 'z')) 
			wordnum++;	
	}
		cout << "The sum of word is:" << wordnum++ << endl;

}


//行数统计函数
void linecount(FILE *file)
{
	int linenum = 0;
	char c,prc;
	if (file == NULL)
		printf("reading error");
	c = fgetc(file);
	while (c != EOF)
	{
		if (c == '\n') {
			linenum++;	
		}
		prc = c;
		c = fgetc(file);
		if (c == EOF )
		{
			linenum++;	
			break;
		}
	}
	cout << "The sum of line is:" << linenum << endl;
}

//空行统计函数
void emptylinecount(FILE* file)
{
	int count = 0;
	char c, prc;
	c = fgetc(file);
	if (c == '\n')
		count++;
	while(c != EOF)
	{
		prc = c;
		c = fgetc(file);
		if ((c == '\n' || c == EOF)  && prc ==  '\n')
			count++;
	}
	cout << "The sum of empty line if:" << count << endl;
}

int main(int argc,char* argv[])
{
	FILE *file;
	char *file_name, order_name[10] = {'c','w','l','a'};
	char order;
	int i = 0, tag = 0;
	if (argc == 3)
	{
		file = fopen(argv[2], "r");
		order = *argv[1];

		while (file == NULL) {						//文件名输入错误时可以重新输入	
			cout <<"reading error"<<endl;
			cout << "Please input file name" << endl;
			file_name = (char*)malloc(sizeof(char) * 20);
			scanf("%s",file_name);
			file = fopen(file_name, "r");
		}
		
		for ( i = 0; order_name[i] != '\0'; i++)  //检查输入的命令是否正确
		{
			if (order == order_name[i]) 
			{
				tag = 1;
				break;
			}
		}

		while (tag == 0)		//如果输入命令错误则重新输入
		{
			cout << "There's no such order,pleas input again" << endl;
			cin >> order;
			for ( i = 0; order_name[i] != '\0'; i++)
			{
				if (order == order_name[i])
				{
					tag = 1;
					break;
				}
			}
		}
		
		switch (order)     //调用命令
		{
		case 'c':
			charcount(file);
			break;
		case 'w':
			wordcount(file);
			break;
		case 'l':
			linecount(file);
			break;
		case 'a':
			emptylinecount(file);
		default:
			break;
		}
		fclose(file);
		
	}

	else
		cout << "Please input 3 parameter" << endl;

	system("pause");
	return 0;
}

