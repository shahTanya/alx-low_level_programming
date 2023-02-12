/**
 * _isalpha - checks for alphabetic characters
 * @c: integer input
 *
 * Return: 1 if alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	char lower = 'a';
	char upper = 'A';

	while (lower <= 'z')
	{
		if (c == lower || c == upper)
		{
			return (1);
		}
		lower++;
		upper++;
	}
	return (0);
}
