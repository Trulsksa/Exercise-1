Exercise 1 - Theory questions
-----------------------------

### Concepts

What is the difference between *concurrency* and *parallelism*?
> *concurrency is when several threads/tasks are executed in an intertwined order, but one at a time, while parallelism is mulitple tasks/threads being executed at once.*

What is the difference between a *race condition* and a *data race*? 
> *Race conditions can happens when the result of a program depends on the timing between threads. A data race is a specific kind of race condition. Where two threads access the same variable at the same time without synchronization.*
 
*Very* roughly - what does a *scheduler* do, and how does it do it?
> *A scheduler decides which thread or process gets to run on the CPU and when. It does this by switching between tasks based on rules like priority.*


### Engineering

Why would we use multiple threads? What kinds of problems do threads solve?
> *We use multiple threads to let a program do several things independently, either truly in parallel (on multiple cores) or by switching quickly between tasks. Threads help solve problems like slow performance and handling many tasks at once, where we want to split a program into separate, independent tasks (threads) that can run at the same time or switch efficiently. And then we use these threads to achieve parallelism or concurrency.*

Some languages support "fibers" (sometimes called "green threads") or "coroutines"? What are they, and why would we rather use them over threads?
> *Fibers are a further division of program flow. A single thread can run multiple fibers handling independent tasks. They achieve blocking-like behavior while remaining non-blocking. Fibers are cooperative, meaning they yield control manually, while threads are usually preemptive, meaning the OS decides when to switch. Fibers are useful in systems with tight memory or CPU constraints, since they use less overhead than threads.*

Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
> *Creating concurrent programs usually makes the programmer's life harder from what i have understood. It introduces complexity like race conditions, deadlocks etc. However, when done right, concurrency can make programs faster, more responsive, and scalable, which makes life easier in the long run. So maybe the answer is both, harder to write, but better results if done well*

What do you think is best - *shared variables* or *message passing*?
> *Message passing, it's safer since there's no shared state and less risk of race conditions or deadlocks. Its also more from what i have understood more portable and scalable, as it can run on different types of machines and networks*


