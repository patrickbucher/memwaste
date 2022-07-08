.PHONY: clean

memwaste: memwaste.c
	gcc -Wall $< -o $@

clean:
	rm -f memwaste
