EXEC_SEQ = lab_6
SRC_SEQ = $(EXEC_SEQ).c
EXEC_PAR_PT = lab_6_integral_thread
SRC_PAR_PT = $(EXEC_PAR_PT).c
EXEC_PAR_OMP = lab_6_integral
SRC_PAR_OMP = $(EXEC_PAR_OMP).c
CFLAGS_OMP = -fopenmp
CFLAGS_PT = -pthread

all: $(EXEC_SEQ) $(EXEC_PAR_PT) $(EXEC_PAR_OMP)
	./$(EXEC_SEQ)
	./$(EXEC_PAR_PT)
	./$(EXEC_PAR_OMP)

$(EXEC_SEQ): $(SRC_SEQ)
	gcc $< -o $@ -lm

$(EXEC_PAR_PT): $(SRC_PAR_PT)
	gcc $< -o $@ $(CFLAGS_PT) -lm

$(EXEC_PAR_OMP): $(SRC_PAR_OMP)
	gcc $< -o $@ $(CFLAGS_OMP) -lm

clean:
	rm -f $(EXEC_SEQ)
	rm -f $(EXEC_PAR_PT)
	rm -f $(EXEC_PAR_OMP)
