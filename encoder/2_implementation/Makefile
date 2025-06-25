flags=-Wall -Wextra
libs=
out=gcc -o 
name=encoder
src=./src/
icd=./include/
build=./build/
target=$(build)$(name)

objs=$(src)main.o  \
	 $(src)log.o   	\
	 $(src)encoder.o \

all: compile clean

compile: $(objs)
	@[ -d "$(build)" ] || { mkdir "$(build)"; }
	$(out)$(target) $(objs) $(flags) $(libs)

clean:
		@rm $(objs)

debug:
	gcc -g $(src)* -o $(target)_d

run: 
	$(target)
