# aixdeb

Aixcoin Script debugging utilities.

This is a set of tools used to debug or construct scripts for use in Aixcoin.

[![Build Status](https://travis-ci.org/aixcoin-core/aixdeb.svg?branch=master)](https://travis-ci.org/aixcoin-core/aixdeb)

## Preparation

Mac users need the macOS command line tools:

```
xcode-select --install
```

And [Homebrew](https://brew.sh/).

## Dependencies

aixdeb depends on the following:

- libtool
- libssl
- automake/autoconf
- pkg-config

Ubuntu/debian users can do: `apt-get install libtool libssl-dev autoconf pkg-config` (with `sudo` prepended if necessary)

Mac users can do: `brew install libtool automake pkg-config`

## Installation

On linux or mac, grab the source code and do:

```Bash
$ ./autogen.sh
$ ./configure
$ make
$ sudo make install
```

Or use **docker**:

```Bash
docker build -t aixdeb .
docker run -d -t --name aix-vm aixdeb aixdeb
# and for run it in the shell
docker exec -it aix-vm /bin/sh
```

If any of those give an error, please file an issue and I'll take a look. It could
be a dependency that I forgot about.

## Emscripten

You can compile aixdeb tools into JavaScript using [emscripten](http://kripken.github.io/emscripten-site/).

After installing the SDK, compile aixdeb tools with the following commands:

```Bash
$ make clean
$ emconfigure ./configure
$ emmake make
$ for i in aixdeb aixc tap; do mv $i $i.bc && emcc -O2 $i.bc libaixcoin.a -o $i.js; done
```

and then instead of doing `./aixdeb` you do `node aixdeb.js` (or `mastify.js`, etc).

The last part is done because emscripten's `emcc` expects the input bytecode file to have the `.bc` extension, whereas the makefile generates files with no extension.

Note: most things work, but the console in aixdeb does not. You can work around this by doing `echo -n -e "step\n\n\n"` (with sufficient `\n`s).

## Script debugger

The `aixdeb` command can step through a Aixcoin Script and show stack content and operations on a per op level. See [doc/aixdeb.md](doc/aixdeb.md) for details on usage.

## Script compiler

The `aixc` command can interpret a script in its human readable form and will
return a corresponding Aixcoin Script.

```Bash
$ aixc OP_DUP OP_HASH160 897c81ac37ae36f7bc5b91356cfb0138bfacb3c1 OP_EQUALVERIFY OP_CHECKSIG
76a914897c81ac37ae36f7bc5b91356cfb0138bfacb3c188ac
```

The above is the script pub key for a transaction in Aixcoin in human readable format turned into its hexadecimal representation.
