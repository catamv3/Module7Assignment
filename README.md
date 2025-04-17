Michael Catalanotti
CSC 343
Module 7 Assignment 
4/15/2025


Q1- Explain why Windows and Linux implement multiple locking mechanisms. Describe the circumstances under which they use spinlocks, mutex locks, semaphores, and condition variables. In each case, explain why the mechanism is needed.

Locking mechanisms exist to grant OS the power to regulate access to it’s resources–in this, OS derive not only computational efficiency but also security measures to protect the integrity of information exchanges within a program. Several locking mechanisms exist, but some locking mechanisms are more appropriate to use when factors like time, program complexity and efficiency needs come into play. 
Spinlocks are more useful in a scenario when time is a resource and threads are not expected to wait for a long time. In multiprocessing systems, spinlocks are beneficial because they continuously check if a lock is available, by not sending the thread to sleep this reduces the overhead of the system, yet threads in action must complete before another can execute. 
 Mutex locks are beneficial when a thread must sleep, and generally used in scenarios where the critical section of a thread is long. These locks avoid race conditions by ensuring only one thread can access OS resources at a time. Mutexes place threads waiting on a mutex place them in a waiting queue, which could allow a system to switch to other threads while the initial thread waits. 
Semaphores are used when you need multiple threads to concurrently access a shared resource. Usually in producer/consumer problems, semaphores are helpful because  multiple threads can send a signal message within the thread pool to access shared resources, unlike mutex locks where only one thread can access a resource. 
A condition variable is an expression that can be used to wait for certain conditions to be met before a thread is woken up. In producer/consumer relationships, his is beneficial as the participants must wait for the condition to be met to interact with the other. In more complex systems, this is beneficial as the condition variable can represent a larger context of a thread and programmers can control resource access based on the condition being met. 


Q2- Describe what changes would be necessary to the producer and consumer processes in Figure 7.1 and Figure 7.2 so that a mutex lock could be used instead of a binary semaphore.
Change the semaphore with a mutex initialization 
Example: pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
Change the wait(mutex) to pthread_mutex_lock(&mutex);
Which would acquire the mutex lock and ensure exclusive access. 
Replace the signal(mutex) with pthread_mutex_unlock(&mutex);
This releases the lock and allows other threads to enter the critical section	

Q3- Describe how deadlock is possible with the dining-philosophers problem.
	Since only one philosopher can hold a chopstick at a time, this creates a mutually exclusive condition. If every philosopher pickled up a chopstick on their right, it means the person to their left took their chopstick. Since no one will release their chopstick until they eat, this causes all philosophers at the table to wait. Additionally, no chopstick can be taken with or without a philosopher eating, this no preemption of resources solidifies that no philosopher will give up their chopstick. 

Q4- Coding assignment. Submit your GitHub link as your answer.
