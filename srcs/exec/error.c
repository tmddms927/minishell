#include "exec.h"
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include "object.h"

void	handle_error(char *str)
{
	printf("error : %s\n", str);
	exit(1);
}

void	handle_message(char *str)
{
	printf("message : %s\n", str);
}

void	snatch_error(int error_num, t_list *command_list)
{
	int i;
	char s[3];
	int j;
	t_set	*temp;

	temp = find_set(command_list, "?\0");
	i = -1;
	j = 0;
	if (error_num == 0)
	{
		temp->value[++i] = '0';
		i++;
	}
	while (error_num > 0)
	{
		s[j++] = error_num % 10 + '0';
		error_num = error_num / 10;
	}
	while (++i < j)
		temp->value[i] = s[j - i - 1];
	temp->value[i] = 0;
}

void	exit_safe(char *func_name, char *obj, int err_num, int exit_num)
{
	if (err_num < 108)
		printf("%s: %s: %s\n", func_name, obj, strerror(err_num));
	else if (err_num == 127)
		command_not_found(func_name, obj);
	exit(exit_num);
}

void	command_not_found(char *func_name, char *obj)
{
	printf("%s: %s: command not found\n", func_name, obj);
}
