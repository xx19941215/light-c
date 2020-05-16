#! /bin/bash

for N in {1..150}
do
    php client.php client.php &
done
wait