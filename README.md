_This project has been created as part of the 42 curriculum by tpinto-v, jlandeir._

# Description

Pushswap is a project that makes use of two stacks. Stack A and stack B — the user provides the numbers that should be placed in stack A (stack B is initialized with 0 elements). We then use a set of operations to sort the numbers using various algorithms with their respective time complexities (considering pushswap's operations and not "background" operations), sending elements to stack B from time to time (one of the operations is to pop elements from A and push to B, or conversely) and then bringing those elements back to A.

![Stacks](https://deen3evddmddt.cloudfront.net/uploads/content-images/push-operation.webp)

## Pushswap operations

The possible operations in pushswap are listed below:

| Operation | Description |
|--|--|
| sa | Swap the first element of stack A with the second |
| pa | Pop an element from stack B and push it to stack A |
| ra | Rotate stack A clockwise (shift up all elements by one): the first element becomes the last, and the second element becomes the new first |
| rra | Rotate stack A counterclockwise (shift down all elements by one): the last element becomes the first, and the second-to-last becomes the new last |

There are also `sb`, `pb`, `rb`, `rrb`, which are analogous to the above but for stack B, as well as `ss`, `rr`, and `rrr`, which are `sa + sb`, `ra + rb`, and `rra + rrb`, respectively.

> **Note:** Considering these operations, the "stack" in pushswap is not really a stack — it is more like a deque (Double-Ended Queue). This makes it natural to consider the type of data structure we used, alongside the circular linked list or the doubly linked list.

## Circular array (Ring buffer)

The data structure used in this project is the circular array, a fixed-size buffer where both ends are connected (the beginning to the end). There are various ways to implement it; the one we chose is as follows:

```c
typedef struct	s_stack
{
	int	*array;
	size_t	top;
	size_t	curr_size;
	size_t	max_size;
}	t_stack;
```

where `array` holds the elements, `max_size` is the maximum capacity, `curr_size` is the current number of elements in the buffer (e.g., stack B will have `curr_size = 0` at the start), and `top` is the index of the element at the top of the stack, i.e., the first element.

![ring buffer](https://camera-sdk.com/attachments/6554/circular-buffer-video-recording.jpg)
![ring buffer2](https://blog.pantuza.com/uploads/18268d3eacfe61c84b808a63d3e84030f1f6af65)

The operations over this data structure are fairly straightforward. The swap is done just as with an ordinary array. To pop from one stack and push to the other, we only need to update `curr_size` for both stacks and adjust the `top` index. For rotating, we copy the current top element to the bottom of the array and then update `top` to `(top + 1) % max_size`. This way, the new top index points to what was previously the second element, and we also handle the case where `top + 1` would equal `max_size` (wrapping around). In our implementation we ensured the remainder never takes a negative value.

![rotate buffer](https://miro.medium.com/v2/resize:fit:710/1*ogvk4qRAcCYr-dPOPSXPJg.png)

## Algorithms and details

### Time complexity and Big O notation

The Big O notation is derived from the term "order of approximation." It serves as a way to evaluate how **scalable** an algorithm is — how it behaves as the amount of data grows — which is why it is referred to as an asymptotic notation. When analyzing time complexity, we look at the order of the number of operations an algorithm performs. For instance, an algorithm might require 100 operations to sort a reversed list of 10 numbers, and 1000 operations for 100 numbers. In other words, the number of operations `f` is a function of `n`, the number of elements: `f(n) = 10n`. When analyzing the algorithm, we consider increasingly larger inputs, so it is convenient to use Big O notation as follows:

Let `f` be a function to be estimated, defined on a domain `D`, and let `g` be a non-negative real-valued comparison function defined on the same domain `D`. We write that `f(x)` is Big O of `g(x)` as:

```
f(x) = O(g(x))
```

which means there exists a positive real number `M` such that:

```
|f(x)| ≤ M · g(x)  for all x in D.
```

![big O](https://media.geeksforgeeks.org/wp-content/uploads/20240329121512/big-o-image.webp)

To illustrate what this definition means, consider the earlier example:

- `f(n) = 10n` → `f(n) = O(n)` with `g(n) = n` and `M = 10`

Another example: `f(n) = n² + 5n + 4`. For all natural numbers `n`, we have `f(n) ≤ 10n²`, so `f(n) = O(n²)`. In other words, Big O notation keeps only the fastest-growing term.

It is worth noting that `O()` is generally used for the **upper bound**, i.e., the worst case. The best case is denoted `Ω()` (Big Omega), and when both the upper and lower bounds match, `Θ()` (Big Theta) is used.

![big omega](https://media.geeksforgeeks.org/wp-content/uploads/20240329124349/big-omega-image.webp)

The algorithms used in our implementation are insertion sort, bucket sort, and radix sort. Their time complexities are listed below:

| Algorithm | Best case | Average case | Worst case |
|--|--|--|--|
| Insertion Sort | Ω(n²) | O(n²) | O(n²) |
| Bucket Sort | Ω(n + k) | O(n + n²/k + k) | O(n²) |
| Radix Sort | Ω(d · n) | O(d · n) | O(d · n) |

where `n` is the number of elements, `k` is the number of buckets, and `d` is the number of digits of the largest number (in our case, base 2 is used).

Each algorithm is selected via a flag when compiling the program: insertion sort maps to `--simple`, bucket sort to `--medium`, and radix sort to `--complex`.

There is also the `--adaptive` strategy, which automatically selects the algorithm based on the disorder level computed by the `compute_disorder` function:

| Classification | Range | Algorithm chosen |
|--|--|--|
| Low disorder | disorder < 0.2 | `--simple` |
| Medium disorder | 0.2 ≤ disorder < 0.5 | `--medium` |
| High disorder | disorder ≥ 0.5 | `--complex` |

---

### "Insertion" Sort

It is not technically insertion sort — it combines logic from insertion, selection, and bubble sort (the original intent was insertion sort, but the final result ended up as a hybrid).

The core idea is similar to selection sort: first, find the minimum of the stack (without using push_swap operations). If the minimum is in the first half of the stack, rotate until it reaches the top; if it is in the second half, use reverse rotate (to minimize the number of operations). Then pop the minimum from A and push to B. Repeat this process until only one element (the largest) remains in stack A. At this point, stack B is in reverse sorted order, so we simply pop all elements from B back to A.

The time complexity is as follows. In the worst case, pushing the minimum requires at most `n/2 + 1` operations. For the next iteration, `(n-1)/2 + 1`, and so on. Summing up:

```
(1 + 1 + ... [n times]) + (n/2 + (n-1)/2 + ... + 1)
= n + (1/2)(1 + 2 + ... + n)
= n + n(n+1)/4
~ O(n²)
```

---

### Bucket Sort

Bucket sort is an algorithm typically used with floating-point numbers. For example, given the array `{0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68}`, the first step is to create an array of buckets (10 buckets here, one for each first decimal digit):

![array buckets](https://media.geeksforgeeks.org/wp-content/uploads/20230705162208/file.png)

The second step is placing each element in its corresponding bucket based on its first decimal digit — `0.78` goes into bucket 7, `0.17` into bucket 1, and so on.

![elements in bucket](https://media.geeksforgeeks.org/wp-content/uploads/20230705162234/file.png)

Then, each bucket is sorted individually using any O(n²) algorithm such as selection sort, insertion sort, or bubble sort.

![sorting buckets](https://media.geeksforgeeks.org/wp-content/uploads/20230705162300/file.png)

Finally, the buckets are concatenated back into the original array.

![gathering](https://media.geeksforgeeks.org/wp-content/uploads/20230705162320/file.png)

The time complexity is: placing elements into buckets is O(n); sorting each bucket of size `n/k` with an O(n²) algorithm gives O((n/k)²) per bucket, so O(k · (n/k)²) = O(n²/k) total; concatenating is O(k). This gives **O(n + n²/k + k)** on average, and **Ω(n + k)** in the best case (already sorted).

**Adapting bucket sort to pushswap:** Since we work with two stacks of integers rather than floating-point numbers, the approach was adjusted as follows.

We set the bucket size to `√n`, so there are approximately `√n` buckets of size `√n` each. The average complexity becomes:

```
O(n + n²/√n + √n) = O(n · (1 + √n + 1/√n)) → O(n√n)
```

as expected for the pushswap subject. We iterate bucket by bucket (from 0 to `√n`, where `√n` is rounded up to the nearest integer so that `⌈√n⌉² ≥ n`). For each element in the current bucket, we pop it from stack A and push to B; elements not in the current bucket are rotated to the bottom. This leaves the smallest elements at the bottom of B and the largest at the top.

We then sort stack B in **descending order** from top to bottom, so that when we pop all elements from B back to A, stack A ends up in ascending order.

> **Note:** More precisely, on the first bucket pass we perform roughly `n` operations, then `n - n/k`, then `n - 2n/k`, and so on. Summing:
> ```
> n + (n - n/k) + (n - 2n/k) + ... + (n - (k-1)n/k)
> = kn - (n/k)(0 + 1 + ... + (k-1))
> = kn - n(k-1)/2 ~ kn
> ```
> Sorting within B costs O(k · (n/k)²) = O(n²/k), and pushing back is O(n). Total: **O(kn + n²/k + n) = O(n(k + n/k + 1))**, which in our case gives **O(n√n)**.

> **Note 2:** To determine which bucket each element belongs to, stack A is first converted to a **rank array**, where each value is replaced by its position in the sorted order (e.g., `{2, 5, 4, 13, 18, 15}` → `{0, 2, 1, 3, 5, 4}`). This is valid because pushswap only cares about the moves required to sort, not about preserving the original values.

---

### Radix Sort

The idea behind radix sort is straightforward: numbers are sorted **lexicographically**, one digit at a time. In base 10, for example, given `{1, 10, 108, 75, 45, 28, 2}`, the first pass sorts by the units digit: `{10, 1, 2, 75, 45, 28, 108}`. The next pass sorts by the tens digit, and so on, until the most significant digit of the largest number.

For our two-stack implementation, it is natural to use **base 2**. In each pass, we examine one bit of the rank: if the current bit is 0, pop the element from A and push to B; if it is 1, rotate A. After processing all elements, push everything from B back to A. After `d` passes (where `d` is the position of the highest set bit of the largest rank), stack A is sorted.

Using the rank instead of the original value is beneficial because the largest rank is at most `n - 1`, which typically has fewer bits than the largest raw input value — so fewer passes are needed. As a bonus, negative numbers are handled correctly too (at least in terms of the operations required).

**Time complexity:** We need to perform `d₂` passes, where `d₂ = log₂(M)` and `M` is the largest rank. To see why, consider that `M` can be written in binary as:

```
M = aₙ · 2ⁿ + aₙ₋₁ · 2ⁿ⁻¹ + ... + a₀ · 2⁰
```

To find the position `n` of the highest set bit, we perform integer division by `2ⁿ`:

```
M / 2ⁿ = aₙ
```

Since `aₙ = 1` (it is the leading bit), we have `M / 2ⁿ = 1`, which gives `M = 2ⁿ` and therefore `n = log₂(M)`. So we need exactly `d₂ = log₂(M)` passes.

In each pass, we push or rotate all `n` elements and then push them back from B to A — roughly `2n` operations per pass. The total complexity is therefore **O(d₂ · n)**. It can also be shown that for any base `b`, `d₂ ∝ d` where `d` is the number of digits in that base (by the change-of-base formula for logarithms), so this is consistent with the general **O(d · n)** complexity of radix sort.

---

# Instructions

To test the project, run `make` to compile the program. Then run it with:

```bash
./push_swap 5 4 3 2 1
```

By default, the adaptive strategy is used, but you can specify one explicitly:

```bash
./push_swap --adaptive 5 4 3 2 1
./push_swap --simple   5 4 3 2 1
./push_swap --medium   5 4 3 2 1
./push_swap --complex  5 4 3 2 1
```

There is also a `--bench` mode that can be combined with any strategy flag. It outputs to **stderr** (file descriptor 2): the disorder percentage (two decimal places), the strategy name, the total number of operations, and the count of each individual operation (`sa`, `sb`, `ss`, `pa`, etc.). Sending output to stderr means it is not buffered and can be redirected to a log file without interfering with the normal stdout output.

On Linux, you can use the GNU utility `shuf` to generate shuffled inputs. For example:

```bash
shuf -i 0-9999 -n 500 > input.txt
./push_swap --bench $(cat input.txt) 2> bench.txt
```

- `shuf -i 0-9999` generates numbers in the range 0–9999.
- `-n 500` picks 500 of them.
- `> input.txt` saves them to a file.
- `2> bench.txt` redirects stderr (file descriptor 2) to `bench.txt`, capturing all benchmark output there.

---

# Contributions

### jlandeir
- Implemented the **"insertion" sort** algorithm.
- Led the **parsing** implementation, including the key design decisions discussed together: using structs for the strategy pattern and enums for operation types.
- Implemented all **stack movement operations**
- Came up with the idea of using **`√n` as the bucket size**, which set the foundation for the bucket sort structure.
- Discussed the **radix sort** approach together with tpinto-v — reviewing other implementations in different contexts — which led to tpinto-v writing the code; also reviewed the code and helped fix any bugs that appeared.
- Later improved the bucket sort with a more **optimized bucket size** tailored specifically to pushswap's constraints, beyond the initial `√n`.

### tpinto-v
- Refactored parts of the codebase to use the `access_stack` function, improving code clarity.
- Wrote this **README**.
- After jlandeir's `√n` bucket size idea and their joint discussion on how elements would flow through stack B, came up with the final sorting strategy: performing a **reverse sort on stack B** so that popping all elements back to A yields a correctly sorted stack A — keeping the logic clean and the code straightforward.
- Wrote the **radix sort** code after both discussed the algorithm and studied other implementations together.

---

# Resources
- [Wikipedia](https://en.wikipedia.org/) — good reference pages for all algorithms used in this project.

> In this project, LLMs were used only to correct grammar and spelling in this README.
