

/* Add two integer */
int Add(int n1, int n2)
{
	return (n1 + n2);
}


/* Swap by pointers */
void Swap(int* n1, int* n2)
{
	/* Check NULL Pointer to avoid segmentation fault */

	if (n1 == nullptr || n2 == nullptr)
	{
		// Do nothing
	}
	else
	{
		// Swap
		int tmp;
		tmp = *n1;
		*n1 = *n2;
		*n2 = tmp;
	}	
}

/* Swap by References */
void SwapRef(int& n1, int& n2)
{
	/* Will not check for NULL pointer refernce can not be NULL */
	int tmp;
	tmp = n1;
	n1 = n2;
	n2 = tmp;

}