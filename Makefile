SNAME = server
CNAME = client

SFILES = src/server.c

CFILES = src/client.c

FILES = ft_atoi.c

FILES := $(addprefix src/, $(FILES))

FLAGS = -Wall -Wextra -Werror

all: $(SNAME) $(CNAME) 

$(SNAME): $(SFILES)
	cc $(FLAGS) $(SFILES) -o $(SNAME)

$(CNAME): $(CFILES) $(FILES)
	cc $(FLAGS) $(CFILES) $(FILES) -o $(CNAME) 

# bonus: $(BNAME)
	
# $(BNAME): $(BFILES)
# 	cc $(FLAGS) $(BFILES) -o $(BNAME) 

clean:
	rm -rf $(CNAME) $(SNAME)

fclean: clean

re: fclean all