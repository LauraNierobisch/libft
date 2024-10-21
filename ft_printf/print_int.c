/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:02:01 by lnierobi          #+#    #+#             */
/*   Updated: 2024/10/21 11:07:51 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_int(long long n)
{
	char	*isstring;
	int		count;

	count = 0;
	isstring = ft_itoa(n);
	if (!isstring)
		return (-1);
	count = print_str(isstring);
	free(isstring);
	return (count);
}
