/**
 * @brief System class of the operating system.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "api.System.hpp"

namespace eoos
{
    
class System
{

public:

    /**
     * @brief Returns the operating system syscall interface.
     *
     * @return the operating system syscall interface.
     */
    static api::System& call();

};

} // namespace eoos
#endif // SYSTEM_HPP_
