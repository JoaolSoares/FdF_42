<p align="center">
    <img src="https://game.42sp.org.br/static/assets/achievements/fdfm.png">
</p>

<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/tokei/lines/github/JoaolSoares/FdF_42?color=critical">
    <img src="https://img.shields.io/badge/Language-C%20%7C%20C%2B%2B-orange.svg" alt="Language">
    <img src="https://img.shields.io/badge/Grade-120%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

# FdF
The fifth project from 42<br>
FdF is a 42 school project whose goal is to create a isometric projection based on a map.<br>
The program will display different isometric projections and allow the user to zoom, move, change perspective and 
relief.

## How to use

- Clone the repository
- You need to use [MiniLibX](https://github.com/42Paris/minilibx-linux)
- Run `make` to compile the executable
- Run `./fdf [map].fdf` to execute the program

## Install MiniLibX
- Clone the repository with `https://github.com/42Paris/minilibx-linux.git`
- Run `make` to compile the library need to install libbsd-dev libXext-dev
- Copy the library `libmlx.a` from the root of the home directory
- Copy the header file `mlx.h` from the root of the home directory
```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```
```bash
cp libmlx.a /usr/local/lib/
```
```bash
cp mlx.h /usr/local/include/
```

## Controls
The following controls are available:
<table>
  <tr><td><strong>Controls</strong></td><td><strong>Action</strong></td></tr>
  <tr><td><kbd>&nbsp;▲&nbsp;</kbd><kbd>&nbsp;◄&nbsp;</kbd><kbd>&nbsp;▼&nbsp;</kbd><kbd>&nbsp;►&nbsp;</kbd></td><td>Move</td></tr>
  <tr><td><kbd>&nbsp;scroll wheel&nbsp;</kbd></td><td>Zoom in and out</td></tr>
  <tr><td><kbd>&nbsp;l&nbsp;</kbd> or <kbd>&nbsp;o&nbsp;</kbd></kbd></td><td>Change the relief</td></tr>
  <tr><td><kbd>&nbsp;p&nbsp;</kbd></kbd></td><td>Change the projection to parallel</td></tr>
  <tr><td><kbd>&nbsp;i&nbsp;</kbd></kbd></td><td>Change the projection to isometric</td></tr>
  <tr><td><kbd>&nbsp;esc&nbsp;</kbd> or close window</td><td>Quit FdF</td></tr>
</table>


## Example
Display the 42_color projection
```bash
./fdf maps/42_color.fdf
```
![image](https://github.com/JoaolSoares/FdF_42/assets/87624275/441cf711-2364-49ba-8d06-8417e76411b8)

Display the Julia projection
```bash
./fractol maps/julia.fdf
```
![image](https://github.com/JoaolSoares/FdF_42/assets/87624275/2eafa225-5d02-48d6-a842-f5666fede86f)

Display the t1 projection
```bash
./fractol maps/t1.fdf
```
![image](https://github.com/JoaolSoares/FdF_42/assets/87624275/82c04115-1746-49c5-a990-385737ced595)
