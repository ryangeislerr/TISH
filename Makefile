# build tish by compiling each .c and .h file
tish: main.c parse.c internalcoms.c help.c exit_cmd.c tishtime.c lines.c lastcom.c pagesize.c maxprocesses.c flags.c tish.h internalcoms.h flags.h
	gcc -std=c11 -g -o tish main.c parse.c internalcoms.c help.c exit_cmd.c tishtime.c lines.c lastcom.c pagesize.c maxprocesses.c flags.c

#clean the built program
clean:
	rm -f tish

#build tar file
tar:
	tar -a -cf rjgeisler25.tar Makefile main.c parse.c internalcoms.c help.c exit_cmd.c tishtime.c lines.c lastcom.c pagesize.c maxprocesses.c flags.c tish.h internalcoms.h flags.h