#pragma once

#include <thread/IThreadable.h>

namespace codetorio {

class Engine : public IThreadable {
public:
    void run() override;

public:

};

}// namespace codetorio
