/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:34:43 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/08 19:53:48 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define FIL 6
# define PIPE 7
# define END 8

# define MAX_VAR_LENGTH 256
# define MAX_VAR_NAME 256

# define TEMP_BUFFER_SIZE 1024

extern int				g_global_status;

typedef struct s_quote_state
{
	int					dq;
	int					sq;
}						t_quote_state;

typedef enum e_quote_state
{
	NONE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
}						t_quotestate;
typedef struct s_token
{
	char				*str;
	int					type;
	struct s_token		*prev;
	struct s_token		*next;
}						t_token;

typedef struct s_file
{
	struct s_file		*next;
	char				*string;
	int					open_mode;
}						t_file;

typedef struct s_heredoc
{
	struct s_heredoc	*next;
	char				*delimiter;
	int					fds[2];
}						t_heredoc;

typedef struct s_section
{
	struct s_general	*info;
	struct s_section	*next;
	t_file				*files;
	t_heredoc			*heredocs;
	int					fd_read;
	int					fd_write;
	char				**env;
	char				**paths;
	char				*path;
	char				**cmdv;
	int					nofile;
	pid_t				pid;
}						t_section;

typedef struct s_allocatedblock
{
	void				*ptr;
	size_t				size;
	char				func_name[20];
}						t_allocatedblock;

typedef struct s_memorymanager
{
	size_t				total_allocated;
	t_allocatedblock	allocated_blocks[16000];
	int					block_count;
	int					total_allocs;
	int					total_frees;
}						t_memorymanager;

typedef struct s_args
{
	char				*resul;
	int					len;
	char				temp[1024];
	char				var_name[256];
	int					temp_index;
	int					var_index;
	int					expanded;
	char				*exit_status_str;
	char				*value;
	int					i;
}						t_args;

typedef struct s_tokenargs
{
	int					i;
	int					*start_pos;
	int					size_malloc;
	int					j;
	char				*current_token;
	int					is_first_token;
	int					expect_file;
	int					in_single_quotes;
	int					in_double_quotes;
	int					k;
}						t_tokenargs;

typedef struct s_general
{
	int					exit_status;
	int					number_of_tokens;
	int					null_paths;
	struct s_token		*tokens_list;
	char				**env;
	char				**exports;
	char				**paths;
	struct s_section	*sections;
	t_memorymanager		manager;
}						t_general;

typedef struct s_section_args
{
	int					i;
	int					*start_pos;
	int					size_malloc;
	int					j;
	int					z;
	int					length_difference;
	int					h;
	char				*current_section;
	char				*current_token;
	int					in_sq;
	int					in_dq;
	t_quotestate		quote_state;
}						t_section_args;

typedef enum e_operator
{
	OP_NONE,
	OP_DOUBLE_QUOTE,
	OP_SINGLE_QUOTE,
	OP_PIPE,
	OP_APPEND,
	OP_TRUNC,
	OP_DOUBLE_INPUT,
	OP_SINGLE_INPUT,
	OP_SPACE
}						t_operator;

// main.c
void					setup_signals(int i);

// tokens.c
t_token					*tokenize_input(t_general *info, char *input);
t_token					*reverse_copy_list(t_token *tokens_list);

// sections.c
void					set_files_section(t_section *section, t_token *first,
							int s);
t_section				*create_sections_list(t_general *info);
void					set_cmdv_section(t_section *section, t_token *first,
							int s);

// executor.c
void					child_process(t_section *current, int prev_fd,
							int *pipefd);
void					parent_process(t_section **current, int *prev_fd,
							int *pipefd);
void					executor(t_general *info);

// prints.c
void					put_str_fd(int fd, char *str);
void					print_tokens_list(t_token *tokens_list);
void					print_matrix(char **matrix);
void					print_string_to_stderror(char *str);
void					print_sections_info(t_section *section);

// frees.c
void					matrix_free(char **str);
void					free_sections_list(t_section *first);
void					free_tokens_list(t_token *first);
void					free_files(t_file *files);
void					free_info(t_general *info);

// frees_2.c
void					free_heredocs(t_general *info);

