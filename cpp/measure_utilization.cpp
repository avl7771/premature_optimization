#include "measure_utilization.hpp"

#include <sys/resource.h>
#include <sys/time.h>

MeasureUtilization::MeasureUtilization()
    : user_time_start_(0),
      system_time_start_(0) {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) != 0)
        return;

    user_time_start_ = usage.ru_utime.tv_sec * 1000000 + usage.ru_utime.tv_usec;
    system_time_start_ =
        usage.ru_stime.tv_sec * 1000000 + usage.ru_stime.tv_usec;
}

uint64_t MeasureUtilization::GetUtilization() const {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) != 0)
        return 0;

    uint64_t user_time = usage.ru_utime.tv_sec * 1000000 +
        usage.ru_utime.tv_usec;
    
    return (user_time - user_time_start_);
}
