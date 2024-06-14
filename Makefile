#################### Utils ##################################################
CC = cc

CFLAGS = -Wall -Wextra -Werror

PRINTF = ./printf/libftprintf.a

LIBFT = ./libft/libft.a
#################### Variable Of Mandatory Parts ############################
SERVER = server

CLIENT = client

HEADER = minitalk.h

SERV_SRC = server.c

CLIENT_SRC = client.c

OBJS_CL = $(CLIENT_SRC:.c=.o)

OBJS_SER = $(SERV_SRC:.c=.o)
#################### Variable of Bonus Parts ###############################
B_SERVER = server_bonus

B_CLIENT = client_bonus

B_HEADER = bonus/minitalk_bonus.h

B_SERVER_SRC = bonus/server_bonus.c

B_CLIENT_SRC = bonus/client_bonus.c	bonus/utils.c

B_OBJ_CL = $(B_CLIENT_SRC:.c=.o)

B_OBJ_SV = $(B_SERVER_SRC:.c=.o)

all: $(SERVER) $(CLIENT)

ifeq ($(MAKCMDGOALS), bonus)
%.o: %.c $(B_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
else
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
endif
#################### Mandatory #################################################
$(SERVER): $(OBJS_SER) logo
	@echo "\033[0;32m \n building server, please wait...\n\033[0m"
	@make -C ./libft
	@make -C ./printf
	@($(CC) $(CFLAGS) $(OBJS_SER) $(LIBFT) $(PRINTF) -o $(SERVER))
	@echo "\033[0;33m \n SERVER built \n\033[0m"

$(CLIENT): $(OBJS_CL)
	@echo "\033[0;32m \n building client, please wait...\n\033[0m"
	@($(CC) $(CFLAGS) $(OBJS_CL) $(LIBFT) $(PRINTF) -o $(CLIENT))
	@sleep 1
	@echo "\033[0;33m \n CLIENT built \n\033[0m"
#################### Bonus ####################################################
bonus: mess $(B_SERVER) $(B_CLIENT)

$(B_SERVER): $(B_HEADER) $(B_OBJ_SV)
	@make -C ./libft
	@make -C ./printf
	@($(CC) $(CFLAGS) $(B_OBJ_SV) ./libft/libft.a ./printf/libftprintf.a -o $(B_SERVER))

$(B_CLIENT): $(B_HEADER) $(B_OBJ_CL)
	@sleep 1
	@($(CC) $(CFLAGS) $(B_OBJ_CL) ./libft/libft.a ./printf/libftprintf.a -o $(B_CLIENT))
	@echo "\033[0;33m \n =>=>=> Bonus Parts Built <=<=<= \n\033[0m"
#################################################################################
mess:
	@echo "\033[0;32m \n Building Bonus Parts...\n\033[0m"
	@sleep 1
logo:
	@printf "\033[0;32m \n    ▄▄▄▄███▄▄▄▄    ▄█  ███▄▄▄▄    ▄█      ███        ▄████████  ▄█          ▄█   ▄█▄  "
	@printf "\033[0;32m \n  ▄██▀▀▀███▀▀▀██▄ ███  ███▀▀▀██▄ ███  ▀█████████▄   ███    ███ ███         ███ ▄███▀  "
	@printf "\033[0;32m \n  ███   ███   ███ ███▌ ███   ███ ███▌    ▀███▀▀██   ███    ███ ███         ███▐██▀    "
	@printf "\033[0;32m \n  ███   ███   ███ ███▌ ███   ███ ███▌     ███   ▀   ███    ███ ███        ▄█████▀     "
	@printf "\033[0;32m \n  ███   ███   ███ ███▌ ███   ███ ███▌     ███     ▀███████████ ███       ▀▀█████▄     "
	@printf "\033[0;32m \n  ███   ███   ███ ███  ███   ███ ███      ███       ███    ███ ███         ███▐██▄    "
	@printf "\033[0;32m \n  ███   ███   ███ ███  ███   ███ ███      ███       ███    ███ ███▌    ▄   ███ ▀███▄  "
	@printf "\033[0;32m \n   ▀█   ███   █▀  █▀    ▀█   █▀  █▀      ▄████▀     ███    █▀  █████▄▄██   ███   ▀█▀  "
	@printf "\033[0;32m \n                                                               ▀           ▀          \n\033"

clean:
	@(make clean -C ./libft)
	@(make clean -C ./printf)
	@(rm -rf $(OBJS_CL) $(OBJS_SER) $(B_OBJ_CL) $(B_OBJ_SV))
	@sleep 1
	@echo "\033[0;31m \n All OBJ file cleaned \n\033[0m"

fclean: clean
	@make fclean -C ./libft
	@make fclean -C ./printf
	@rm -rf $(SERVER) $(CLIENT) $(B_SERVER) $(B_CLIENT)
	@sleep 1
	@echo "\033[0;31m \n The Project clean\n\033[0m"

re: fclean all
	@echo "\033[0;36m \n Rebuilding minitalk succed \n\033[0m"
