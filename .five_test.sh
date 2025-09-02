#!/bin/bash

# Loop through all permutations of 0..4
for a in {0..4}; do
  for b in {0..4}; do
    [ "$b" = "$a" ] && continue
    for c in {0..4}; do
      [ "$c" = "$a" ] && continue
      [ "$c" = "$b" ] && continue
      for d in {0..4}; do
        [ "$d" = "$a" ] && continue
        [ "$d" = "$b" ] && continue
        [ "$d" = "$c" ] && continue
        for e in {0..4}; do
          [ "$e" = "$a" ] && continue
          [ "$e" = "$b" ] && continue
          [ "$e" = "$c" ] && continue
          [ "$e" = "$d" ] && continue

          # Build the input string
          input="$a $b $c $d $e"

          # Feed into push_swap and count lines
          echo -n "$input: "
        done
      done
    done
  done
done
