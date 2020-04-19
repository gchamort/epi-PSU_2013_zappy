R_PATH	= srcs/

SRCS	= \
	$(R_PATH)tools.c		\

HEAD	= -I includes/

## client ##
CLIENT	= client

C_PATH	= $(R_PATH)client/

C_SRCS	=$(C_PATH)main.c		\
	$(R_PATH)tools.c		\
	$(C_PATH)client.c		\
	$(C_PATH)checks_usage.c		\
	$(C_PATH)write_to.c		\
	$(C_PATH)IAFood.c		\
	$(C_PATH)IAJewels.c		\
	$(C_PATH)IATeam.c		\
	$(C_PATH)IAmain.c		\
	$(C_PATH)ParseData.c		\
	$(C_PATH)initElevation.c	\
	$(C_PATH)endElevation.c		\
	$(C_PATH)moves.c		\
	$(C_PATH)tabs.c			\
	$(C_PATH)forIncantation.c	\
	$(C_PATH)broadcasts.c		\
	$(C_PATH)read_socket.c		\
	$(C_PATH)fdisset.c		\

C_OBJS	= $(C_SRCS:.c=.o)

## server ##
SERVER	= server

S_PATH	= $(R_PATH)server/

S_SRCS	= $(SRCS)			\
	$(S_PATH)main.c			\
	$(S_PATH)init_param.c		\
	$(S_PATH)server.c		\
	$(S_PATH)handle_ctrl_c.c	\
	$(S_PATH)handle_sig_pipe.c	\
	$(S_PATH)manage_clients.c	\
	$(S_PATH)display.c		\
	$(S_PATH)manage_fd.c		\
	$(S_PATH)wr_on_socket.c		\
	$(S_PATH)set_values.c		\
	$(S_PATH)map_manage.c		\
	$(S_PATH)map_getinfo.c		\
	$(S_PATH)manage_timer.c		\
	$(S_PATH)cmd_broadcast.c	\
	$(S_PATH)cmd_check.c		\
	$(S_PATH)cmd_connect_nbr.c	\
	$(S_PATH)cmd_drop.c		\
	$(S_PATH)cmd_expulse.c		\
	$(S_PATH)cmd_fork.c		\
	$(S_PATH)cmd_incant.c		\
	$(S_PATH)cmd_invent.c		\
	$(S_PATH)cmd_listbox.c		\
	$(S_PATH)cmd_manage.c		\
	$(S_PATH)cmd_move.c		\
	$(S_PATH)cmd_see.c		\
	$(S_PATH)cmd_take.c		\

S_OBJS	= $(S_SRCS:.c=.o)

## compile ##
CC	= gcc -o

CFLAGS	= -W -Wall -Werror -Wextra $(HEAD)

RM	= rm -f

## rules ##
all:	$(CLIENT) $(SERVER)
	cd client_graphique && make && cd .. && pwd
	@echo -e "\033[32m\t\t\t\t{Client Compiled.}\033[039m"

$(CLIENT):	$(C_OBJS)
	$(CC) $(CLIENT) $(C_OBJS)
	@echo -e "\033[32m\t\t\t\t{Client Compiled.}\033[039m"

$(SERVER):	$(S_OBJS)
	$(CC) $(SERVER) $(S_OBJS)
	@echo -e "\033[32m\t\t\t\t{Server Compiled.}\033[039m"

clean:
	$(RM) $(C_OBJS)
	$(RM) $(S_OBJS)
	cd client_graphique && make clean && cd .. && pwd
	@echo -e "\033[33m\t\t\t\t{Project Cleaned.}\033[039m"

fclean:	clean
	$(RM) $(CLIENT)
	$(RM) $(SERVER)
	cd client_graphique && make fclean && cd .. && pwd
	@echo -e "\033[31m\t\t\t\t{Project Full Cleaned.}\033[039m"

re:	fclean all
	cd client_graphique && make re && cd .. && pwd

rec:	re
	$(RM) $(C_OBJS)
	$(RM) $(S_OBJS)
	@echo -e "\033[33m\t\t\t\t{Project Cleaned.}\033[039m"

debug:	CFLAGS += -g
debug:	re
