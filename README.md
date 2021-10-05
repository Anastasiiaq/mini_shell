# 🐚 minishell

``🐚 minishell`` is a team project. It's a simple shell like a little bash.

### Usage
Using ``make`` will create the ``minishell`` executable.

Simply run it with :

```
./minishell
```

### Available options

minishell can search and launch the right executable based on the PATH variable or by using relative or absolute path (``/bin/ls`` or ``ls``).

minishell stores the history of executed commands, use the arrows (``↑↓``) to navigate through the history.

``'`` and ``"`` work the same as bash, except for multiline commands.

You can use redirections ``>`` ``>>`` ``<`` and ``pipes |``. As well as minishell can work with here-document structure (``<<``).

Environment variables are handled, like ``$HOME``, including the exit status ``$?``.

Also, using a minishell, you can use ``Ctrl-C`` to interrupt and ``Ctrl-\`` to exit the program, as well as ``Ctrl-D`` to start ``EOF``, as in bash.

There are several "built-in" functions implemented in the minishell, which means we are not calling the executable file, we have recoded them directly. 
This applies to ``echo``, ``cd``, ``pwd``, ``export``, ``unset``, ``env`` and ``exit``.
