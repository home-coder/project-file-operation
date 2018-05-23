/***************************************************************************
  > Filename   : 001.c
  > Author     : oneface - one_face@sina.com
  > Company    : 一尊还酹江月
  > Time       : 2018-05-21 17:30:16
  > Description: 

  - This program is free software; you can redistribute it and/or modify it
  - under the terms of the GNU General Public License as published by the
  - Free Software Foundation;  either version 2 of the  License, or (at your
  - option) any later version.
 **************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <sys/stat.h>

#define TESTFILE	"./test"
#define TESTFILE2	"./test2"
#define TESTFILE3	"./test3"

#define BUF_SIZE	32

//1. 文本文件和二进制文件都可以在屏幕上显示，但是二进制文件的内容无法读懂，大部分是乱码。
//   文本文件是一种特殊的二进制文件，在于每个字符流的字符可以显示出ascci码

//2. 在Linux和其他一些系统中，文本文件的换行符就是LF(0X0A)，与C语言的换行符一样。所以也就沒有了文本方式和二进制方式的区分，使不使用'b'标志都是一样的。

int main()
{
	//输出到文件中，然后通过vim 打开，再转换成文本查看 是不是我们输入的字符
#if 0
	FILE *fp = fopen(TESTFILE, "wb");

	uint8_t buf[5] = { 0x61, 0x62, 0x63, 0x01, 0x32 };
	fwrite(buf, sizeof(buf[0]), 5, fp);
	fclose(fp);

	fp = fopen(TESTFILE, "rb");
	FILE *fp2 = fopen(TESTFILE2, "w");
	int num = fread(buf, sizeof(char), BUF_SIZE, fp);
	while (num > 0) {
		fwrite(buf, sizeof(char), num, fp2);
		num = fread(buf, 1, BUF_SIZE, fp);
	}

	fclose(fp);
	fclose(fp2);
#endif

#if 0
	FILE *fp = fopen("001.c", "rb");
	FILE *fp2 = fopen("001bac.c", "wb"); //linux 平台下可以w，但是window下如果没有b，则默认成普通文本文件会将0a替换成0d0a
	int num;
	char buf[BUF_SIZE];

	while ((num = fread(buf, 1, BUF_SIZE, fp)) > 0) {
		fwrite(buf, num, BUF_SIZE, fp);
	}
#endif

#if 0 //0x0A 是换行还是文件结束符

	FILE *fp = fopen(TESTFILE3, "wb");
	//比较有符号和无符号的区别
	uint8_t buf[] = {0x61, 0x62, 0x7e, 0x63, 0xff, 0x63, 0x01, 0x32, 0x0a, 0x66, 0xff, 0x62, 0x64, 0x0a, 0x67, 0x68};
	fwrite(buf, sizeof(buf[0]), sizeof(buf)/sizeof(buf[0]), fp);
	fclose(fp);
	fp = fopen(TESTFILE3, "r");
	char c;
#if 0 //文本文件可以通过EOF来判断，EOF=0xff=-1, 不在0-127  Ascci码范围，所以可以使用EOF， 但是二进制则不可以
	while ((c = fgetc(fp)) != EOF) {
		printf("%c ", c);
	}
#endif

	//TODO
#if 0 // 0xff 是可以通过feof判断吗， feof判断的是什么东西, 为什么文本文件和二进制都可以使用feof
	c = fgetc(fp);
	while (!feof(fp)) {
		printf("%c ", c);
		c = fgetc(fp);
	}
#endif

	//比较有符号和无符号的区别
#if 1
	int num;
	for (num = 0; num < sizeof(buf)/sizeof(buf[0]); num++) {
		printf("0x%x ", buf[num]);	
	}
	while ((num = fread(buf, sizeof(char), 2, fp))) {
		printf("0x%x ", buf[0]);	
	}
#endif
#if 0
#endif
	fclose(fp);
#endif

#if 1
	//TODO: 8765的存储，以二进制存储，以文本存储
	int a = 8765999;
#if 0
	FILE *fp = fopen("8765", "w+b");
	fwrite(&a, sizeof(int), 1, fp);
#else 
	FILE *fp = fopen("8765", "w+");
	fprintf(fp, "%d", a);
#endif
	fclose(fp);
	unsigned long filesize = -1;      
	struct stat statbuff;  
	if(stat("8765", &statbuff) >= 0){  
		filesize = statbuff.st_size;  
	}
	printf("8765 size: %ld\n", filesize);
#endif
	//TODO: 8765的存储，以二进制存储fwrite，以文本存储fprintf

	return 0;
}
