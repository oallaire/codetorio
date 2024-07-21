#pragma once

namespace codetorio {

class IThreadable {
public:
    virtual ~IThreadable() = default;

    virtual void run() = 0;
};

} // namespace codetorio
