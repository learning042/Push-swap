_This project has been created as part of the 42 curriculum by tpinto-v, jlandeir._

#Description

Pushswap is a project that we use make use of two stacks. A stack a and a stack b, firstly the user givesthe numbers that we should put in the stack a(stack b is initialized with 0 elements), then we make use of some operations for sorting the numbers in various algorithms with their respective time complexity(considering pushswap's operations and not "background" operations), sending time to time elements to the stack b(so as in the image below one of the operations is to pop the elements from a and push to b, or conversily) and taking those elements back to a.

![Stacks](https://deen3evddmddt.cloudfront.net/uploads/content-images/push-operation.webp)

## Pushswap operations

The possible operations in pushswap are listed below:

Operation | Description
--|--
sa | Swap first element of the stack a with the second
pa | Pop element from stack b and push it to stack a
ra | Rotate stack a clockwise, i.e., take the first element and put it on the bottom and the last elementon the top r
rra | Reverse rotate of stack a, i.e., counterclockwise

and also sb, pb, rb, rrb that are analogous to the above but with stack b and also ss, rr, rrr that are sa + sb, ra + rb, rra + rrb , respectively. 

Note: Considering these operations, the "stack" of the pushswap is not a stack, it is more like a deque(Double-Ended Queue). Therefore it becomes kind of natural to consider the type of data structure that we did, besides the circular linked list or the double linked list. 

## Circular array (Ring buffer)

The data structure used in this project was the circular array that is a fixed-size buffer where we connect both ends (the beginning to the end). There are various ways to implement it, the one considered is asfollows: 

`typedef struct	s_stack
{
	int	*array;
	size_t	top;
	size_t	curr_size;
	size_t	max_size;
}	t_stack;
`
where we have an array with a maximum size max_size, curr_size("current size", the amount of elements in currently in the buffer, e.g., the stack b will have curr_size = 0 in the beginning). and the top is the index of the element on the top of the stack, i.e., currently the first element.

![ring buffer](https://camera-sdk.com/attachments/6554/circular-buffer-video-recording.jpg)
![ring buffer2](https://blog.pantuza.com/uploads/18268d3eacfe61c84b808a63d3e84030f1f6af65)

So in the way this data structure works, it is kind of straightforward how its operations can be done. For doing the swap is the same of doing to a ordinary array, to pop from one stack and push to the other, we just need to update the current size of both stacks and change the top value and for rotating, it is just necessary to change the value o the bottom most element in the array to the current top element and then change the variable top value to the remainder (top + 1) % max_size(actually in our code we made a way to make sure this remainder wouldnt have negative value in some cases that would have), in this way the top index will become the first element(that was the second previously) and we deal with cases that the top index is in the bottom of the array(i.e., top + 1 could be equal to the max_size.  

![rotate buffer](https://miro.medium.com/v2/resize:fit:710/1*ogvk4qRAcCYr-dPOPSXPJg.png)

## Algorithms and details

### Time complexity and big O notation

The big O notation is derived from the term "order of approximation". It serves as a way to see how much your algorithm is "scalable"(how it works when the number of data dealt grow more and more, that's why it is referenced as an assyntotic notation). When it comes to time complexity, what we are seeing the order of operations that the algorithm is dealing with. So for instance, an algorithm could give 100 operations for sorting a reversed list of 10 numbers and in the same way could give 1000 operations for 100 numbers. In other words, the number of the operations f in this example is a function of the number n of elements in the list f(n) = 10n. When analyze the algorithm, we are considering bigger and bigger numbers in the list, so itis more convenient to consider the big O notation in this case as follows: 

Let f be a function to be estimated and defined in the domain D and let g be a non-negative real valued comparison functoin that is defined in the same set D. We can write that f(x) is big O of g(x) in the following way: 

f(x) = O(g(x))

and this means that there exists a positive real number M such that: 

|f(x)| <= Mg(x) for all x in D.

![big O](https://media.geeksforgeeks.org/wp-content/uploads/20240329121512/big-o-image.webp)

For examplify what this math definition means, we can use the example done before:

f(n) = 10n --> f(n) = O(n) with g(n) = n and M = 10

another example could be with f(n) being f(n) = n^2 + 5n + 4, considering n being a natural number, we have that f(n) >= -10n^2 and f(n) <= 10n^2 always. So f(n) = O(n^2) in this case. In other words, we are always carrying the term that grows faster in such notation.

It is good to take in account that the O() is generally used for the the upper_bound, i.e, the worst case of the algorithm. When it comes to the best case, it is used the symbol \Omega() and when both lower and upper bound are equal, it is used \Theta().  

![big omega](https://media.geeksforgeeks.org/wp-content/uploads/20240329124349/big-omega-image.webp)

The algorithms that were used in our case was insertion sort, bucket sort and radix sort. Their time complexities are listed below:

Algorithm | Best case | Average Case | Worst case
--|--|--
Insertion Sort | Omega(n^2) | O(n^2) | O(n^2)
Bucket Sort | Omega(n + k) | O(n + n^2/k + k) | O(n^2)
Radix Sort | Omega(d * n) | O(d * n) | O(d * n)

being n the number of operations, k the number of buckets, d the number of digits of the biggest number and b the numeric base considered(in our case, as you will see, base 2). 

For each algorithm in the pushswap it will receive a flag when compiling the program. The insertion sort will be the "simple" strategy (--simple), bucket sort is the medium (--medium) and radix sort is the complex strategy(--complex). 

### "Insertion" sort

It is not technically a insertion sort, it is more like a little of the logic in the insertion combined with selection and bubble(well for me it is like a selection implementation but for my partner, he first tried to implement as insertion and ended up with a combinations).

This sorting is basically a very natural idea like selection sort, you first find the minimum of the stack(without push_swap operations), then if the minimum is in the first half of the stack, you rotate until you get it on the top and if it is in the second half you do reverse rotate(this part is for doing less operations). Then you pop from a the minimum and throw on b. After it you try to find the minimum of the current stack a and do the same process again. You repeat this process until the stack a is with just one element(the greatest one). Finally you have a reversed sorted stack b and you just need to pop the elements and push to a. 

The time complexity is straightforward. For pushing the minimum you will need in the worst case n/2 + 1 operations. Next time you will need (n - 1)/2 + 1 and so on. So you have: 

(1 + 1 + ... n times) + (n/2 + (n-1)/2 + ... + 1) = n + n/2 * n - 1/2 (1 + 2 + 3 + .... + (n - 1))  n + n^2/2 - n * (n-1) / 2  = 3n/2 \alguma conta errada que eu fiz

### Bucket Sort

Bucket sort is an algorithm that is generally used with floating-point numbers. So for instance, an array{0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68}. The first step is creating arrays of buckets, in this case you can have elements from 0 to 9 in the second decimal place, so each bucket has size 10(of course, in pushswap we can optimize such thing, because we are only worried about pushswap's operations):  

![array buckets](https://media.geeksforgeeks.org/wp-content/uploads/20230705162208/file.png)

The second step is putting each element in their respective bucket. Just need to see the first decimal place. So 0.78 would be in the bucket 7, 0.17 in the bucket 1, and so on so forth. 

![elements in bucket](https://media.geeksforgeeks.org/wp-content/uploads/20230705162234/file.png)

After that we just need to sort the element in each bucket. It can be any algorithm, like O(n^2) algorithms as selection sort, insertion sort, bubble sort, etc. 

![sorting buckets](https://media.geeksforgeeks.org/wp-content/uploads/20230705162300/file.png)

and finally gather the elements in the original array

![gathering](https://media.geeksforgeeks.org/wp-content/uploads/20230705162320/file.png)

Notice that the time complexity of bucket sort is straightforward, for putting the elements in the buckets in the beginning we do a number of operations that is in the order of n, for sorting each bucket we use an algorithm O(n^2), but it is already divided in buckets, we technically sort each bucket with size n/k, so for each bucket O((n/k)^2) being n the size of and then you concatenate the buckets O(k). So in the end you have O(n + k(n/k)^2 + k) = O(n + n^2/k + k) in average and if it is already sorted , you dont need to sort with O(n^2) algorithm, you just check once(which is a O(n) operation) so you get Omega(n + k).

For the pushswap, we need to change how the things work since we are using 2 stacks and integers instead of floats. In this way, the solution for that was:

First we choose the size of each bucket being the square root of the stack a maximum size, in this way, we can ensure that we have in average sqrt(n) buckets with each of them sqrt(n). Then our bucket sort would be in average O(n + n^2/sqrt(n) + sqrt(n)) = O(n(1 + sqrt(n) + 1/sqrt(n))) --> O(nsqrt(n)) time complexity as expected in the pushswap's subject. After that, we just need to do one iteration at a time for each bucket(from 0 to bucket = sqrt(n), the sqrt was calculated with approximation for being sqrt(n) * sqrt(n) = n if n is a perfect square or we approximate up , i.e., next integer that the square is bigger than the n for instance sqrt(2) is approximally 1.41, we would approximate it to 2), when an element is in the current bucket we pop from stack a and push to b, and if the element is not in the current bucket, we rotate the stack a(putting this element on the bottom). As it can be seen in this way, we have the smaller elements on the bottom of stack b and the bigger ones on the top. Now we just need to do a reverse sort, i.e., we sort the element of stack b in a way that from the top to the bottom of the stack b, the order is descending. In this way, after sorting in this way, we just need to pop from top to bottom the elements in stack b and push to stack a, so in the end all  the elements in stack a are sorted as we wanted.

Note: technically, for being more precise, first we have something of the order of n for pushing to b, but we do for each bucket. So saying that there is the same amount of numbers for each bucket. We have first something like n operations, then we have n - n/k operations, then n - 2n/k and so on. Doing the calculation we have the sum: 

n + (n - n/k) + (n - 2n/k) + ... + (n - (k - 1)n/k) = kn + k(k - 1)n/2k = kn - (k - 1)n/2 ~ kn

for making the sorting on the stack b, it is in the order of  k * (n/k)^2 = n^2 / k. And then for pushing n, so we have O(kn + n^2 / k + n) = O(n(k + n / k + 1)), so in our case O(nsqrt(n)) as we wanted.  

Note2: For being able to know in what bucket each element of the array would be. We changed the stack a to the stack of ranks, this means that the array will have the position that each number would have in the sorted array(e.g., {2, 5, 4, 13, 18, 15} --> {0, 2, 1, 3, 5, 4}). We can do it because the pushswap project only cares about the moves that are necessary to sort the array, not necessarily that we are able to print our input numbers on the screen.  

### Radix Sort

The idea of radix is straightforward, we sort the numbers in the array lexographically. So we compare digits at a time(considering a implementation with base 10). So for instance, if we have an array {1, 10, 108, 75, 45, 28, 2}. The first step is seen the unit digit(so for instance 10<u>8</u> would be sorted based in the digit 8), so after sorting we have {1<u>0</u>, <u>1</u>, <u>2</u>, 7<u>5</u>, 4<u>5</u>, 2<u>8</u>, 10<u>8</u>}, and then we would go to the next part of the number so for instance <u>7</u>5 and we repeat this process until the digit of the biggest number in the array.

For our case with two stacks, it is natural to do the lexographical analysis/sorting considering base 2. In this way, we just need to pop from stack a and push to b the element if it has 0 in the current bit(we do this analysis until the last 1-bit of the greatest rank, because it will use possibly compare less bits since the greatest rank is generally smaller than the greatest number in the pushswap's common inputs, besides that we can even sort negative numbers without problems(well... technically we have the movements for sorting them at least)). After that one time the bit analysis and poppping the elements with 0's bit and rotating the ones with 1's. We return all the elements that was popped to the stack a, in this way we will have the smallest numbers in the specific bits on the top of stack a in the end. Doing this until the last bit let the stack a sorted.

Talking about the time complexity, we will have to do the process d_2 = log_2(M) times where M is the greatest numbers and d_2 the position of the last bit-1 this number has(i.e, the last digit in base 2, that's why d_2). For seeing that consider M = a_n * 2^n + a_(n - 1) 2^(n - 1) + ... + a_0 * 2^0. For getting the number n, we need first to  divide n, by 2^n. Considering the integer division, we get M / 2^n = a_n. Because a_n = 1 since it is the last bit, we have M / 2^n = 1. So M = 2^n , therefore n = log_2(M). 

Besides that, we push/rotate n elements each time and then we pop from b and push to a, so each time 2n operations. So in our implementation, in average radix sort is O(d_2 * n), of course it can be shown that for any base d_2 \proportional symbol d being d the number of digits in a generic base(just use the log arithmetic). So, we have O(d * n) as expected.

#Instructions

For testing the project you can just use the command `make` for compiling the push_swap. Then you run it by using ./push_swap and giving arguments to it, for instance ./push_swap 5 4 3 2 1. By default it will run the adaptative strategy by default. This strategy considers the disorder in the specific input, it will choose the  



#Resources


