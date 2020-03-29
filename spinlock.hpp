#include <atomic>


class SpinLock {
 public:
  void Lock() {
    while (locked_.exchange(true)) {
      while (locked_.load()) {
        SpinLockPause();        
      }
    }
  }

  bool TryLock() {
    return locked_.exchange(true) == false;
  }

  void Unlock() {
    locked_.store(false);
  }

 private:
  static inline void SpinLockPause() {
  #if defined(__GNUC__) && (defined(_i386_) || defined(_x86_64_))
    __asm __volatile("pause");
  #endif
  }

 private:
  volatile std::atomic<bool> locked_{false};
};
