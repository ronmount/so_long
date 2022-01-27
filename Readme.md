<h1>42 project: so_long</h1>

<h3>Goal of the project</h3>
The main goal of the project is to create a small 2D game using the Minilibx library.

<h3>Building</h3>
```shell
git clone https://github.com/ronmount/so_long/archive/master.zip
```
Mandatory:
```shell
make
```
Bonus:
```shell
make bonus
```

Run:
```shell
./so_long maps/map1.ber
```
It works natively on MacOS (tested on Intel Mojave and M1 Monterey), behaviour on any other OS is undefined. =)

There are two separate makefiles, so if you want to build mandatory and bonus you need to change both makefiles (maybe other flags to compile).

<h3>Gameplay</h3>
WASD, Esc to quit. </br>
Your goal - collect all pepes and go through exit using the door. (And do not touch Enemy aka TIJ!)

<h3>Example</h3>

<img src="https://tlgur.com/d/8l6KqZDg">


<h3>Problems</h3>
I admit that there are architectural problems in the project and maybe not very clean main.c and the names of other *.c files. But now it doesn't matter, and maybe I'll make changes later.</br>
Also there are two annoying black lines crossing the window, but it is MLX bug.