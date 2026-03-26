# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

Fractol is a 42 school project — a fractal renderer written in C using MiniLibX (macOS). It renders three fractals: Mandelbrot, Julia, and Mike (a custom variant). The Julia set supports real-time mouse-tracking to adjust parameters.

## Build Commands

- `make` — build the `fractol` binary (also builds libft and minilibx_macos)
- `make clean` — remove object files
- `make fclean` — remove object files and binary
- `make re` — full rebuild

## Running

```
./fractol Mandelbrot
./fractol Julia
./fractol Mike
```

Argument is case-sensitive. No argument or invalid argument prints usage.

## Architecture

All state lives in a single `t_mlx` struct (defined in `fractol.h`) passed by pointer throughout.

- **main.c** — argument parsing (`ft_verif_arg`), MLX window setup, event hook registration, main loop
- **ft_init.c** — initialization functions per fractal type + shared `ft_initialisation`
- **ft_mandelbrot.c / ft_julia.c / ft_mike.c** — per-pixel fractal computation, each split into `ft_<name>` (outer loop) and `ft_<name>_next` (inner iteration)
- **ft_controleur.c** — `ft_print_image`: destroys/recreates image, dispatches to the correct fractal renderer, and blits to window
- **ft_key_event.c** — keyboard handler: arrow movement, color toggling (R/G/B), iteration count, reset
- **ft_mouse_event.c** — mouse handler: zoom (scroll/click), Julia mouse-tracking
- **ft_put_pixel_color.c** — pixel writing to image buffer + color computation

## Dependencies

- **libft/** — custom C standard library (built via its own Makefile)
- **minilibx_macos/** — 42's MiniLibX graphics library (expects macOS frameworks: OpenGL, AppKit)

## Code Style

42 Norminette conventions: 42 header comments, tab indentation, `ft_` prefix on all functions, no more than 25 lines per function, max 4 arguments.
