# pact

This runs another program in such a way that when the calling process dies, a
`SIGTERM` is delivered to the program.

This is useful in command pipelines, shells, process managers and other
situations where an intermediate process recieves a signal and dies, causing
its children to be reattached to PID 1.

## running

```bash
$ make
$ ./pact [-N] path/to/command
```

## options

* `-N` - signal number to send. Default is 15 (`SIGTERM`).

## credits and license

Copyright (c) 2015 Robert Norris. MIT license. See LICENSE.
