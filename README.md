# logfile
This is a stupid idea for C++ developers, log always collected by other domain, and you didn't know how they works.
sometimes log runs wrong like log lost too much beyound your expected. Maybe this is occasionally, and you don't want to deep why the log is lost, so you will want save the log to a new file under your control without the log domain.
This demon will help you.

I create a file and open it at first, make it as a unique instance for other codes to get the same interface to write log into it. it didn't consider the thread and others, it's simple and easy enough to read and use for a workaround. and this is what I want, and I think you will like it too.
