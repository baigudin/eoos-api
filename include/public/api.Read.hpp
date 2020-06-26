/**
 * Stream read interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_READ_HPP_
#define API_READ_HPP_

#include "api.Object.hpp"

namespace eoos
{
    namespace api
    {
        class Read : public Object
        {

        public:

            /**
             * Destructor.
             */
            virtual ~Read(){}
        
            /**
             * Reads data from a stream.
             *
             * @param data - Pointer to data.
             * @param size - Size of data in Bytes.
             * @return number of read bytes.
             */
            virtual size_t read(void* data, size_t size) const = 0;
            
        };

    }
}
#endif // API_READ_HPP_