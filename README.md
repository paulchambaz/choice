# choice

## About

choice is a tiny program that takes an input from stdin, prints a selection menu and prints the output to stdout.
This tool is intended for piping and redirection.

For example, with my tool [twitch cli](https://gitlab.com/Paul-Chambaz/twitch-cli).
```
twitch-cli $(twitch-cli -l | choice)
```
This command will start a stream without leaving the terminal.

It is very similar to tools like dmenu or fzf, but it stays in the terminal.

## Installation

```
git clone https://gitlab.com/Paul-Chambaz/choice
cd choice/build
sudo make clean install
```

## License

This project is licensed under the GPLv2 license.
For more information, read the LICENSE file.
