/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_words.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 22:45:10 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/09 02:03:58 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "split.h"

int				words_oadd(t_words *words)
{
	t_word		*temp;
	t_word		*word;

	word = (t_word *)malloc(sizeof(t_word));
	if (!word)
		return (free_words(words, "Error : failed malloc\n"));
	temp = words_olast(words);
	if (!temp)
		words->head = word;
	else
		temp->next = word;
	word->next = 0;
	return (1);
}

t_word			*words_olast(t_words *words)
{
	t_word		*temp;

	temp = words->head;
	if (!temp)
		return (temp);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_list			*init_list(void)
{
	t_list		*temp;

	temp = (t_list *)malloc(sizeof(t_list) * 1);
	if (!temp)
		return (temp);
	temp->head = 0;
	return (temp);
}
