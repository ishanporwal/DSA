## Exercise 3: Reverse Stack

For solving this, I would first pop everything from the stack into a queue. Then I would dequeue everything from that queue and push everything back to the stack. This ends up reversing the order.

## Exercise 4: Valid Parentheses

I used a stack to store all of the currently open brackets that need to be closed. Then I have a map of the closing brackets to the opening brackets for checking purposes. When I find a closing bracket then I check that it matches the opening bracket at the top of the stack and if it does then pop it. We just need to keep making sure that every closing bracket finds a match and the stack is empty at the end.

## Exercise 5: Copy Stack

For this, we can pop everything from the original stack into a queue. Then we can dequeue from this queue into a temporary stack that's now the reverse of the original. Then we can pop from the stack and enqueue this all back into the queue again. Finally, we can dequeue every element into both the original stack and the temporary stack therefore yielding a stack and its copy.
