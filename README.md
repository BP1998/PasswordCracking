# PasswordCracking
TLDR:
These are brute force attacks on an encrypted Linux password written in parallel.
Cracker.C is worse than RCracker.C
I'm working on an even better version, but a brute force attack is still not an amazing method.

This repository holds a personal project I've been working on in my free time.
In my systems programming class, we were tasked with decoding an encrypted Linux password (like one you could find in the shadow file).
We had to write this as a parallel program, using a single process would give you a 0 for the assignment.
The program I turned in for the class is named Cracker.C and it accomplished the task required by the assignment, but I wasn't satisfied.

I set out to write a better version on a password decoder. I wanted it to be more flexible and quicker. 
This is where I came up with RCracker.C, which used a ripple carry method to get rid of the nested loops.
I also implemented some more command line arguments to allow more flexibility.

I am currently working on a new version of my password decoder.
My goal is to write a reasonably fast implementation of a brute force attack. 
It's worth noting that no matter how well you implement a brute force attack, it's still one of the slowest methods of decoding something.

Note:
  All of these programs are parallel programs meaning they create multiple processes to complete the task faster.
  The function call fork() that I use in these programs is an amazing utility but should be used with caution. 
  If you would like to start writing parallel programs, make sure you fully understand fork and use it in a controlled environment.
  You don't want to accidentally fork bomb a machine you don't own.
