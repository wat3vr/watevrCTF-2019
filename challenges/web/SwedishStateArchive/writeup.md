# Swedish State Archive

First off, if we look at the source of the main page, we can see that it has a tag
`<meta name="author" content="web_server.py">`. If we look at `/web_server.py`, we can see that
it contains a check `if "logs" in path or ".gti" in path:`, which of course was ment to block
access to the `.git` folder. If we try to access it though, we are presented with the message
`This server is not configured to display folders.`. However, this means that the folder does
exists, and is accessible, only that we can't know the content of each directory.

Knowing the structure of a `.git/` folder, we can start by looking at the `./git/HEAD` file.
It contains `ref: refs/heads/master`. If we look at that file we get the hash of the HEAD
commit. Every git object is stored in the following way:
`.git/objects/<first two chars of hash>/<rest of hash>`. These objects are compressed using
zlib compression, which the shell utility `pigz` can decode.

Doing this reveals the content of the latest commit, meaning we can see the commit message
and the parent of the commit. Going up to the parent commit, and then to its' parent and so
on, we eventually reach a commit with a message saying that `flag.txt` was added. If we look
at the tree of the commit, we can see that there is a `flag.txt` file. We can access by
it by its' hash given in raw ascii in the tree object. Reading the content of the file gives
us the flag.