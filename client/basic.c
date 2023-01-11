#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int int2char(int i)
{
	return i + 48;
}

int char2int(int c)
{
	return c - 48;
}

void add(char a[], char b[], char c[])
{
	int asize, bsize;
	asize = (int)strlen(a);
	bsize = (int)strlen(b);
	int ext, adda, addb, r;
	for (int i = 0; i < max(asize, bsize); i++)
	{
		if (asize - i - 1 >= 0)
		{
			adda = char2int(a[asize - i - 1]);
		}
		else
		{
			adda = 0;
		}
		if (bsize - i - 1 >= 0)
		{
			addb = char2int(b[bsize - i - 1]);
		}
		else
		{
			addb = 0;
		}

		r = adda + addb + ext;
		if (r >= 10)
		{
			if (i == (max(asize, bsize) - 1))
			{
				c[i + 1] = '1';
				c[i + 2] = '\0'; 
			}
			c[i] = int2char(r % 10);
			ext = 1;
		}
		else
		{
			if (i == (max(asize, bsize) - 1))
			{
				c[i + 1] = '\0'; 
			}
			c[i] = int2char(r);
			ext = 0;
		}
	}
	char nc[strlen(c)];
	for (int i = 0; i < strlen(c); i++)
	{
		nc[i] = c[strlen(c) - 1 - i];
	}
	nc[strlen(c)] = '\0';
	memset(c, 0, strlen(c));
	strcpy(c, nc);
}

void mul(char a[], char b[], char c[])
{
	int asize, bsize, r;
	asize = strlen(a);
	bsize = strlen(b);

	for (int bi = 0; bi < bsize; bi++)
	{
		for (int ai = 0; ai < asize; ai++)
		{
			r = char2int(a[asize - 1 - ai]) * char2int(b[bsize - 1 - bi]);
			if (r >= 10)
			{
				c[ai + bi] += r % 10;
				c[ai + bi + 1] += r / 10;
			}
			else
			{
				c[ai + bi] += r;
			}
		}
	}

	for (int i = 0; i < asize + bsize; i++)
	{
		if (c[i] >= 10)
		{
			c[i + 1] += c[i] / 10;
			c[i] = c[i] % 10;
		}
	}

	char nc[asize + bsize + 1];
	int iszero = 1;
	int j = 0;
	for (int i = 0; i < asize + bsize; i++)
	{
		if (c[asize + bsize - 1 - i] != 0 && iszero)
		{
			iszero = 0;
		}
		if (!(iszero))
		{
			nc[j] = int2char(c[asize + bsize - 1 - i]);
			j++;
		}
	}
	nc[j] = '\0';
	if (iszero)
	{
		memset(nc, 0, asize + bsize);
		nc[0] = '0';
		nc[1] = '\0';
	}
	memset(c, 0, asize + bsize);
	strcpy(c, nc);
}

void mod(char a[], char b[], char c[])
{
	int intb;
	sscanf(b, "%d", &intb);

	char div[100];
	int intdiv;
	for (int i = 0; i < strlen(a); i++)
	{
		div[strlen(div)] = a[i];
		div[strlen(div) + 1] = '\0';
		sscanf(div, "%d", &intdiv);
		memset(div, 0, 100);
		sprintf(div, "%d", intdiv % intb);
	}

    strcpy(c, div);
}

int is_prime(char strnum[])
{
	if ((strcmp(strnum, "0") == 0) || (strcmp(strnum, "1") == 0))
	{
		return 0;
	}

	char tempresult[strlen(strnum)];

	mod(strnum, "11", tempresult);
	if (strcmp(tempresult, "0") == 0)
	{
		return 0;
	}
	memset(tempresult, 0, strlen(strnum));

	mod(strnum, "2", tempresult);
	if (strcmp(tempresult, "0") == 0)
	{
		return 0;
	}
	memset(tempresult, 0, strlen(strnum));

	mod(strnum, "3", tempresult);
	if (strcmp(tempresult, "0") == 0)
	{
		return 0;
	}
	memset(tempresult, 0, strlen(strnum));

	mod(strnum, "5", tempresult);
	if (strcmp(tempresult, "0") == 0)
	{
		return 0;
	}
	memset(tempresult, 0, strlen(strnum));
	
	mod(strnum, "7", tempresult);
	if (strcmp(tempresult, "0") == 0)
	{
		return 0;
	}
	memset(tempresult, 0, strlen(strnum));

	return 1;
}