/***************************************************************************
 > Filename   : jcps_file.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-05-26 15:23:29
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>

#define TEST_TXT
#define TEST_BIN
#define BUFSIZE		1024

int main(int argc, char **argv)
{
	FILE *fpr = NULL, *fpw1 = NULL, *fpw2 = NULL;
	char buf[BUFSIZE];
	unsigned int num;

	if (argc < 2) {
		fprintf(stderr, "argc invalid\n");
		return -1;
	}

	fpr = fopen(argv[1], "r+b");
	if (!fpr) {
		fprintf(stderr, "fopen %s failed\n", argv[1]);
		return -1;
	}

#ifdef TEST_TXT
	fpw1 = fopen("jcps_file1", "w+b");
	if (!fpw1) {
		fprintf(stderr, "fpw1 failed\n");
		return -1;
	}
	//这里fpr fpw1是两个文件流，不需要fseek fflush rewind等刷新
	while ((num = fread(buf, sizeof(char), BUFSIZE, fpr)) > 0) {
		fwrite(buf, sizeof(char), num, fpw1);
	}
	fclose(fpw1);
#endif

#ifdef TEST_BIN //如c: 01000001 则实际打开文件后看到的是A, 二进制是特殊的文本文件
	char c;
	fseek(fpr, 0, SEEK_SET); //rewind 读流的起始指针
	fpw2 = fopen("jcps_file2", "w+b");
	if (!fpw2) {
		fprintf(stderr, "fpw2 failed\n");
		return -1;
	}
	c = fgetc(fpr);
	while (!feof(fpr)) {
		fwrite(&c, sizeof(char), 1, fpw2);
		c = fgetc(fpr);
	}
	fclose(fpw2);
#endif

#ifdef TEST_HFM
#endif
	return 0;
}
