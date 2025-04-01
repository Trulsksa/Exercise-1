why the result is not always zero
The final result is not always zero because the program contains a race condition.
Both the incrementing and decrementing threads (or goroutines) are modifying the shared variable i at the same time without synchronization. Since increment (i++) and decrement (i--) are not atomic operations, they can interfere with each other during execution.
For example, two threads might read the same value of i at the same time, both modify it, and write back the same result, effectively losing one of the operations. This leads to an unpredictable final value of i.
To fix this and get consistent results (like exactly zero), we would need to synchronize access to i, for example using mutexes in C or sync primitives like sync.Mutex in Go.