#include <stdio.h>
#include <stdlib.h>
int charcount(char *filename)//ͳ���ַ���
{
	int n1 = 0;
	char ch;
	FILE *fp;
	errno_t err;
	if ((err = fopen_s(&fp,filename, "r")) != 0)
	{
		exit(-1);
	}
	ch = fgetc(fp);
	while (!feof(fp))
	{
		ch = fgetc(fp);
		n1++;
	}
	fclose(fp);
	return n1;
}

int wordcount(char *filename)//ͳ�Ƶ�����
{
	int n2 = 0, word = 0;
	char ch;
	FILE *fp;
	errno_t err;
	if ((err = fopen_s(&fp, filename, "r")) != 0)
	{
		exit(-1);
	}
	ch = fgetc(fp);
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch<'A' || (ch>'Z'&&ch<'a') || ch>'z')
			word = 0;
		else if (word == 0)
		{
			word = 1;
			n2++;
		}
	}
	fclose(fp);
	return n2;
}
int main()
{
	int charcount(char *filename);
	int wordcount(char *filename);
	FILE *fp;
	errno_t err;
	int c_count, w_count;
	char ch[3], filename[100];
	printf("�����û�����.exe ");
	scanf_s("%s %s", ch,3,filename,100);
	if ((err = fopen_s(&fp, filename, "r")) != 0)
	{
		printf("filenull.\n");
		exit(-1);
	}
	//��ȡ��������
	if (ch[1] == 'c')
	{
		c_count = charcount(filename);
		printf("�ַ���: %d\n", c_count);
	}
	if (ch[1] == 'w')
	{
		w_count = wordcount(filename);
		printf("������: %d\n", w_count);
	}
	return 0;
}