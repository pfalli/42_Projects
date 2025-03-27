#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void ft_putstr(char *str, int *len) {
	if (!str)
		str = "(nil)";
	while (*str)
		len += write(1, str++, 1);
}

void ft_putnbr(long long int n, int base, int *len) {
	char *hex = "0123456789abcdef";

	if (n < 0) {
		n *= -1;
		write(1, "-", 1);
	}
	if (n >= base)
		ft_putnbr((n / base), base, len);
	len += write(1, &hex[n % base], 1);
}

int ft_printf(const char *fmt, ...) {
	int len = 0;
	va_list ptr;
	va_start(ptr, fmt);

	while (*fmt) {
		if ((*fmt == '%') && ((*(fmt + 1) == 's') || (*(fmt + 1) == 'd') || (*(fmt + 1) == 'x'))) {
			fmt++;
			if (*fmt == 's')
				ft_putstr(va_arg(ptr, char *), &len);
			else if (*fmt == 'd')
				ft_putnbr((long long int)va_arg(ptr, int), 10, &len);
			else if (*fmt == 'x')
				ft_putnbr((long long int)va_arg(ptr, unsigned int), 16, &len);
		} else
			len += write(1, fmt, 1);
		fmt++;
	}
	return (va_end(ptr), len);
}	

#include <stdio.h>
int main (void) {
	ft_printf("abc: %s %d %x\n", "42", 42, 42);
	printf("abc: %s %d %x\n", "42", 42, 42);
	return 0;
}
