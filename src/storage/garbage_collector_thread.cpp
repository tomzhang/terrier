#include "storage/garbage_collector_thread.h"

namespace terrier::storage {
GarbageCollectorThread::GarbageCollectorThread(const common::ManagedPointer<GarbageCollector> gc,
                                               const std::chrono::milliseconds gc_period)
    : gc_(gc),
      run_gc_(true),
      gc_paused_(false),
      gc_period_(gc_period),
      gc_thread_(std::thread([this] { GCThreadLoop(); })) {}

}  // namespace terrier::storage
