loop forever:
    if interactive:
        print prompt

    read a line

    if EOF:
        break

    if empty line:
        continue

    split into comman + args

    if built-in:
        run built-in directly
    else:
        search PATH

        if found:
            fork
            child: exec
            parent: wait
        else:
            print error

    free this iterations memory
