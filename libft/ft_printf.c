/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:58:28 by mredkole          #+#    #+#             */
/*   Updated: 2023/09/30 21:44:11 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pointer_check(unsigned long long num, int *len)
{
	if (num == 0)
	{
		ft_putstrr("(nil)", len);
		return ;
	}
	else
	{
		ft_putstrr("0x", len);
		ft_conv_hexa(num, 'x', len);
	}
}

void	ft_format_check(va_list *ap, int *len, char format)
{
	if (format == 'c')
		ft_putcharr(va_arg(*ap, int), len);
	else if (format == 's')
		ft_putstrr(va_arg(*ap, char *), len);
	else if (format == 'p')
		pointer_check(va_arg(*ap, unsigned long long), len);
	else if (format == 'd' || format == 'i')
		ft_num(va_arg(*ap, int), len);
	else if (format == 'u')
		ft_num_unsigned(va_arg(*ap, unsigned int), len);
	else if (format == 'x')
		ft_conv_hexa(va_arg(*ap, unsigned int), format, len);
	else if (format == 'X')
		ft_conv_hexa(va_arg(*ap, unsigned int), format, len);
	else if (format == '%')
		ft_putcharr('%', len);
}

int	ft_printf(const char *placeholder, ...)
{
	int		len;
	int		i;
	va_list	ap;

	len = 0;
	i = 0;
	va_start(ap, placeholder);
	while (placeholder[i])
	{
		if (placeholder[i] == '%')
		{
			ft_format_check(&ap, &len, placeholder[i + 1]);
			i++;
		}
		else
			ft_putcharr((char)placeholder[i], &len);
		i++;
	}
	va_end(ap);
	return (len);
}
