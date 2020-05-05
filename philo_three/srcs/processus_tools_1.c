#include "philosopher.h"

void	ft_speak(t_philosopher *phi, int status)
{
	int		i;
	char	str[300];

	i = 0;
	ft_putnbr(ft_get_time(&phi->start), str, &i);
	str[i++] = ' ';
	str[i++] = ' ';
	str[i++] = ' ';
	ft_putnbr(phi->my_id + 1, str, &i);
	if (status == L_FORK)
		ft_std_add_str(str, &i, "   has taken a fork\n");
	else if (status == R_FORK)
		ft_std_add_str(str, &i, "   has taken a fork\n");
	else if (status == EAT)
		ft_std_add_str(str, &i, "   is eating\n");
	else if (status == SLEEP)
		ft_std_add_str(str, &i, "   is sleeping\n");
	else if (status == THINK)
		ft_std_add_str(str, &i, "   is thinking\n");
	str[i++] = '\0';
	sem_wait(phi->sem_speak);
	write(1, str, ft_strlen(str));
	sem_post(phi->sem_speak);
}

void	ft_take_fork(t_philosopher *phi)
{
	sem_wait(phi->sem_forks);
	ft_speak(phi, L_FORK);
	sem_wait(phi->sem_forks);
	ft_speak(phi, R_FORK);
}

void	ft_return_fork(t_philosopher *phi)
{
	sem_post(phi->sem_forks);
	sem_post(phi->sem_forks);
}

void	*ft_end_thread(void *arg)
{
	t_philosopher *phi;

	phi = arg;
	while (1)
	{
		usleep(WAIT_CPU);
		if (ft_get_time(&phi->last_meal) > phi->arg_time_to_die &&
				ft_is_eating(phi) == FALSE)
		{
			sem_wait(phi->sem_speak);
			ft_putnbr(ft_get_time(&phi->start), NULL, NULL);
			write(1, "   ", 3);
			ft_putnbr(phi->my_id + 1, NULL, NULL);
			write(1, "   ", 3);
			write(1, "died\n", 5);
			sem_post(phi->sem_end);
			exit(0);
		}
	}
	return (NULL);
}

void	ft_is_satiated(t_philosopher *phi)
{
	if (phi->arg_must_eat != ERROR && phi->nbr_meal >= phi->arg_must_eat)
	{
		usleep(phi->arg_time_to_eat + WAIT_END);
		sem_post(phi->sem_end);
		exit(0);
	}
}