// utils_1.c
int						thereis_pipe(t_token *first);
void					set_paths_and_env(t_general *info, char **env);
int						count_tokens_per_section(t_token *first);
int						count_sections(t_token *first);
int						ft_strncmp_pipex(const char *str, const char *str2,
							size_t c);

// utils_2.c
int						count_files_per_section(t_token *first);
int						count_cmdvs_per_section(t_token *first);
t_token					*get_first_in_section(t_token *first, int s);
void					add_file_to_files(t_token *section_first, t_file *files,
							int *i, int n);
void					open_files_section(t_section *section);

// utils_3.c
int						exec_if_builtin_1(t_section *current);
void					exec_if_builtin_2(t_section *current);
char					*ft_strjoin_pipex(char const *s1, char const *s2);
void					set_cmd_in_paths(t_section *section);
void					set_path(t_section *section);

// utils_4.c
char					*add_var_equal(char *cmdv1);
char					**remove_env_line(t_section *current, int line);
int						is_directory(const char *path);
char					*ft_getenv(const char *name, char **env);
void					set_exports(t_general *info, char **env);

// utils_5.c
void					add_str_to_matrix(char ***matrix, char *str);
void					allocate_heredocs(t_section *section, t_token *first,
							int s);
void					write_in_heredocs(t_section *current, t_general *info);
char					*clean_str_exit(char *str);
void					close_section_hdocs_parent(t_section *current);

// utils_6.c
void					init_section_objects_helper(t_section *section,
							t_token *first, int s);
void					set_cmdv_section_helper(t_section *section, char **cmdv,
							int i);
void					open_truncate(t_section *section, t_file *tmp);
void					open_append(t_section *section, t_file *tmp);
void					close_prev_fdread(t_section *section);

// utils_7.c
void					exit_if_no_cmdv(t_section *section, int *i);
void					set_cmd_in_paths_helper(t_section *section,
							char *new_path, int i);
int						count_lines(char **matrix);
void					allocate_heredocs_helper(t_token *tmp,
							t_heredoc *tmp_hdocs, t_heredoc *new_hdoc,
							int count);
void					clean_str_exit_helper(char *result, char *str);

// utils_8.c
void					write_in_heredocs_helper(t_heredoc *tmp_hdoc,
							char *buffer, t_general *info);
int						ft_atol_overflow(const char *str, long *result);
void					check_argc_exit(t_section *current);

// utils_9.c
char					*get_var_name(const char *var);
int						compare_var_name(const char *env_var,
							const char *var_name);
char					*get_prev_dir(char **env);
char					*get_home(char **env);
int						n_valid_succession(char **cmdv, int *i);

// utils_10.c
int						search_var_env(char ***env, char *var_name,
							size_t env_len);
int						check_all_env(char ***env, char *var, char **var_name,
							size_t *env_len);
void					set_new_env(char **new_env, size_t j, char *var_name,
							char ***env);
int						check_new_env(char **newenv, int i);
void					set_new_env_2(t_section *current, char **new_env,
							char *var_equal);

// utils_11.c
void					add_export_var(t_section *current, char ***new_paths,
							int n);
char					*get_pdir_helper(size_t len, char **pwd,
							char **prev_dir);
int						has_slash(char *str);
int						has_content(char *str);
int						n_all(char **cmdv);

// utils_12.c
void					remove_endslash(char **var);
int						remove_dots_helper(char *var_pwd, int *i, char c);
int						remove_dots(char **var_pwd);
void					remove_lastdir_helper(char *new_varpwd, char **var_pwd,
							int *i, int *n);
void					remove_var_from_exports(t_section *current,
							char *var_equal);

// utils_13.c
void					remove_lastdir(t_section *current, char **var_pwd);
void					change_last_subdir_helper(char **var_pwd, char *result,
							int *i, int *n);
void					change_last_subdir(t_section *current, char **var_pwd);
int						has_dots_and_subdir(char *str);
void					update_oldpwd(char **var_oldpwd, char **var_pwd);

// utils_14.c
void					upwds_one(t_section *current, char *tmp, char **var_pwd,
							char **var_oldpwd);
