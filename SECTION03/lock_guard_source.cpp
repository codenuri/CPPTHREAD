template <class _Mutex> class lock_guard 
{ 
public:
    using mutex_type = _Mutex;

    explicit lock_guard(_Mutex& _Mtx)      : _MyMutex(_Mtx) { _MyMutex.lock(); }
    lock_guard(_Mutex& _Mtx, adopt_lock_t) : _MyMutex(_Mtx) {} 
    
    ~lock_guard() noexcept {_MyMutex.unlock(); }

    lock_guard(const lock_guard&) = delete;
    lock_guard& operator=(const lock_guard&) = delete;
private:
    _Mutex& _MyMutex;
};

struct adopt_lock_t 
{ 
    explicit adopt_lock_t() = default;
};
constexpr adopt_lock_t adopt_lock {};