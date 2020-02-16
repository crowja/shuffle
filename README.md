# shuffle 0.1.0-dev0.

Provides

    int shuffle_array(void *base, size_t nmemb, size_t size);

to shuffle a generic list. For example:

    char *x[] = {"ant", "cat", "dog", "mouse", "zebra"};
    . . .

    shuffle_array(x, 5, sizeof(char *));

