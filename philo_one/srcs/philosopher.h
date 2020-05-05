#ifndef _PHILOSOPHER_H
# define _PHILOSOPHER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

# define SEMAPHORE	"forks"
# define WAIT_PHI		84
# define WAIT_CPU		42
# define WAIT_WHL		4200

# define UNVAILABLE		-3
# define AVAILABLE		-2
# define ERROR			-1
# define TRUE			0
# define FALSE			1

# define ABSENT			-2
# define DEATH			-1
# define NOTHING		0
# define L_FORK			1
# define R_FORK			2
# define EAT			3
# define SLEEP			4
# define THINK			5

typedef struct	s_philosopher
{
	int				my_id;
	int				nbr_meal;
	struct timeval	last_meal;

	struct timeval	*start;
	pthread_mutex_t	*speak;
	pthread_mutex_t	eating;
	int				eating_status;

	int				arg_time_to_eat;
	int				arg_time_to_sleep;
	int				arg_must_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}				t_philosopher;

typedef	struct	s_all
{
	struct timeval	start;
	pthread_mutex_t	speak;

	int				arg_nbr_philosopher;
	int				arg_time_to_die;
	int				arg_time_to_eat;
	int				arg_time_to_sleep;
	int				arg_must_eat;

	pthread_mutex_t	*array_frk;
	t_philosopher	*array_phi;
	pthread_t		*array_thr;

}				t_all;

/*
************************	check_end.c
*/

int				ft_is_eating(t_philosopher *phi);
int				ft_someone_is_dead(t_all *all);
int				ft_everyone_is_satisfied(t_all *all);

/*
************************	error_exit.c
*/

int				ft_error(char *str, int ret_value);
int				ft_free(t_all *all, int ret_value);

/*
************************	get_time.c
*/

int				ft_get_time(struct timeval *start);

/*
************************	init_1.c
*/

int				ft_init_null(t_all *all);
int				ft_init_speak(t_all *all);
int				ft_init_fork(t_all *all);
int				ft_init_philosopher(t_all *all);
int				ft_init_start(t_all *all);

/*
************************	init_2.c
*/

int				ft_init_thread(t_all *all);

/*
************************	parser.c
*/

int				ft_parser(t_all *all, int argc, char **argv);

/*
************************	thread_tools.c
*/

void			ft_speak(t_philosopher *phi, int status);
void			ft_take_fork(t_philosopher *phi);
void			ft_return_fork(t_philosopher *phi);
void			ft_set_eating_status(t_philosopher *phi, int status);

/*
************************	thread.c
*/

void			*ft_thread(void	*arg);

/*
************************	tools.c
*/

int				ft_strlen(char *str);
void			ft_putstr(char *str);
int				ft_atoi(char *str);
void			ft_putnbr(int nb, char *str, int *i);
void			ft_std_add_str(char *dest, int *i, char *src);

#endif