void					upwds_two(char **var_pwd, char **var_oldpwd);
void					upwds_three(t_section *current, char **var_pwd,
							char **var_oldpwd);
void					upwds_four(t_section *current, char *tmp,
							char **var_pwd, char **var_oldpwd);
void					upwds_five(t_section *current, char *tmp,
							char **var_pwd, char **var_oldpwd);

// utils_15.c
void					update_pwds(t_section *current, char **var_pwd,
							char **var_oldpwd);
char					*get_var_pwd(t_section *current);
char					*get_var_oldpwd(t_section *current);
int						count_exports(char **exports);
char					**copy_exports(char **exports, int omit_index,
							int total);

// utils_16
void					reset_newline_flag(char **cmdv, int *no_newline);
void					clean_repeateds(char ***env);
char					**reset_env(char ***env, int i);
int						count_env(char **env);
char					*give_varname(char *str);

// utils_17.c
void					if_backdirs_only(t_section *current);

// utils_18.c
void					remove_duplicates(char ***env, int i);
char					**copy_non_null_elements(char **env, int size);
void					free_and_nullify(char **ptr);

// utils_19.c
char					**allocate_path_parts(void);
char					*allocate_result(const char *path);
int						handle_double_dot(char **path_parts, int count);
int						copy_path_part(const char *start, int length,
							char **path_parts, int count);
void					free_allocated_parts(char **path_parts, int count,
							char *result);

// utils_20.c
int						process_path_segments(const char *path,
							char **path_parts);
void					build_clean_path(char *result, char **path_parts,
							int count);
void					copy_env_var(char **new_env, char **env, int i);
char					*extract_pwd(char *env_var);
char					*create_new_env_entry(char *new_pwd);

// utils_21.c
char					*clean_path(const char *path);
int						calculate_env_size(char **env);
void					free_and_replace_env(t_section *current,
							char **new_env);
void					process_env_var(char **new_env, char **env, int i);
void					if_clean_complex_route(t_section *current);

// utils_22.c
int						open_files_section_helper(t_section *section,
							t_file **tmp, t_heredoc **tmp_hdocs);
void					heredocs_norminetter_two(t_section *section,
							t_token **tmp, t_token **section_start, int count);
int						heredocs_norminetter_one(t_section *section,
							t_token **tmp, int s, int *section_index);
int						write_heredocs_norminetter(int *len, char **expanded,
							t_heredoc **tmp_hdoc);
void					removevar_norminetter(t_section *current,
							int *total_exports, char ***new_exports, int n);

// utils_23.c
int						psnorminetter(const char **start, int *count,
							char ***path_parts, int *length);
void					handle_forks(t_section **current, int *prev_fd,
							int (*pipefd)[2]);
void					exexport_printerr(t_section *current, int n);
void					excd_helper(t_section *current, char **var_pwd,
							char **var_oldpwd, char ***new_env);
void					excd_helper_two(t_section *current, char **var_pwd,
							char **var_oldpwd);

// utils_24.c
int						rembackdirs_hlpr(t_section *current, int dirs_back,
							int *i, char ***split_pwd);
int						rembackdirs_hlpr_zero(t_section *current, int i,
							char ***split_pwd);
void					rembackdirs_hlpr_one(char **new_pwd, char ***split_pwd,
							int new_len);
void					rembackdirs_hlpr_two(t_section *current, int i,
							char ***new_env, char **new_pwd);
void					routine(t_general *info, char **input);
void					idontevenknow_bro(t_general *info, t_section **section);

// utils_25.c
void					signals_print_handler(int print);
void					heredoc_handler(int sig);
void					sig_handler(int sig);
void					child_handler(int sig);
void					setup_signals(int i);

// utils_26.c
void					handle_print_tokens(int **print_mode, t_general *info,
							t_token **current, t_token **token_list);
void					handle_input(t_general *info, char *input,
							int *print_mode);

// utils_27.c
void					inits_inits(t_general *info, char ***env,
							const char **history_file, int *print_mode);
void					finish(t_general *info, const char **history_file,
							char **input);
