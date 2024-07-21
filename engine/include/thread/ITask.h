#pragma once

#include <chrono>

#include <thread/IThreadable.h>

namespace codetorio {

class ITask : public IThreadable{
public:
    [[nodiscard]] virtual std::chrono::milliseconds getPeriod() const = 0;
};

}// namespace codetorio
