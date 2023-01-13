#include <stdio.h>
#include <string.h>

#define BUFSIZE 3000

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

void strn_mvleft(char str[], int n, char newstr[])
{
	/*
	str: "123"
	n: 3

	new: "123000"
	*/
	strncpy(newstr, str, strlen(str));
	for (int i = 0; i < n; i++)
	{
		strcat(newstr, "0");
	}
}

int compare(char a[], char b[])
{
	/*
	1  : a > b
	-1 : a < b
	0  : a = b
	*/
	int la, lb;
	la = strlen(a); lb = strlen(b);

	if (la > lb)
	{
		return 1;
	}
	if (la < lb)
	{
		return -1;
	}
	if (la == lb)
	{
		for (int i = 0; i <= la - 1; ++i)
		{
			if (char2int(a[i]) > char2int(b[i]))
			{
				return 1;
			}
			if (char2int(a[i]) < char2int(b[i]))
			{
				return -1;
			}
			if (char2int(a[i]) == char2int(b[i]) && i == la - 1)
			{
				return 0;
			}
		}
	}
}

void add(char a[], char b[], char c[])
{
	int abuf[BUFSIZE], bbuf[BUFSIZE], cbuf[BUFSIZE];

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

	memset(abuf, 0, BUFSIZE);
	memset(bbuf, 0, BUFSIZE);
	memset(cbuf, 0, BUFSIZE);
}

void mul(char a[], char b[], char c[])
{
	int abuf[BUFSIZE], bbuf[BUFSIZE], cbuf[BUFSIZE];

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

	memset(abuf, 0, BUFSIZE);
	memset(bbuf, 0, BUFSIZE);
	memset(cbuf, 0, BUFSIZE);
}

void sub(char a[], char b[], char c[])
{
	/*
	a is bigger than b
	*/
	int abuf[BUFSIZE], bbuf[BUFSIZE], cbuf[BUFSIZE];

	int la, lb, lc;
	la = strlen(a); lb = strlen(b);
	for (int i = 0; i <= la - 1; ++i)
	{
		abuf[i] = char2int(a[la - 1 - i]);
	}
	for (int i = 0; i <= lb - 1; ++i)
	{
		bbuf[i] = char2int(b[lb - 1 - i]);
	}
	lc = 0;
	while (lc <= la - 1 || lc <= lb - 1)
	{
		cbuf[lc] += abuf[lc] - bbuf[lc];
		if (cbuf[lc] < 0)
		{
			cbuf[lc] += 10;
			cbuf[lc + 1]--;
		}
		lc++;
	}

	while (cbuf[lc] == 0 && lc >= 1) lc--;

	for (int i = 0; i <= lc; i++)
	{
		c[i] = int2char(cbuf[lc - i]);
	}
	c[lc + 1] = '\0';

	memset(abuf, 0, BUFSIZE);
	memset(bbuf, 0, BUFSIZE);
	memset(cbuf, 0, BUFSIZE);
}

void div(char a[], char b[], char c[])
{
    char abuf[BUFSIZE], bbuf[BUFSIZE], cbuf[BUFSIZE];

    int la, lb, lc;
	la = strlen(a); lb = strlen(b);
    lc = la - lb + 1;

    // copy to buffer
    strncpy(abuf, a, la);

    for (int i = 0; i < lc; i++)
    {
    	memset(bbuf, 0, strlen(bbuf));
    	strn_mvleft(b, lc - i - 1, bbuf);
    	while (compare(abuf, bbuf) >= 0) // abuf >= bbuf
        {
        	cbuf[lc - 1 - i]++;
        	// abuf -= bbuf;
        	char r[BUFSIZE];
        	sub(abuf, bbuf, r);
        	memset(abuf, 0, BUFSIZE);
        	strncpy(abuf, r, BUFSIZE);
        }
    }

    while (cbuf[lc] == 0 && lc >= 1) lc--;

   	for (int i = 0; i <= lc; i++)
   	{
   		c[i] = int2char(cbuf[lc - i]);
   	}
   	c[lc + 1] = '\0';

   	memset(abuf, 0, BUFSIZE);
	memset(bbuf, 0, BUFSIZE);
	memset(cbuf, 0, BUFSIZE);
}

void mod(char a[], char b[], char c[])
{
    char abuf[BUFSIZE], bbuf[BUFSIZE];

    int la, lb, lc;
	la = strlen(a); lb = strlen(b);
    lc = la - lb + 1;

    // copy to buffer
    strncpy(abuf, a, la);

    for (int i = 0; i < lc; i++)
    {
    	memset(bbuf, 0, strlen(bbuf));
    	strn_mvleft(b, lc - i - 1, bbuf);
    	while (compare(abuf, bbuf) >= 0) // abuf >= bbuf
        {
        	// abuf -= bbuf;
        	char r[BUFSIZE];
        	sub(abuf, bbuf, r);
        	memset(abuf, 0, BUFSIZE);
        	strncpy(abuf, r, BUFSIZE);
        }
    }

    strncpy(c, abuf, strlen(abuf));

   	memset(abuf, 0, BUFSIZE);
	memset(bbuf, 0, BUFSIZE);
}