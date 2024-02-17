EXEC_SEQ = seq
SRC_SEQ = $(EXEC_SEQ).c
EXEC_PAR_PT = par_pthreads
SRC_PAR_PT = $(EXEC_PAR_PT).c
EXEC_PAR_OMP = par_openmp
SRC_PAR_OMP = $(EXEC_PAR_OMP).c
CFLAGS_OMP = -fopenmp
CFLAGS_PT = -pthread

all: $(EXEC_SEQ) $(EXEC_PAR_PT) $(EXEC_PAR_OMP)
	./$(EXEC_SEQ)
	./$(EXEC_PAR_PT)
	./$(EXEC_PAR_OMP)

$(EXEC_SEQ): $(SRC_SEQ)
	gcc $< -o $@

$(EXEC_PAR_PT): $(SRC_PAR_PT)
	gcc $< -o $@ $(CFLAGS_PT)

$(EXEC_PAR_OMP): $(SRC_PAR_OMP)
	gcc $< -o $@ $(CFLAGS_OMP)

clean:
	rm -f $(EXEC_SEQ)
	rm -f $(EXEC_PAR_PT)
	rm -f $(EXEC_PAR_OMP)
