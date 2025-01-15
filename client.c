#include "minitalk.h"

t_mini  *client_initiate(void)
{
    t_mini  *talk;

    talk = malloc(sizeof(t_mini));
    if (!talk)
    {
        ft_putstr("ERROR!, malloc failed !\n");
        exit(EXIT_FAILURE);
    }
    talk->pid_server = 0;
    talk->pid_client = 0;
    return (talk);
}

void    client_send(t_mini *talk, char *message)
{
    int bit_displacement;
    int i;
    int signal;

    i = -1;
	// send_length(talk, message);
    while (++i <= ft_strlen(message))
    {
        bit_displacement = 7;
        while (bit_displacement >= 0)
        {
            if ((message[i] >> bit_displacement) & 1)
                signal = SIGUSR2;
            else
                signal = SIGUSR1;
			bit_displacement--;
            kill(talk->pid_server, signal);
            usleep(100);
        }
    }
    return ;
}

// void	send_length(t_mini *talk, char *message)
// {
// 	size_t	len;
// 	int		bit_displacement;

// 	len = ft_strlen(message);
// 	bit_displacement = 15;
// 	while (bit_displacement >= 0)
// 	{
// 		if ((len >> bit_displacement) & 1)
// 			kill(talk->pid_server, SIGUSR2);
// 		else
// 			kill(talk->pid_server, SIGUSR1);
// 		bit_displacement--;
// 	}
// 	return ;
// }

int main(int nword, char *arguments[])
{
    t_mini *talk;

    talk = NULL;
    if (nword != 3)
    {
        ft_putstr("ERROR!, use \"./client PID \"string\"\"\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        talk = client_initiate();
        talk->pid_server = ft_atoi(arguments[1]);
        if (talk->pid_server <= 0)
        {
            ft_putstr("ERROR!, PID is equal or less than 0\n");
            free(talk);
            exit(EXIT_FAILURE);
        }
        client_send(talk, arguments[2]);
    }
    free(talk);
    return (EXIT_SUCCESS);
}
