/**
 * _islower - chexks for lower case alphabets
 * @c: an interger input
 *
 * Return: 1 if lowercase; 0 otherwise
 */
int _islower(int c)
{
	char lower = 'a';

	while (lower <= 'z')
	{
		if (c == lower)
		{
			return (1);
		}
		lower++;
	}
	return (0);
}
