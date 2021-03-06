/**
 * @file      Program.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef PROGRAM_HPP_
#define PROGRAM_HPP_

#include "Types.hpp"
#include "api.List.hpp"

namespace eoos
{

/**
 * @class Program
 * @brief Entry point to an operating system main program.
 */
class Program
{

public:

    /**
     * @brief Starts executing an operating system main program.
     *
     * @param args Arguments passed to the program.
     * @return Zero, or error code if an error has been occurred.
     */
    static int32_t start(const api::List<char_t*>* args);

};

} // namespace eoos
#endif // PROGRAM_HPP_
