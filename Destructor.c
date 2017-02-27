class Array
{
private:
	int *ptr;
	int num;
public:
	int *getptr()
	{
		return ptr;
	}
	Array(int n=5)
	{
		num = n;
		ptr = (int *)malloc(sizeof(int)*n);
		if (ptr == NULL)
		{
			return;
		}
		memset(ptr, 0, sizeof(int)*n);
		cout << "A" << endl;
	}

	~Array()
	{
		if (ptr != NULL)
		{
			cout << "free" << endl;
			free(ptr);
			ptr = NULL;
			system("pause");
		}
	}
};

int main()
{
	Array arr(10);
	arr.getptr()[0] = 0;
	return 0;
}
