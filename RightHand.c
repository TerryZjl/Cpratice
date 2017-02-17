#include<stdio.h>
#include<string.h>
#include<assert.h>

void filp(char *left, char *right)
{
	assert(left);
	assert(right);

	while (left<right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}

void RightHand(char *str, int len)
{
	assert(str);

	int num = strlen(str);
	filp(str, str + num - len - 1);
	filp(str + num - len, str + num - 1);
	filp(str, str + num - 1);
}
int main()
{
	char a[] = "abcdefj";
	RightHand(a, 2);
	printf("%s\n", a);
	system("pause");
	return 0;
}
