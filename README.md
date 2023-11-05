# Insertion sort with middle tracking

The Idea comes from a practice in CLRS, stating that whether are we able to reduce time-complexity of insertion-sort by using binary-search instead of linear-search or not. The answer is of course, no.
But what if we could eliminate half of the sorted list? We could compare the element at hand to the middle element of the sorted list and perform insertion sort at **left-end** or **right-end** of the list depending on the comparison result. You might say this is not doable with array since we can't just shift the array to the right and add an element to the left side of it and you are correct, the cost is great. But we can use a linked list to sort the elements; Meaning we would have a linked list as output.

So for example if we have doubly-linked-list of the following sorted elements: `1-3-4-5-6` and we are willing to add `2` to it, we would compare `2` and the middle element (which we are keeping track of in every iteration). `2<4` so we would perform insertion sort in reverse and import `2` at the head of the linked list, `2-1-3-4-5-6`. Then we would move `2` to the right until we hit its place (just like normal insertion sort, but reversed). `1-2-3-4-5-6`.

This saves a couple of steps when `n` is larger.

A few tips about this algo:

- The algorithm is no longer in-place since we are adding a linked list

- Converting linked list to array is fairly cheap time-wise, so we could easily get an array output if memory is not an issue

- Reversed/nearly-reversed lists are also a good scenario for this algorithm whereas in insertion-sort we had to tolerate `n^2`
