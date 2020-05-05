#ifndef _PHILOSOPHER_H
# define _PHILOSOPHER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

# define SEM_START		"sem_start"
# define SEM_FORKS		"sem_forks"
# define SEM_SPEAK		"sem_speak"
# define SEM_END			"sem_end"
# define WAIT_PHI		42
# define WAIT_END		42
# define WAIT_CPU		420

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

	struct timeval	start;

	int				starter;
	int				arg_time_to_die;
	int				arg_time_to_eat;
	int				arg_time_to_sleep;
	int				arg_must_eat;
	pthread_t		thread;

	sem_t			*eating;
	int				eating_status;

	sem_t			*sem_start;
	sem_t			*sem_forks;
	sem_t			*sem_speak;
	sem_t			*sem_end;
}				t_philosopher;

typedef	struct	s_all
{
	struct timeval	start;

	int				arg_nbr_philosopher;
	int				arg_time_to_die;
	int				arg_time_to_eat;
	int				arg_time_to_sleep;
	int				arg_must_eat;

	sem_t			*eating;
	int				eating_status;

	sem_t			*sem_start;
	sem_t			*sem_forks;
	sem_t			*sem_speak;
	sem_t			*sem_end;

	t_philosopher	*array_phi;
	pthread_t		*array_thr;
	pid_t			*array_pid;

}				t_all;

/*
************************	error_exit.c
*/

int				ft_error(char *str, int ret_value);
int				ft_kill_everyone(t_all *all);
void			ft_unlink(void);
int				ft_free(t_all *all, int ret_value);

/*
************************	get_time.c
*/

int				ft_get_time(struct timeval *start);

/*
************************	init_1.c
*/

int				ft_init_null(t_all *all);
int				ft_init_sem_start(t_all *all);
int				ft_init_sem_fork(t_all *all);
int				ft_init_sem_speak(t_all *all);
int				ft_init_sem_end(t_all *all);

/*
************************	init_2.c
*/

int				ft_init_eating_status(t_all *all);
int				ft_init_philosopher(t_all *all);
int				ft_init_start(t_all *all);
int				ft_init_synchronisation_start(t_all *all);
int				ft_init_processus(t_all *all);

/*
************************	parser.c
*/

int				ft_parser(t_all *all, int argc, char **argv);

/*
************************	processus_tools_1.c
*/

void			ft_speak(t_philosopher *phi, int status);
void			ft_take_fork(t_philosopher *phi);
void			ft_return_fork(t_philosopher *phi);
void			*ft_end_thread(void *arg);
void			ft_is_satiated(t_philosopher *phi);

/*
************************	processus_tools_1.c
*/

int				ft_is_eating(t_philosopher *phi);
void			ft_set_eating_status(t_philosopher *phi, int status);

/*
************************	processus.c
*/

void			*ft_processus(t_philosopher *phi);

/*
************************	tools.c
*/

int				ft_strlen(char *str);
void			ft_putstr(char *str);
int				ft_atoi(char *str);
void			ft_putnbr(int nb, char *str, int *i);
void			ft_std_add_str(char *dest, int *i, char *src);

#endif
