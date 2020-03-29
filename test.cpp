#include "gtest/gtest.h"
#include "spinlock.hpp"

TEST(UnitTest, LockUnlock) {
  SpinLock spinlock;
  spinlock.Lock();
  spinlock.Unlock();
}

TEST(UnitTest, SequentialLockUnlock) {
  SpinLock spinlock;
  spinlock.Lock();
  spinlock.Unlock();
  spinlock.Lock();
  spinlock.Unlock();
}

TEST(UnitTest, TryLock) {
  SpinLock spinlock;
  ASSERT_TRUE(spinlock.TryLock());
  ASSERT_FALSE(spinlock.TryLock());
  spinlock.Unlock();
  ASSERT_TRUE(spinlock.TryLock());
  spinlock.Unlock();
  spinlock.Lock();
  ASSERT_FALSE(spinlock.TryLock());
}

int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
