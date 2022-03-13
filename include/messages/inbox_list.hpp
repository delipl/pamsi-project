#pragma once

#include "messages/package.hpp"
namespace pamsi
{
    

    class InboxList {
       public:
       private:
        std::shared_ptr<InboxList> next;
    }
} // namespace pamsi
