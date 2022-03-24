#include <stdio.h>

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *src)
{
	int	result;
	int	sign;
	int	control;

	sign = -1;
	result = 0;
	control = 0;
	while (ft_isspace(*src))
		src++;
	if (*src == 45 || *src == 43)
		if (*src++ == 45)
			sign = 1;
	while (*src >= 48 && *src <= 57)
	{
		result = (result * 10) - (*src++ - '0');
		if (control < result)
		{
			if (sign < 0)
				return (-1);
			return (0);
		}
		control = result;
	}
	return (sign * result);
}

int main(void) {
    printf("number: %d\n", ft_atoi("-1"));
}