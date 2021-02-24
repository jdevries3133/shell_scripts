# My Shell Scripts

Each script has a comment at the top explaining what it does. These are all
very small bash or python scripts that I like to use.

## Setup

Add `export PATH=$PATH:/path/to/this/repo` to your environment setup file
(~/.bashrc for bash, ~/.zshenv for zsh, etc.). Then, you'll be able to call
any of these scripts by name in your terminal.

## Compilation

I recently started learning C and adding some things written in C. They are
easy to setup!

```bash
cd src
make
```

The compiled binaries will be dumped into the project root directory which
should also be in your `$PATH` already. To delete the compiled binaries:

```bash
cd src
make clean
```
