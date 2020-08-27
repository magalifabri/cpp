NAME 		=  whatever.out

SRC_DIR 	= ./
SRC_FILES 	= whatever.cpp

OBJ_DIR 	= ./obj/
OBJ_FILES 	= $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

INC_FILES	=

CC 			= clang++
CFLAGS 		= -Wall -Wextra -Werror

RM 			= /bin/rm -f
RMDIR 		= /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_FILES) $(INC_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

# make OBJ_DIR for NAME dependency
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

# make .o files for NAME dependency
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ_FILES)
veryclean: clean
	$(RMDIR) $(OBJ_DIR)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY : all clean fclean re