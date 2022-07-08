# Memwaste

Waste a specific amount of memory, which is useful to test monitoring,
alterting, and your computer's behaviour when swapping.

Usage (build it and waste 100 megabytes):

    $ make memwaste
    $ ./memwaste 100

Use `pmap` and fellows to check if the memory is _really_ allocated:

    $ ps a | grep -E 'memwaste [0-9]+' | awk '{ print $1 }' | xargs pmap | tail -1 | awk '{print $2}'
