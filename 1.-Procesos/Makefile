# objetivo: dependencia(s)
# <tab>	cmd1
# <tab> cmd2
# .

todos: ejemplo1 ejemplo2 mem_compartida_ejemplo.c

ejemplo1: ejemplo1.c
	gcc ejemplo1.c -o ejemplo1
	echo "termino de compilacion ejemplo1"

ejemplo2: ejemplo2.c
	gcc ejemplo2.c -o ejemplo2
	echo "termino de compilacion ejemplo2"

mem_compartida_ejemplo: mem_compartida_ejemplo.c
	gcc mem_compartida_ejemplo.c -o mem_compartida_ejemplo
