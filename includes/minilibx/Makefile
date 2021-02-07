

SRC= interface.swift
OBJ=$(SRC:.swift=.o)

CFLAGS=-O3

NAME=libmlx.dylib

INC=-I.

all: $(NAME)

$(NAME): $(OBJ)
	@swiftc $(INC) -o $(NAME) -emit-library $(OBJ) -lz

%.o: %.swift
	@swiftc $(INC) -parse-as-library -c $< -o $@

%.swiftmodule: %.swift
	@swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)

clean:
	@rm -f $(NAME) $(OBJ) *.swiftdoc *~

fclaen: clean

re: fclaen all