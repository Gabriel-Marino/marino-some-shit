ed:	clean
	@gcc -O3 src/v0_sphere.c src/op.c -static -lgsl -lgslcblas -lm -o sphere.out

clean:
	@clear
	@rm *.out
	@rm *.pdf
	@rm *.mp4
	@rm *.gif
	@rm dat/*.dat
	@rm plt/*.png

video:
	@ffmpeg -r 29 -i plt/%d.png -c:v libx264 -profile:v baseline -level 3.0 -pix_fmt yuv420p -y cm.mp4