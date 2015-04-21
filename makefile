fill: src/main.c
	reset && gcc src/main.c -O3 -lgmp -o bin/fill -g 
windows: src/main.c
	cls && gcc src/main.c -O3 -lgmp -o bin/fill.exe -g

