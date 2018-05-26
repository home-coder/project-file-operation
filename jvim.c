/***************************************************************************
  > Filename   : jvim.c
  > Author     : oneface - one_face@sina.com
  > Company    : 一尊还酹江月
  > Time       : 2018-05-24 14:55:07
  > Description: 

  - This program is free software; you can redistribute it and/or modify it
  - under the terms of the GNU General Public License as published by the
  - Free Software Foundation;  either version 2 of the  License, or (at your
  - option) any later version.
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int width[3001] = { 0 };

int height = 1;
int dwidth = 80;
int dheight = 300;                                                                                                  
int dstart = 1;
int maxlen = 24000;
int x = 1, y = 1;
char a[24002] = { };

int check();
void pull(int temp);
void format();
int sum(int x);
void push(int temp);
int conv(int x1, int y1);
void fr();
void fw();
int non(char ch);
int key(char ch);
int ctrkey(char ch);
int cursor(char ch);
void prin(int n);
void init();

static void clrscr()
{
	printf("\033c");
}

void gotoxy(int x, int y)                                                                                           
{
	printf("%c[%d;%df", 0x1B, y, x);
}

int check()
{
	int i = 1, t = 1, temp = 1;
	while (a[i] != '\0') {
		if ((a[i] == '\n')) {
			t++;
			temp = 0;
		}

		else if (temp == dwidth) {
			if (t < dheight) {
				t++;
				temp = 0;
			}
		}
		i++;
		temp++;
	}
	if (t > dheight)
		return 1;

	else
		return 0;
}

void pull(int temp)
{
	int i = 0;
	for (i = temp; i <= sum(height); i++) {
		a[i - 1] = a[i];
	}
	a[sum(height)] = 0;
}

void format()
{
	int i = 1, t = 1, temp = 1;
	height = 0;
	while (a[i] != '\0') {
		if ((a[i] == '\n')) {
			width[t] = temp;
			t++;
			temp = 0;
		}

		else if (temp == dwidth) {
			width[t] = dwidth;
			if (t < dheight) {
				t++;
				temp = 0;
			}
		}
		i++;
		temp++;
	}
	if ((a[i] == '\0')) {
		width[t] = temp;
		temp = 0;
	}
	height = t;
}

int sum(int x)
{
	int i = 0, sum = 0;
	for (i = 1; i <= x; i++)
		sum += width[i];
	return sum;
}

void push(int temp)
{
	int i = 0;
	for (i = sum(height); i >= temp; i--) {
		a[i + 1] = a[i];
	}
}

int conv(int x1, int y1)
{
	return sum(x1 - 1) + y1;
}

void init()
{
	int i = 0;
	x = 1;
	y = 1;
	for (i = 0; i <= maxlen + 1; i++)
		a[i] = 0;
	for (i = 0; i <= 3000; i++)
		width[i] = 0;
	dstart = 1;
	format();
}

int getch()
{
	char ch;
	system("stty -echo -icanon");
	ch = getchar();
	system("stty echo icanon");
	return ch;
}

void fr()
{
	FILE *fp;
	int c = 0, r = 0;
	int i;
	char ch;
	char fpath[100] = { 0 };
	memset(fpath, 0, sizeof(fpath));
	clrscr();
	printf("[OPEN] Please input a number to decryption:");
	r = scanf("%d", &c);
	while ((ch = getchar()) != '\n' && ch != EOF) ;
	ch = 0;
	if ((r != 1)) {
		printf("Error!\n");
		getch();
		getch();
		clrscr();
		return;
	}
	r = 0;
	printf("[OPEN] Please input the file path:");
	fgets(fpath, 100, stdin);
	while ((ch = getchar()) != '\n' && ch != EOF) ;
	ch = 0;
	if ((fp = fopen(fpath, "r")) == NULL) {
		printf("Can't open the file!");
		getch();
		getch();
		clrscr();
		return;
	}
	init();
	i = 1;
	while ((ch = getc(fp)) != EOF) {
		if (i > maxlen)
			break;
		a[i] = ch + c;
		i++;
	}
	fclose(fp);
	printf("Read the file successful!");
	getch();
	getch();
	clrscr();
	return;
}

void fw()
{
	FILE *fp;
	char fpath[100] = { 0 };
	int i = 0;
	int c = 0, r = 0;
	char ch = 0;
	memset(fpath, 0, sizeof(fpath));
	clrscr();
	printf("[SAVE] Please input a number to encrypt:");
	r = scanf("%d", &c);
	while ((ch = getchar()) != '\n' && ch != EOF) ;
	ch = 0;
	if ((r != 1)) {
		printf("Error!\n");
		getch();
		getch();
		clrscr();
		return;
	}
	r = 0;
	printf("[SAVE] Please input the file path:");
	fgets(fpath, 100, stdin);
	while ((ch = getchar()) != '\n' && ch != EOF) ;
	ch = 0;
	if ((fp = fopen(fpath, "w")) == NULL) {
		printf("Can't open file!");
		getch();
		getch();
		clrscr();
		exit(0);
	}
	for (i = 1; i <= sum(height); i++) {
		if (a[i] != 0)
			putc(a[i] - c, fp);
	}
	fclose(fp);
	printf("Write the file successful!");
	getch();
	getch();
	clrscr();
	exit(0);
}


int key(char ch)                                                                                                    
{
	char temp = 0;
	if (((conv(x, y) >= sum(height)) && (height <= dheight) && (y <= dwidth))) {
		a[conv(x, y)] = ch;
		if (width[x] < dwidth)
			width[x]++;
		if (y < width[x])
			y = y + 1;

		else if ((y == width[x]) && (x < dheight)) {
			x++;
			y = 1;
		}
		if (x > (22 + dstart))
			dstart++;
		format();
		prin(1);
	}

	else {
		if ((height > dheight) || ((height == dheight) && (width[height] - 1 == dwidth))) ;

		else {
			push(conv(x, y));
			temp = a[conv(x, y)];
			a[conv(x, y)] = ch;
			if (check() == 1) {
				pull(conv(x, y));
				a[conv(x, y)] = temp;
			}

			else {
				a[conv(x, y)] = ch;

				/*if (width[x]<dwidth) width[x]++;
				  else
				  if ((width[x]==dwidth)&&(x<=dheight)) {height++;x++;width[x]++;x--;} */
				format();
				if (y < width[x])
					y = y + 1;

				else if ((y == width[x]) && (x < dheight)) {
					x++;
					y = 1;
				}
				if (x > (22 + dstart))
					dstart++;
				prin(1);
			}
		}
	}
	return 1;
}

void prin(int n)
{
	int i = 0, j = 0, flag = 0;
	if (n == 1) {
		clrscr();
		for (i = dstart; i <= dstart + 62; i++) {
			flag = 0;
			for (j = 1; j <= width[i]; j++) {
				printf("%c", a[conv(i, j)]);
				if (a[conv(i, j)] == '\n')
					flag = 1;
			}
			if (flag == 0)
				printf("\n");
		}
		gotoxy(61, 64);
		printf("Powered by LEXUGE");
	}
	gotoxy(5, 64);
	printf("X:%d Y:%d ", x, y);
	gotoxy(y, (x - dstart + 1));
}

int main()
{
	clrscr();
	while (1) {
		gotoxy(22, 22);
		printf("hello world");
		char ch = getch();
		key(ch);
	}

	return 0;
}