int						check_input(t_general *info, char **input);
void					do_your_thing(t_general *info, char **input,
							t_quote_state *state, int *print_mode);
void					reset_general_paths(t_general *info, char *input);
void					initialize_ij(int *i, int *j);

// utils_executor.c
void					handle_child_process(t_section *current, int prev_fd,
							int pipefd[2]);
void					create_pipe_if_needed(t_section *current,
							int pipefd[2]);
void					wait_for_sections(t_general *info);

// builtins_1.c
int						execute_echo(t_section *current);
int						execute_pwd(t_section *current);
int						execute_env(t_section *current);

// builtins_2.c
void					if_remove_var_from_env(char ***env, char *var);
void					execute_unset(t_section *current);
void					execute_export(t_section *current);
void					execute_cd(t_section *current);
void					execute_exit(t_section *current);
char					**new_wd_environment(char **oldenv,
							const char *var_newpwd, const char *var_newoldpwd);

// tokenize_aux_1.c
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strcat(char *dest, const char *src);
size_t					get_old_size(char *ptr);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*trolft_strdup(const char *s1, t_general *info);

// tokenize_aux_2.c
const char				*get_token_type_name(int type);
void					free_tokens_list_tokenize(t_general *info);
void					quoting_choice(t_quote_state *state, char c);
int						open_quote(char *line, t_quote_state *state);

// tokenize_aux_3.c
char					*allocate_and_copy_section(char **start, char *end,
							t_general *info);
void					init_extract_section(int *in_single_quotes,
							int *in_double_quotes);
void					update_quotes(char current_char, int *in_single_quotes,
							int *in_double_quotes);
void					error_strdup(void);
void					error_malloc(void);

// tokenize_aux_4.c
char					*extract_section(char **start, const char *delimiters,
							t_general *info);
char					*append_string(char *dest, char *src);
void					add_token_to_list(t_general *info, const char *str,
							int type);
char					*add_char_to_token2(t_general *info, char *token,
							char c);
char					*add_char_to_token(t_general *info, char *token,
							char c);

// tokenize_aux_5.c
int						ft_isspace(char c);
char					*get_env_var(t_general *info, const char *var_name);
int						is_special_separator(char c);

// tokenize_aux_6.c
int						count_dollars(const char *section);
void					print_start_pos(int *start_pos);
int						reset_positions(int *start_pos, int size_malloc);

// tokenize_aux_7.c
char					*expand_dollar_question(t_general *info);
char					mark_char(char c);
unsigned char			unmark_char(unsigned char c);
int						is_marked(char c);

// tokenize_aux_8.c
int						is_valid_command(t_general *info, const char *command,
							char **env);

// tokeniza_aux_9.c
char					*expand_variable2(const char *input, int start_pos,
							t_general *info);
int						calculate_length_difference(const char *input,
							int start_pos, t_general *info);

// aux_expansor.c
void					ft_initialize_args(t_args *args, const char *input,
							int start_pos);
void					ft_copy_initial_chars(const char *input, int start_pos,
							t_args *args);
void					handle_expand_dollar_question(t_general *info,
							t_args *args);
void					handle_expand_dollar_zero(t_args *args);
void					copy_invalid_char_to_temp(t_args *args,
							const char *input, int *i);

// aux_aux_expansor.c
void					capture_var_name(const char *input, int *i,
							t_args *args);
void					handle_expansion_chars(t_args *args, const char *value);
void					initialize_and_copy_args(t_args *args,
							const char *input, int start_pos);
void					capture_var_and_value(const char *input,
							t_general *info, t_args *args);
void					ft_line(t_args *args);

// syntax_error.c
int						check_syntax_errors(t_general *info);
int						check_first_command(t_token *current_token,
							t_general *info);
int						check_command(t_general *info, t_token *current_token,
							int *last_type);
int						check_argument(t_token *current_token, int *last_type);
int						check_redirection(t_token *current_token);

// aux_syntax.c
int						check_pipe_at_start(t_token *current_token);

// extract_token.c
void					ft_last_token(t_general *info, t_tokenargs *args);
void					ft_add_char(const char *section, t_general *info,
							t_tokenargs *args);
