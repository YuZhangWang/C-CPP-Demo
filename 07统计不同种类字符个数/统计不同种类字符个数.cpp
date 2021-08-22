  #include <stdio.h>
void main()
{
	char c;
	int English = 0, Space = 0, Number = 0, Others = 0;
    printf("ÇëÊäÈëÒ»´®×Ö·û:");
	while((c = getchar())!='\n')
	{
		if ((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            English++;
		else if (c==' ')
            Space++;
		else if (c>='0'&&c<='9')
            Number++;
		else
			Others++;
	}
    printf("English=%d\n",English);
    printf("Space=%d\n",Space);
	printf("Number=%d\n",Number);
	printf("Others=%d\n",Others);
}

