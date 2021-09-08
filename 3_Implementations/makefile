PROJ_NAME = STEPIN_TIC_TAC_TOE
SRC =  src/good_game.c\

#To check if the OS is windows or linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

all:
	gcc main.c $(SRC) -o $(call FixPath,$(PROJ_NAME).$(EXEC)) -lm

run: all
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

clean:
	$(RM) $(call FixPath,$(PROJ_NAME).$(EXEC))
