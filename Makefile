# Student makefile for Cache Lab
# Change the USER/TEAM to your First_Last 
USER = Jeremiah_Sommerfeld 
VERSION = 1
# Change your icarus server user, ex: hv12345 
ICAUSER = js11224
DEST = "$(ICAUSER)@icarus.cs.weber.edu:/home/hvalle/submit/cs3100/"
#
# Student makefile for Threads
# 
CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g 
# Compiler Flags:
# 		-g			-- Enables debugig
# 		-Wall		-- Turns on all the warnings
# 		-Werror		-- All warnings are errors
# 		-std=c99	-- Use C99 standard
# 		-Wno-pointer-to-int-cast --To suppress warning	
# 									on 32bit systems

all: ta

ta: main.c ta.c mythreads.c
	# Load Threads library:  -lpthread
	$(CC) $(CFLAGS) -o ta main.c ta.c mythreads.c -lpthread  -lm
tar: 
	tar -cv  $(USER)-hw6-$(VERSION).tar .

# info
handin:
	scp $(USER)-hw6-$(VERSION).tar $(DEST)
#
# Clean the src dirctory
#
clean:
	rm -f ta
