#include "ft_printf.h"
#include <limits.h>

int	main(void)
{

	// error
	printf("%i\n", printf(NULL));
	ft_printf("%i\n", ft_printf(NULL));
	
	// %c
	printf("%i\n", printf("hello %c%c hello\n", '4', '2'));
	ft_printf("%i\n", ft_printf("hello %c%c hello\n", '4', '2'));

	// %s
	printf("%i\n", printf("hello %s hello\n", "42"));
	ft_printf("%i\n", ft_printf("hello %s hello\n", "42"));

	// %p
	int i = 5;
	printf("%i\n", printf("address %p address", &i));
	ft_printf("%i\n", ft_printf("address %p address", &i)); 

	// %d / %i
	printf("%i\n", printf("hello %d%i hello\n", 42, 42));
	ft_printf("%i\n", ft_printf("hello %d%i hello\n", 42, 42));

	printf("%i\n", printf("hello %i %d hello\n", INT_MIN, INT_MAX));
	ft_printf("%i\n", ft_printf("hello %i %d hello\n", INT_MIN, INT_MAX));
	
	printf("%i\n", printf("hello %i %d hello\n", 0, UINT_MAX));
	ft_printf("%i\n", printf("hello %i %d hello\n", 0, UINT_MAX));
	// %u
	printf("%i\n", printf("hello %u hello\n", 42));
	ft_printf("%i\n", ft_printf("hello %u hello\n", 42));

	printf("%i\n", printf("hello %u %u hello\n", INT_MIN, INT_MAX));
	ft_printf("%i\n", ft_printf("hello %u %u hello\n", INT_MIN, INT_MAX));
	
	printf("%i\n", printf("hello %u %u hello\n", 0, UINT_MAX));
	ft_printf("%i\n", ft_printf("hello %u %u hello\n", 0, UINT_MAX));

	// %x / %X
	printf("%i\n", printf("hello %x %X", 42, 42));
	ft_printf("%i\n", ft_printf("hello %x %X", 42, 42));

	printf("%i\n", printf("hello %x %X hello\n", 0, UINT_MAX));
	ft_printf("%i\n", ft_printf("hello %x %X hello\n", 0, UINT_MAX));
	
	printf("%i\n", printf("hello %x %X hello\n", INT_MIN, INT_MAX));
	ft_printf("%i\n", ft_printf("hello %x %X hello\n", INT_MIN, INT_MAX));
	
	// undef behavior
	printf("%i\n", printf("%p %p\n", NULL, NULL));
	ft_printf("%i\n", ft_printf("%p %p\n", NULL, NULL));

	//printf("%i\n", printf("%s %s\n", NULL, NULL));
	ft_printf("%i\n", ft_printf("%s %s\n", NULL, NULL));

	//printf("%i\n", printf("hello\n%"));
	ft_printf("%i\n", ft_printf("hello\n%"));
	return (0);
}
