# tish — a tiny interactive shell

A small Unix-style command shell written from scratch in C.

## Overview

tish reads one line at a time from the terminal and splits it into words. If the first word matches one of the built-in commands, tish runs it directly in its own process. Otherwise, it forks a child process and hands the line off to `execvp`, just like any other Unix shell falls back to programs on the system. Along the way it tracks a little bit of state: how long it has been running, how many non-empty lines it has read, and the last line it executed.

> **Project page:** [https://ryangeislerr.github.io/TISH/](https://ryangeislerr.github.io/TISH/)
>
> ## Build & Run
>
> ```
> make
> ./tish
> ```
>
> ## Built-in Commands
>
> `help` — lists every built-in command with a one-line description.
>
> `exit` — terminates the shell.
>
> `tishtime` — prints how many seconds the shell has been running.
>
> `lines` — prints how many non-empty lines have been entered so far.
>
> `lastcom` — re-parses and re-runs the previous line, if it was a built-in.
>
> `pagesize` — prints the system's memory page size, via `sysconf`.
>
> `maxprocesses` — prints the maximum number of child processes allowed.
>
> `cwd` (planned) — will report the working directory of a given process.
>
> `size` (planned) — will report a process's size in pages.
>
> ## Files
>
> | File | Description |
> | --- | --- |
> | `main.c` | Entry point and the read-parse-dispatch loop |
> | `parse.c` | Splits a raw input line into words |
> | `internalcoms.c` | The built-in command table and its dispatcher |
> | `flags.c` | Handles the `-h`, `-l`, and `-i` command-line flags |
> | `help.c`, `exit_cmd.c`, `tishtime.c`, `lines.c`, `lastcom.c`, `pagesize.c`, `maxprocesses.c` | One file per built-in command |
> | `tish.h`, `internalcoms.h`, `flags.h` | Shared declarations and the `Command` struct |
> | `Makefile` | Builds the binary and packages the source for submission |
>
> ## Author
>
> Ryan Geisler — [github.com/ryangeislerr/tish](https://github.com/ryangeislerr/tish)
> 
