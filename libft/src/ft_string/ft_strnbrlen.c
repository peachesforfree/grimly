/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:00:49 by bmontoya          #+#    #+#             */
/*   Updated: 2017/05/23 15:01:03 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strnbrlen(long long nbr, int base)
{
	int len;

	len = (nbr < 0) ? 2 : 1;
	while ((nbr /= base))
		++len;
	return (len);
}
