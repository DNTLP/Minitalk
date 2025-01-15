#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>

typedef struct s_mini
{
    int 	pid_server;
    int 	pid_client;
	// int		recived_len;
	// char	*message;
}   t_mini;

t_mini *client_start(void);
t_mini *server_start(void);
void    client_send(t_mini *talk, char *message);
void    server_recieve(int  boolean);
int ft_strlen(char *str);
int ft_atoi(const char *str);
void    ft_putstr(char *str);
void    ft_putnbr(int num);

#endif