t_operator				identify_operator(const char *section, size_t i,
							t_tokenargs *args);
void					ft_operators(t_operator op, const char *section,
							t_general *info, t_tokenargs *args);
void					extract_tokens(const char *section, t_general *info);

// extract_token_aux.c
void					ft_init_token_args(t_tokenargs *args,
							const char *section);
void					ft_init_expand(const char *section, t_tokenargs *args,
							t_general *info);
void					ft_double_quote(const char *section, t_general *info,
							t_tokenargs *args);
void					ft_single_quote(const char *section, t_general *info,
							t_tokenargs *args);
void					ft_append(const char *section, t_general *info,
							t_tokenargs *args);

// extract_token_aux_aux.c
void					ft_trunc(const char *section, t_general *info,
							t_tokenargs *args);
void					ft_doble_input(const char *section, t_general *info,
							t_tokenargs *args);
void					ft_single_input(const char *section, t_general *info,
							t_tokenargs *args);
void					ft_pipe(const char *section, t_general *info,
							t_tokenargs *args);
void					ft_space(const char *section, t_general *info,
							t_tokenargs *args);

// extract_section.c
void					ft_init_section_args(t_section_args *args);
char					*extract_current_section(const char *section,
							t_general *info);

// extract_section_aux.c
void					ft_init_section(const char *section,
							t_section_args *args, t_general *info);
void					ft_init_section_args(t_section_args *args);
void					ft_section_double_quotes(const char *section,
							t_general *info, t_section_args *args);
void					ft_section_single_quotes(const char *section,
							t_general *info, t_section_args *args);
void					ft_section_append(const char *section, t_general *info,
							t_section_args *args);

// extract_section_aux_aux.c
void					ft_section_doble_input(const char *section,
							t_general *info, t_section_args *args);
void					ft_section_single_input(const char *section,
							t_general *info, t_section_args *args);
void					ft_section_trunc(const char *section, t_general *info,
							t_section_args *args);
void					ft_section_pipe(const char *section, t_general *info,
							t_section_args *args);
void					ft_section_args(const char *section, t_general *info,
							t_section_args *args);

// extract_section_aux_aux_aux.c
void					ft_reset_section_state(t_section_args *args,
							t_general *info);

char					*append_to_current_section(t_general *info,
							char *current_section, const char *token);

void					trim_trailing_whitespace(char *str);

// extract_section_aux_aux_aux_aux.c
void					ft_while_pipe(const char *section, t_general *info,
							t_section_args *args);
void					handle_quotes(const char c, const char *section,
							t_general *info, t_section_args *args);
int						ft_it_is_operator(const char c);
void					ft_handle_non_operator(const char *section,
							t_general *info, t_section_args *args);
void					ft_handle_whitespace(const char *section,
							t_general *info, t_section_args *args);
// signals.c

void					signals_print_handler(int print);
void					heredoc_handler(int sig);
void					sig_handler(int sig);
void					child_handler(int sig);
void					setup_signals(int i);

// aux_main.c

int						limtit_input(char *input);
void					handle_special_commands(const char *input,
							int *print_mode);
void					cleanup(const char *history_file);
void					init_history(const char *history_file);
int						init_general(t_general *info, char **env);

// trol_alloc.c
void					*my_malloc(t_general *info, size_t size);
void					my_free(t_general *info, void *ptr);
void					free_all_allocated_blocks(t_general *info);
char					*my_realloc_char(char *ptr, size_t new_size);

const char				*get_token_type_name(int type);
int						check_syntax_errors(t_general *info);
void					free_tokens_list_tokenize(t_general *info);
int						open_quote(char *line, t_quote_state *state);
char					*extract_current_section(const char *section,
							t_general *info);

char					*expand_dollar_question(t_general *info);
int						is_special_separator(char c);
char					*get_env_var(t_general *info, const char *var_name);

char					*trolft_strdup(const char *s1, t_general *info);
char					*trolft_itoa(int n, t_general *info);
int						check_syntax_errors(t_general *info);
#endif
