NAME 		= masters_phonebook

SRC_DIR 	= ./src/
SRC_FILES 	= masters_phonebook.cpp welcome_message.cpp

OBJ_DIR 	= ./obj/
OBJ_FILES 	= $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

CC 			= clang++
CFLAGS 		= -Wall -Wextra -Werror

RM 			= /bin/rm -f
RMDIR 		= /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_FILES) masters_phonebook.hpp
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