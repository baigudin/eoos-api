/**
 * @file      api.SysSemaphore.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2015-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef API_SYS_SEMAPHORE_HPP_
#define API_SYS_SEMAPHORE_HPP_

#include "api.Semaphore.hpp"
#include "api.SysResource.hpp"

namespace eoos
{
namespace api
{

/**
 * @class SysSemaphore
 * @brief System semaphore interface.
 */
class SysSemaphore : public Semaphore, public SysResource
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~SysSemaphore() = 0;

};
        
inline SysSemaphore::~SysSemaphore() {}

} // namespace api
} // namespace eoos
#endif // API_SEMAPHORE_HPP_
