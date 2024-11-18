#!/usr/bin/bash
you=hello
x=you
y=x
z=\$$y
eval u=\$$y

echo $z
echo $u
