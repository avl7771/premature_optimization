#ifndef MEASURE_UTILIZATION_HPP
#define MEASURE_UTILIZATION_HPP

#include <cstdint>

class MeasureUtilization {
 public:
  // Constructor; starts the measurement.
  MeasureUtilization();

  // Microseconds of user time + system time used by this process since the
  // measurement started.
  uint64_t GetUtilization() const;

 private:
  uint64_t user_time_start_;
  uint64_t system_time_start_;
};

#endif  // MEASURE_UTILIZATION_HPP
