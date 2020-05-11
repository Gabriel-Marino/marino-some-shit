ed:
	@gcc -O3 src/v1_square.c src/op.c -static -lm -o serie.out

clean:
	@clear
	@rm dat/*.dat
	# @rm *.gif
	@rm *.out
	# @rm *.pdf
	# @rm plt/*.png
	# @rm *.mp4

video:
	@ffmpeg -r 2 -i plt/square-%d.png -c:v libx264 -profile:v baseline -level 3.0 -pix_fmt yuv420p -y quadrado.mp4

gif:
	@ffmpeg -ss 61.0 -t 2.5 -i quadrado.mp4 -f gif qua.gif