all: file_info.c
	      gcc file_info.c


clean:
	      -rm *.out
	      -rm *~
        -rm test.txt

run: all
	      ./a.out
