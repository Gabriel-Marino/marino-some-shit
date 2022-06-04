ed:	clean
	@gcc -O3 src/main.c -static -lgsl -lgslcblas -lm -o pi.out

video:
	@ffmpeg -r 29 -i plt/phi-%d.png -c:v libx264 -profile:v baseline -level 3.0 -pix_fmt yuv420p -y pi.mp4

clean:
	@rm -f dat/*.dat
	@rm -f *.out
	@rm -f plt/*.png
	@clear