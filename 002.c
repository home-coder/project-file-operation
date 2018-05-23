/***************************************************************************
 > Filename   : 002.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-05-23 11:14:09
 > Description: 笑渐不闻声渐悄，多情总被无情恼

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE		1024

char *fgets(char *s, int n, FILE * stream)
{
	register int c;
	register char *cs;
	cs = s;
	while (--n > 0 && (c = getc(stream)) != EOF)
		if ((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

static int find1_find2(char *end1, char *start2)
{
	if (end1 >= start2) {
		return 0;
	}
	while (end1++ < start2) {
		if (isspace(*end1)) {
			return 0;
		}
	}

	return 1;
}

int main()
{
	int ret;
	unsigned long llen;
	char *p1 = NULL, *p2 = NULL, *pmatch = NULL;
	char *find1 = "hello";
	char *find2 = "world";
	FILE *fp = fopen("002test", "r+b");	//TODO r r+ w w+ b等规则
	//if err

	char *test = "wahahaslhello worldjfkdsal;jfkdshello \t  worldfkdkkkhello";
	printf("test len=%ld\n", strlen(test));
	char buf[BUFSIZE];
	while (fgets(buf, BUFSIZE, fp) != NULL) {
		llen = strlen(buf);	//TODO 文件指针fp此时指向的是下一行的头
		pmatch = buf;
		while ((p1 = strstr(pmatch, find1)) && (p2 = strstr(p1 + strlen(find1), find2))) {
			printf("p1=%s\n", p1);
			printf("p2=%s\n", p2);

			ret = find1_find2(p1 + strlen(find1), p2);
			if (ret > 0) {
				//BUFSIZE 足够大，容纳了一行，且实际buf中的数据比文本中看到的实际字符多了一个换行符\n
				printf("存在这样的匹配规则下的情况, llen=%ld\n", llen);
				fseek(fp, -llen, SEEK_CUR);	//TODO 如果采用两个文件指针实现该怎么做
				fwrite("fuck", sizeof(char), strlen("fuck"), fp);	//如果使用格式化写入函数fputs或者fprintf呢
				fseek(fp, (llen - strlen("fuck")), SEEK_CUR);
				break;	//TODO 只要一次就可以,同时反思王垠优秀编程的反向判断规则：去除循环中的continue,break等
			}
			pmatch = ++p1;
		}
	}

	close(fp);

	return 0;
}
