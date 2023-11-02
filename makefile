all:
	mkdir -p bin
	gcc main.c ./funcs/*.c -I include -o bin/saida.exe
  
run:
	./bin/saida.exe

clean:
	rm -rf bin


