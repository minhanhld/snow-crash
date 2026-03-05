There's nothing in the home folder, no interesting files that flag14 or level14 could execute.
Let's take a look at the getflag binary with ghidra
We can see that it uses a ft_des function to basically decrypt the tokens that are hardcoded in the main function.
We can take a look at the ft_des function and try to reproduce it in C.

So pcVar2 contains param_1 which basically is the encrypted token.
pcVar4 points to that same pointer.

uVar3 = 0xffffffff;
pcVar4 = pcVar2;
do {
	if (uVar3 == 0) break;
	uVar3 = uVar3 - 1;
	cVar1 = *pcVar4;
	pcVar4 = pcVar4 + (uint)bVar5 * -2 + 1;
} while (cVar1 != '\0');
    if (~uVar3 - 1 <= local_20) {
      return pcVar2;
	}

cVar1 is the current character the the pointer is pointing on

pcVar4 = pcVar4 + (uint)bVar5 * -2 + 1;

Since bVar5 is set to 0 and never changes, this line can simply be translated to :

pcVar4 = pcVar4 + 0 + 1 = pcVar4 + 1;

uVar3 is set to UINT_MAX, meaning all its 32 bits are set to 1.
uVar3 acts like a counter, decrementing by 1 in each iteration.
After the loop, we apply the bitwise NOT operator on uVar, fliping every bit.
We have at the end of the loop : uVar3 = 0xFFFFFFFF - N, N being the number of iterations, which is basically the length of the string.

When doing 0xfffffff - N, we're flipping all the bits of N, so we basically have  uVar3 = 0xFFFFFFFF - N = ~N
Meaning that when running bitwise NOT on uVar3, it's in reality just getting back N : ~uVar3 = ~(~N) = N
But this is the length of our token WITH the NUL character at the end, thus why in the code, it's comparing ~uVar3 - 1, which corresponds to the length of the encrypted token.
After reading the code, we understand that local_20 is simply the index of the current character in the string.

    if (~uVar3 - 1 <= local_20) {
      return pcVar2;
	}

So this condition means to return when the index is equal or superior to the length of the string.
All of this is in reality simply a strlen() of the token.

x & 1 checks the least significant bit of x. If that bit is 1, meaning x is odd, then x & 1 returns 1, else it returns 0.

So we can notice that there are 2 transformations on the current char, one occurs when the index is even (local_20 & 1 == 0)
and one that occurs the rest of the time so when the index is odd.

for (local_14 = 0; local_14 < "0123456"[local_1c]; local_14 = local_14 + 1) {
	pcVar2[local_20] = pcVar2[local_20] + -1;
	if (pcVar2[local_20] == '\x1f') {
	pcVar2[local_20] = '~';
	}
}

We can analyze one of the transformation to understand it, the other one is almost identical.
local_14 is just the index that iterates in the for loop.
"0123456"[local_lc] takes the char in the array that corresponds to the index [local_lc]. So for example if local_lc = 6, then :

"0123456"[local_lc] = '6' = 54

Which is the number of time we will be doing the operation in the for loop.
And that's it, if the index is even, we'll increment the current char by that number, if it's odd, we'll decrement.
And there are 2 conditions in case the char equals 0x1f or 0x7f.


if (local_1c == 6) {
	local_1c = 0;
}

This is to cycle through the array "0123456"


