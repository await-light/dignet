#include <stdio.h>
#include <string.h>

int abuf[3000], bbuf[3000], cbuf[3000];

int char2int(char c)
{
	/*
	char to int
	'1' -> 1
	*/
	return (c - 48);
}

int int2char(int i)
{
	/*
	int to char
	1 -> '1'
	*/
	return (i + 48);
}

void add(char a[], char b[], char c[])
{
	int la, lb, lc, x;
	la = strlen(a); lb = strlen(b);

	for (int i = 0; i <= la - 1; ++i)
	{
		abuf[la - 1 - i] = char2int(a[i]);
	}
	for (int i = 0; i <= lb - 1; ++i)
	{
		bbuf[lb - 1 - i] = char2int(b[i]);
	}

	lc = 0; x = 0;
	while (lc <= la - 1 || lc <= lb - 1)
	{
		cbuf[lc] = abuf[lc] + bbuf[lc] + x;
		x = cbuf[lc] / 10;
		cbuf[lc] %= 10;
		lc++;
	}
	cbuf[lc] = x;

	while (cbuf[lc] == 0 && lc > 0) lc--;

	for (int i = 0; i <= lc; i++)
	{
		c[i] = int2char(cbuf[lc - i]);
	}
	c[lc + 1] = '\0';

	memset(abuf, 0, 3000);
	memset(bbuf, 0, 3000);
	memset(cbuf, 0, 3000);
}

void mul(char a[], char b[], char c[])
{
	int lena, lenb, lenc, x = 0;
	
	lena = strlen(a); lenb = strlen(b);
	for (int i = 0; i <= lena - 1; ++i)
	{
		abuf[i] = char2int(a[lena - 1 - i]);
	}
	for (int i = 0; i <= lenb - 1; ++i)
	{
		bbuf[i] = char2int(b[lenb - 1 - i]);
	}

	for (int i = 0; i <= lena - 1; ++i)
	{
		for (int j = 0; j <= lenb - 1; ++j)
		{
			cbuf[i + j] += abuf[i] * bbuf[j] + x;
			x = cbuf[i + j] / 10;
			cbuf[i + j] %= 10;
		}
	}

	lenc = lena + lenb;
	while (cbuf[lenc] == 0 && lenc >= 1) lenc--;
	for (int i = 0; i <= lenc; i++)
	{
		c[i] = int2char(cbuf[lenc - i]);
	}
	c[lenc + 1] = '\0';
}