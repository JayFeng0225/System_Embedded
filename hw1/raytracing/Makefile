EXEC = raytracing
.PHONY: all
all: $(EXEC)

CC ?= gcc
CFLAGS = \
	-std=gnu99 -Wall -O0 -g -fopenmp
LDFLAGS = \
	-lm -lgomp

ifeq ($(strip $(PROFILE)),1)
PROF_FLAGS = -pg
CFLAGS += $(PROF_FLAGS)
LDFLAGS += $(PROF_FLAGS) 
endif

OBJS := \
	objects.o \
	raytracing.o \
	main.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: use-models.h
use-models.h: models.inc Makefile
	@echo '#include "models.inc"' > use-models.h
	@egrep "^(light|sphere|rectangular) " models.inc | \
	    sed -e 's/^light /append_light/g' \
	        -e 's/light[0-9]/(\&&, \&lights);/g' \
	        -e 's/^sphere /append_sphere/g' \
	        -e 's/sphere[0-9]/(\&&, \&spheres);/g' \
	        -e 's/^rectangular /append_rectangular/g' \
	        -e 's/rectangular[0-9]/(\&&, \&rectangulars);/g' \
	        -e 's/ = {//g' >> use-models.h

check: $(EXEC)
	@./$(EXEC) && diff -u baseline.ppm out.ppm || (echo Fail; exit)
	@echo "Verified OK"

gprof : $(EXEC)
	./raytracing 
	 gprof -b raytracing gmon.out > prof_output
	gprof ./raytracing | ./gprof2dot.py | dot -Tpng -o output.png

plot: output.txt
	gnuplot scripts/runtime.gp

clean:
	$(RM) $(EXEC) $(OBJS) use-models.h \
		out.ppm gmon.out prof_output output.png runtime.png
