int main()
{
	char c;
	unsigned char uc;
	unsigned short us;
	c = 128;
	uc = 128;
	us = c + uc;
	printf("0x%x  ", us);
	us = (unsigned char)c + uc;
	printf("0x%x  ", us);
	us = c + (char)uc;
	printf("0x%x  ", us);
	system("pause");
	return 0;
}
