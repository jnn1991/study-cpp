#include <iostream>
using std::cout;
using std::endl;

class MutexLock
{
public:
    MutexLock() 
    :_isLocking(false)
    {    
        if(pthread_mutex_init(&_mutex,NULL))
        {
            perror(">> pthread_cond_init");
        }
    }
    ~MutexLock()
    {
        if(pthread_mutex_destroy(&_mutex))
        {
            perror(">> pthread_mutex_destroy");
        }
    }
    //c++11用法，表达禁止复制
    MutexLock (const MutexLock&)=delete ;
    MutexLock & operator=(const MutexLock &)= delete ;
    void lock() 
    {
        if(pthread_mutex_lock(&_mutex))
        {
            perror(">> pthread_mutex_lock");
        }
        _isLocking = true;
    }
    void unlock()
    {
        if(pthread_mutex_unlock(&_mutex))
        {
            perror(">> pthread_mutex_unlock");
        }
        _isLocking = false;
    }

    bool isLocking() const
    {
        return _isLocking;
    }
    pthread_mutex_t * getMutexLockPtr()
    {
        return &_mutex;
    }
#if 0
private://禁止复制 ==》 对象语义
    MutexLock (const MutexLock&);
    MutexLock & operator=(const MutexLock &);
#endif
private:
    pthread_mutex_t _mutex;
    bool _isLocking;

};

class MutexLockGuard
{
public:
    MutexLockGuard(MutexLock & mutex)
    :_mutex(mutex)
    {
        _mutex.lock();
    }

    ~MutexLockGuard()
    {
        _mutex.unlock();
    }

private:
    MutexLock &_mutex;
};

class Condition
{
public:
    Condition(MutexLock & mutex)
    :_mutex(mutex)
    {   
       if( pthread_cond_init(&cond,NULL))
       {
           perror(">> pthread_cond_init");
       }   
    }
    ~Condition(){   
        if(pthread_cond_destroy(&cond))
        {
            perror(">> pthread_cond_destroy");
        }
    }
    void wait()
    {
        if(pthread_cond_wait(&cond,_mutex.getMutexLockPtr()))
        {
            perror(">> pthread_cond_wait");
        }
    }
    void notify()
    {
        if(pthread_cond_signal(&cond))
        {
            perror(">> pthread_cond_signal");
        }
    }
    void notifyall()
    {
        if(pthread_cond_broadcast(&cond))
        {
            perror("pthread_cond_broadcast");
        }
    }

private:
    MutexLock & _mutex;
    pthread_cond_t cond;
};

int main(void)
{
   
    return 0;
}

