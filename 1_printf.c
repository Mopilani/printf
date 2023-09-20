#include "main.h"

/**
 * _printf - Custom printf function supporting %c and %s format specifiers.
 * @format: The format string.
 * Return: The total number of characters printed.
 */
int _printf(const char *const format, ...)
{
	int _length = 0;
	va_list _list;
	const char *_fmt_char;

	if (format == NULL)
		return (-1);
	_fmt_char = format;
	if ((_fmt_char[0] == '%' && !_fmt_char[1]) || !_fmt_char)
		return (-1);
	if ((!_fmt_char[2] && _fmt_char[0] == '%' && _fmt_char[1] == ' '))
		return (-1);


	va_start(_list, format);

	for (; *_fmt_char; _fmt_char++)
	{
		if (*_fmt_char == '%')
		{
			_fmt_char++; /* Move to the character after '%' */
			if (*_fmt_char == 'c' || *_fmt_char == 's' || *_fmt_char == 'd' ||
			*_fmt_char == 'x' || *_fmt_char == 'X' || *_fmt_char == 'i' || 
			*_fmt_char == 'u' ||  *_fmt_char == 'o' ||  *_fmt_char == 'b')
				_length += _slt_func(*_fmt_char)(_list);
			else if (*_fmt_char == '%')
			{
				_length += _putchar('%');
			}
			else
			{
				_length += _putchar('%');
				_length += _putchar(*_fmt_char);
				continue;
			}
		}
		else
			_length += _putchar(*_fmt_char);
	}
	va_end(_list);
	return (_length);
}

