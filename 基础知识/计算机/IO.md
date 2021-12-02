## select与pselect与poll
select(关心的描述符， read/write/except指向描述符的指针， 超时时间)
pselect(关心的描述符， read/write/except指向描述符的指针， 超时时间，屏蔽信号量)
poll(描述符集数组，数组长度，超时值)
- pselect可以使用信号屏蔽字：一个进程是否屏蔽某个信号是由该进程的信号屏蔽字决定的。信号屏蔽字是一个信号集，其包含的信号都会被阻塞而不能递送给这个进程。而sigprocmask就是用来修改进程的信号屏蔽字的，因此它可以屏蔽某个信号会对某个已经屏蔽的信号解除屏蔽。
- pselect使用timeval来代表时间
- pselect的超时值为const