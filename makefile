default:
	gcc -Wall -o prog main.c listing.c scrape.c
debug:
	gcc -Wall -o prog -g main.c
clean:
	rm -f prog
