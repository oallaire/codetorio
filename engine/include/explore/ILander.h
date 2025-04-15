#pragma once

#include "factory/IFactory.h"
#include "types/types.h"
#include "vault/IVault.h"

namespace codetorio {

class ILander : public IFactory, public IVault {
public:

};

} // codetorio
