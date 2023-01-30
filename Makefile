SNAME = server
CNAME = client

SBNAME = server_bonus 
CBNAME = client_bonus

SFILES = src/server.c
CFILES = src/client.c

SBFILES = bonus/server_bonus.c
CBFILES = bonus/client_bonus.c

FILES = ft_atoi.c ft_putchar.c ft_putnbr.c ft_isdigit.c ft_error.c ft_strlen.c

FILES := $(addprefix utils/, $(FILES))

FLAGS = -Wall -Wextra -Werror

all: $(SNAME) $(CNAME) 

$(SNAME): $(SFILES)
	cc $(FLAGS) $(SFILES) $(FILES) -o $(SNAME)

$(CNAME): $(CFILES) $(FILES)
	cc $(FLAGS) $(CFILES) $(FILES) -o $(CNAME) 

bonus: $(SBNAME) $(CBNAME)
	
$(SBNAME): $(SBFILES)
	cc $(FLAGS) $(SBFILES) $(FILES) -o $(SBNAME)

$(CBNAME): $(CBFILES) $(FILES)
	cc $(FLAGS) $(CBFILES) $(FILES) -o $(CBNAME) 

clean:
	rm -rf $(CNAME) $(SNAME)

fclean: clean
	rm -rf $(SBNAME) $(CBNAME)
re: fclean all